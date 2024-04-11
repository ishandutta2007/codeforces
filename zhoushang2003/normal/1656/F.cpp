#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
inline void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
inline void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

int T, n, a[N];

ll calc(int t) {
	ll ret = -1ll * (n - 1) * t * t;
	if (a[1] + t >= 0) {
		for (int i = 2; i <= n; i++)
			ret += 1ll * (a[1] + t) * (a[i] + t);
		return ret;
	}
	if (a[n] + t <= 0) {
		for (int i = 1; i < n; i++)
			ret += 1ll * (a[n] + t) * (a[i] + t);
		return ret;
	}
	int p = 1;
	while (p + 1 <= n && a[p + 1] + t < 0) p++;
	for (int i = p + 1; i <= n; i++)
		ret += 1ll * (a[1] + t) * (a[i] + t);
	for (int i = 2; i <= p; i++)
		ret += 1ll * (a[n] + t) * (a[i] + t);
	return ret;
}

int main() {
	for (read(T); T; T--) {
		read(n); ll s = 0;
		lep (i, 1, n) read(a[i]), s += a[i];
		sort (a + 1, a + n + 1);
		if (1ll * a[1] * (n - 2) + s > 0 || 1ll * a[n] * (n - 2) + s < 0) {
			puts("INF");
			continue;
		}
		int l = -1e6, r = 1e6;
		while (r - l >= 5) {
			int mid = (l + r) >> 1;
			if (calc(mid) > calc(mid + 1)) r = mid;
			else l = mid;
		}
		ll ans = -infll;
		for (int i = l; i <= r; i++)
			ans = max(ans, calc(i));
		printf("%lld\n", ans);
	}
	return 0;
}