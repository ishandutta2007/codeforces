#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	int n;
    	scanf("%d", &n);
    	if (n <= 3) {
    		printf("-1\n");
    	} else {
    		if (n == 6) {
    			printf("5 3 6 2 4 1\n");
    		} else if (n == 7) {
    			printf("5 1 3 6 2 4 7\n");
    		} else if (n == 11) {
    			printf("5 1 3 6 2 4 7 10 8 11 9\n");
    		} else {
    			int base = 0;
    			while (base != n) {
    				if ((n - base) % 5 > 0) {
    					printf("%d %d %d %d ", base + 2, base + 4, base + 1, base + 3);
					    base += 4;
    				} else {
					    printf("%d %d %d %d %d ", base + 2, base + 4, base + 1, base + 3, base + 5);
					    base += 5;
    				}
    			}
    			printf("\n");
    		}
    	}
    }
	return 0;
}