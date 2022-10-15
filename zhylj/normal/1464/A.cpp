#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int fa[kN], siz[kN], siz_s[kN];
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) {
	int f_x = Find(x), f_y = Find(y);
	if(f_x == f_y) { ++siz[f_x]; return; }
	fa[f_x] = f_y; siz[f_y] += siz[f_x] + 1;
	siz_s[f_y] += siz_s[f_x];
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		int cnt = 0;
		int n, m; rd(n, m);
		for(int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 0, siz_s[i] = 1;
		for(int i = 1; i <= m; ++i) {
			int x, y; rd(x, y);
			if(x == y) continue;
			Merge(x, y);
		}
		for(int i = 1; i <= n; ++i)
			if(fa[i] == i) {
				cnt += (siz[i] == siz_s[i] ? siz[i] + 1 : siz[i]);
			}
		printf("%d\n", cnt);
	} return 0;
}