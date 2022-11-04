#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int test;
int n, x, m;

int in(int a, int b, int c) {
	return a >= b && a <= c;
}

void work() {
	scanf("%d %d %d", &n, &x, &m);
	int l = x, r = x;
	for (int i = 0; i < m; i++) {
		int ll, rr;
		scanf("%d %d", &ll, &rr);
		if (in(ll, l, r) || in(rr, l, r) || in(l, ll, rr) || in(r, ll, rr)) {
			l = min(l, ll);
			r = max(r, rr);
		}
	}
	printf("%d\n", r - l + 1);
}

int main() {
    scanf("%d", &test);
    while (test--) {
    	work();
    }
	return 0;
}