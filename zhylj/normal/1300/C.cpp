#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 1e5 + 5;

ll a[kMaxN]; int s[40];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	for(int i = 0; i <= 30; ++i)
		for(int j = 1; j <= n; ++j)
			s[i] += ((a[j] >> i) & 1);
	ll x, maxans = 0;
	for(int i = 1; i <= n; ++i) {
		ll tmp = 0;
		for(int j = 0; j <= 30; ++j)
			if(((a[i] >> j) & 1) && s[j] == 1) tmp += (1LL << j);
		if(tmp >= maxans) maxans = tmp, x = i;
	}
	printf("%lld ", a[x]);
	for(int i = 1; i <= n; ++i)
		if(i != x) printf("%lld ", a[i]);
	return 0;
}