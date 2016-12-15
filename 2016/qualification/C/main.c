// https://code.google.com/codejam/contest/6254486/dashboard#s=p2
// Google Code Jam 2016 - Qualification Round - C: Coin Jam

#include <stdio.h>

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

int main() {
	printf("%d: %d\n", 7, nontrival_factor(7));
	printf("%d: %d\n", 10, nontrival_factor(10));
}