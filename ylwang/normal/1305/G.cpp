#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout);
#define file(s) Fin(s".in"), Fout(s".out")
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar());
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x;
}
const int MAXN = (1 << 18 | 1) + 5, mx = (1 << 18);
int a[MAXN], n;
struct DSU {
	static const int N = MAXN;
	int f[MAXN], siz[MAXN];
	DSU() {For(i, 0, N - 1) f[i] = i, siz[i] = -1;}
	inline int find(int x) {
		while(x != f[x]) x = f[x] = f[f[x]];
		return f[x];
	}
	inline int merge(int x, int y) {
		if((x = find(x)) == (y = find(y))) return 0; if(siz[x] < siz[y]) swap(x, y);
		int ans = (siz[x] == -1 ? a[x] : 1) + (siz[y] == -1 ? a[y] : 1) - 1;
		if(siz[x] == -1) siz[x] = 1; if(siz[y] == -1) siz[y] = 1;
		f[y] = x, siz[x] += siz[y]; return ans;
	}
}d;
signed main() {
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	n = read(); int m = 0; long long ans = 0;
	For(i, 0, n - 1) {
		int x = read();
		a[x]++; ckmax(m, x), ans -= x;
	}
	n = m + 1; a[0]++;
	
	for(int i = mx - 1; i >= 0; i--) {
		for(int j = i; j; j = (j - 1) & i) {
//			if((i ^ j) > j) break;
			if(a[(i ^ j)] && a[j]) {
				ans += 1ll * i * d.merge((i ^ j), j);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}