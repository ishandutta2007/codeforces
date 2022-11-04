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
    	int n, k;
    	scanf("%d %d", &n, &k);
	    if (n >= k && (n - k) % 2 == 0) {
		    printf("YES\n");
		    for (int i = 1; i < k; i++) {
			    printf("1 ");
		    }
		    printf("%d\n", 1 + (n - k));
	    } else {
		    if (n % 2 == 0 && n >= 2 * k) {
		    	printf("YES\n");
			    for (int i = 1; i < k; i++) {
				    printf("2 ");
			    }
			    printf("%d\n", 2 + (n - k * 2));
		    } else {
		    	printf("NO\n");
		    }
	    }
    }
	return 0;
}