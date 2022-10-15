#include <bits/stdc++.h>

typedef long long ll;

const int kN = 2e5 + 5;
const ll kMod = 998244353;

ll ans[kN], tp[kN]; int n;

int main() {
	scanf("%d", &n);
	tp[0] = 1;
	for(int i = 1; i <= n; ++i) tp[i] = tp[i - 1] * 10 % kMod;
	for(int i = 1; i < n; ++i)
		printf("%lld ", ((n - i - 1) * tp[n - i - 1] * 81 + tp[n - i] * 2 * 9) % kMod);
	printf("10\n");
	return 0;
}