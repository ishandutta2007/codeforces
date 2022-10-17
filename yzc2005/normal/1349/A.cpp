#include <bits/stdc++.h>
using namespace std;

const int N = 200005, inf = 0x3f3f3f3f;
int n, x, m1[N], m2[N], cnt[N];

inline void upd(int x, int y) {
	if(y < m1[x]) m2[x] = m1[x], m1[x] = y;
	else if(y < m2[x]) m2[x] = y;
}

int main() {
	memset(m1, 0x3f, sizeof(m1));
	memset(m2, 0x3f, sizeof(m2));
	scanf("%d", &n);
	for(int t = 1; t <= n; ++t) {
		scanf("%d", &x);
		for(int i = 2, mx = sqrt(x); i <= mx; ++i) {
			if(x % i == 0) {
				++cnt[i];
				int y = 0;
				while(x % i == 0) ++y, x /= i;
				upd(i, y);
			}
		}
		if(x > 1) ++cnt[x], upd(x, 1);
	} 
	long long ans = 1;
	for(int i = 1; i <= 200000; ++i) { 
		if(cnt[i] == n) while(m2[i]--) ans *= i;
		else if(cnt[i] == n - 1) while(m1[i]--) ans *= i;
	} 
	printf("%lld", ans);
}