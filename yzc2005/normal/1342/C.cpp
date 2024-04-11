#include <bits/stdc++.h>
using namespace std;

int t, a, b, q, lcm, sum[66666];
long long l, r;

long long calc(long long n) {
	return 1ll * sum[lcm] * (n / lcm) + sum[n % lcm];
}
int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d%d", &a, &b, &q);
		lcm = a * b / __gcd(a, b);
		if(a > b) swap(a, b);
		for(int i = 1; i <= lcm; ++i) sum[i] = sum[i - 1] + ((i % a % b) != (i % b % a));
		for(int t = 1; t <= q; ++t) {
			scanf("%lld%lld", &l, &r);
			printf("%lld%c", calc(r) - calc(l - 1), t < q ? ' ' : '\n');
		}
	}
	return 0;
}