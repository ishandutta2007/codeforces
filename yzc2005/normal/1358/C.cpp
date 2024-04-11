#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, x[2], y[2];
long long n, m;

int main() {
	for(scanf("%d", &t); t; --t) {
		for(int i = 0; i < 2; ++i) scanf("%d%d", &x[i], &y[i]);
		m = x[1] - x[0], n = y[1] - y[0];
		printf("%lld\n", (2 * m + n + 1) * n / 2 - n * (n + 1) / 2 + 1);
	}
	return 0;
}