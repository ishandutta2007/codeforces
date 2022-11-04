#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void work() {
	int n;
	scanf("%d", &n);
	if (n < 31) {
		printf("NO\n");
	} else {
		printf("YES\n");
		int now = n - 30;
		if (now == 6) {
			printf("5 6 10 15\n");
		} else if (now == 10) {
			printf("6 10 15 9\n");
		} else if (now == 14) {
			printf("6 7 10 21\n");
		} else {
			printf("%d 6 10 14\n", now);
		}
	}
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	work();
    }
	return 0;
}