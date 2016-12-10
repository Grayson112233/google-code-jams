// https://code.google.com/codejam/contest/6254486/dashboard
// Google Code Jam 2016 - Qualification Round - A: Counting Sheep

#include <stdio.h>
#include <stdbool.h>

bool seen_all(bool *seen) {
    for (int i = 0; i < 10; i++) {
        if(!seen[i]) {
            return false;
        }
    }
    return true;
}

long int count_sheep(int n) {
    // 0 can't produce any digits but 0
    if(n == 0) {
        return -1;
    }
    bool seen[10] = {0};
    int i = 1;
    long int to_ret;
    while(!seen_all(seen)) {
        long int result = i * n;
        to_ret = result;
        // Check the digits of the result
        while(result > 0) {
            seen[result % 10] = true;
            result /= 10;
        }
        i++;
    }
    return to_ret;
}

int main() {

    FILE *fp = fopen("large.in", "r");
    int cases;
    fscanf(fp, "%d", &cases);
    int i = 1;
    int input;
    while(i <= cases) {
        fscanf(fp, "%d", &input);
        if(input == 0) {
            printf("Case #%d: INSOMNIA\n", i);
        } else {
            printf("Case #%d: %ld\n", i, count_sheep(input));
        }
        i++;
    }


    return 0;
}