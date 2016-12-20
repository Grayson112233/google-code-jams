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

int get_value(bool *coin, int len, int base) {
    int value = 0;
    for(int i = 0; i < len; i++) {
        if(coin[i]) {
            value += (int)pow(base, i);
        }
    }
    return value;
}

bool validate_coin(bool *coin, int len) {
    if(!coin[0] || !coin[len-1]) {
        return false;
    }
    // For each base
    for(int base = 2; base <= 10; base++) {
        int value = get_value(coin, len, base);
        if(nontrival_factor(value) == -1) {
            //printf("Fails, %d is prime (base %d)\n", value, base);
            return false;
        }
    }
    return true;
}

// Assigns int to coin array (ignoring index 0 and len-1)
void int_to_coin(int n, bool *coin, int len) {
    int chunk; // Variable to store pow() calculation to prevent recalculation
    // For each position in the binary number
    for(int i = len-3; i >= 0; i--) {
        chunk = (int)pow(2, i);
        if(n >= chunk) {
            coin[len-2-i] = true;
            n -= chunk;
        } else {
            coin[len-2-i] = false;
        }
    }
}

void print_coin(bool *coin, int len) {
    for(int i = 0; i < len; i++) {
        printf("%c", coin[i] ? '1' : '0');
    }
}

void print_proof(bool *coin, int len) {
    // For each base
    for(int base = 2; base <= 10; base++) {
        int value = get_value(coin, len, base);
        printf(" %d", nontrival_factor(value));
    }
}

int main() {

    int len, n;
    FILE *fp = fopen("small.in", "r");
    fscanf(fp, "%*d"); // Always one case, ignore
    fscanf(fp, "%d %d", &len, &n);

    printf("len is %d\n", len);
    bool coin[len];
    
    // Valid coins have 1's at index 0 and len-1 always
    coin[0] = true;
    coin[len-1] = true;

    printf("staring coin is: ");
    print_coin(coin, len);
    printf("\n");

    int i = 0;
    int num_found = 0;
    while(num_found < n) {
        int_to_coin(i, coin, len);
        //print_coin(coin, len);
        if(validate_coin(coin, len)) {
            print_coin(coin, len);
            print_proof(coin, len);
            printf("\n");
            num_found++;
        }
        i++;
    }
}