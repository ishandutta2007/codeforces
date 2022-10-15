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

int n, a[kN], b[kN], fa[kN], mn[kN], mx[kN];
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) {
	int f_x = Find(x), f_y = Find(y);
	if(f_x == f_y) return;
	fa[f_x] = f_y;
	mn[f_y] = std::min(mn[f_x], mn[f_y]);
	mx[f_y] = std::max(mx[f_x], mx[f_y]);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= n; ++i) fa[i] = mx[i] = mn[i] = i, b[i] = 0;
		for(int i = 1; i < n; ++i) {
			if(a[i] != a[i + 1]) Merge(i, i + 1);
		}
		bool flag = true;
		for(int i = 1; i <= n; ++i) ++b[a[i]];
		for(int i = 1; i <= n; ++i) {
			if(b[i] > (n + 1) / 2) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			printf("-1\n");
			continue;
		}
		for(int i = 1; i <= n; ++i) b[i] = 0;
		flag = true;
		int cnt = 0, fx = 0;
		for(int i = 1; i <= n; ++i) {
			if(fa[i] == i) {
				++cnt;
				++b[a[mx[i]]];
				++b[a[mn[i]]];
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans = std::max(ans, cnt - 1 + std::max(0, b[i] - (cnt + 1)));
		}
		printf("%d\n", ans);
	} return 0;
}