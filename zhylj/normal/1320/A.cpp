#include <bits/stdc++.h>

typedef long long ll;

const int kN = 8e5 + 25;
const int kMid = 4e5 + 5;

int n, b[kN], bud[kN]; ll f[kN], ans = 0;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", b + i);
	for(int i = 1; i <= n; ++i) {
		int tmp = i - b[i] + kMid;
		if(!bud[tmp]) { f[i] = b[i]; bud[tmp] = i; continue; }
		f[i] = f[bud[tmp]] + b[i];
		bud[tmp] = i;
	}
	for(int i = 1; i <= n; ++i) ans = std::max(ans, f[i]);
	printf("%lld ", ans);
	return 0;
}