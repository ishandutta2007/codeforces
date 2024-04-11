#include <bits/stdc++.h>
using namespace std;

int n, m;

inline void print(int x) {
	for(int i = 1; i <= m; ++i) {
		printf("%d %d\n", x, i);
		printf("%d %d\n", n - x + 1, m + 1 - i);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n >> 1; ++i) print(i);
	if(n & 1) {
		int x = (n + 1) / 2, l = 1, r = m;
		for(int i = 1; i <= m; ++i) printf("%d %d\n", x, i & 1 ? l++ : r--);
	}
	return 0;
}