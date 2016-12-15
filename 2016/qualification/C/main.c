// https://code.google.com/codejam/contest/6254486/dashboard#s=p2
// Google Code Jam 2016 - Qualification Round - C: Coin Jam

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Returns lowest nontrivial factor of x.
// If no such factor exists, returns -1
int nontrival_factor(int x) {
    if(x <= 2) {
        return -1;
    }
    for(int i = 2; i < x; i++) {
        if(x % i == 0) {
            return i;
        }
    }
    return -1;
}

bool validate_coin(int coin) {
    for(int i = 2; i <= 10; i++) {
        int temp = coin;
        int value = 0;
        int j = 0;
        while(temp != 0) {
            if(temp % 10 == 1) {
                value += (int)pow(i, j);
            }
            temp /= 10;
            j++;
        }
        if(nontrival_factor(value) == -1) {
            printf("Fails, %d is prime (base %d)\n", value, i);
            return false;
        }
    }
    return true;
}

int main() {
    printf("%d: %s\n", 100101, validate_coin(100101) ? "true" : "false");
}