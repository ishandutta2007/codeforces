#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void work() {
	int n;
	scanf("%d", &n);
	printf("%d\n", (n + 1) / 2);
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	work();
    }
	return 0;
}