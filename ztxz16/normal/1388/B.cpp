#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void work() {
	int n;
	scanf("%d", &n);
	int s8 = (n - 1) / 4 + 1;
	for (int i = 0; i < n; i++) {
		if (n - i <= s8) {
			printf("8");
		} else {
			printf("9");
		}
	}
	printf("\n");
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	work();
    }
	return 0;
}