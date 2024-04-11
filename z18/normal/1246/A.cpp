#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= 30; i++) {
		if (__builtin_popcount(n - i * m) <= i && n - i * m >= i) {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}