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
    	int a0, a1, a2;
    	scanf("%d %d %d", &a0, &a1, &a2);
    	if (a1 == 0) {
    		if (a0 > 0) {
    			for (int i = 0; i <= a0; i++) {
    				printf("0");
    			}
    		} else {
    			for (int i = 0; i <= a2; i++) {
    				printf("1");
    			}
    		}
    		printf("\n");
    	} else {
		    for (int i = 0; i <= a0; i++) {
			    printf("0");
		    }
		    for (int i = 0; i <= a2; i++) {
			    printf("1");
		    }
		    for (int j = 0; j < a1 - 1; j++) {
			    printf("%d", j % 2);
		    }
		    printf("\n");
	    }
    }
	return 0;
}