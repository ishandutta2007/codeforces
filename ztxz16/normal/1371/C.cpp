#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void work() {
	long long a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	if (a + b < c + d) {
		printf("No\n");
		return;
	}
	if (min(a, b) < d) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
	return;
}
int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	work();
    }
	return 0;
}