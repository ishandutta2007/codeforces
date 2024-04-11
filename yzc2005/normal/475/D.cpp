#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rint register int
#define fu(i, a, b) for(rint i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rint i = a, I = (b) - 1; i > I; --i)
#define finish(x) return x, 0;

const int N = 1e5 + 5, K = 20;
int n, q, st[N][K], Log[N];
map<int, ll> ans;

inline void prework() {
	fu(i, 2, n) Log[i] = Log[i >> 1] + 1;
	fu(i, 1, n) scanf("%d", &st[i][0]);
	fu(k, 1, Log[n]) 
		fu(i, 1, n - (1 << k) + 1)
			st[i][k] = __gcd(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]); 
}

inline int query(int l, int r) {
	int k = Log[r - l + 1];
	return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

inline int find(int g, int p, int l) {
	int r = n, ans;
	while(l <= r) {
		int mid = l + r >> 1;
		if(query(p, mid) == g) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans + 1;
}

int main() {
	scanf("%d", &n); prework();
	fu(i, 1, n) {
		int pos = i;
		while(pos <= n) { 
			int lst = pos, g = query(i, pos);
			pos = find(g, i, pos);
			ans[g] += pos - lst;
		}
	}
	scanf("%d", &q); int a;
	while(q--) {
		scanf("%d", &a);
		printf("%lld\n", ans[a]);
	}
	return 0;
}