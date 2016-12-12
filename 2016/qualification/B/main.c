// https://code.google.com/codejam/contest/6254486/dashboard#s=p1
// Google Code Jam 2016 - Qualification Round - B: Revenge of the Pancakes

#include <stdio.h>
#include <stdbool.h>

int get_num_flips(bool *stack, int size) {
    // Find groups of blanks
    // If the group is on top of the stack, add 1
    // If the group is below any happy pancakes, add 2
    int flips = 0;
    bool happy_seen = false;
    for(int i = 0; i < size; i++) {
        if(stack[i]) {
            happy_seen = true;
        } else {
            while(i+1 < size && !stack[i+1]) {
                // Skip the rest of the pancakes in this blank group
                i++;
            }
            flips += happy_seen ? 2 : 1;
        }
    }
    return flips;
}

int main() {

    // Stacks are limited to 100
    bool stack[100];

    FILE *fp = fopen("large.in", "r");
    int cases;
    fscanf(fp, "%d", &cases);
    fgetc(fp);
    int i = 1;
    while(i <= cases) {
        int j = 0;
        char pancake;
        while((pancake = fgetc(fp)) != '\n' && pancake != EOF) {
            stack[j] = pancake == '+' ? true : false;
            j++;
        }
        printf("Case #%d: %d\n", i, get_num_flips(stack, j));
        i++;
    }

}