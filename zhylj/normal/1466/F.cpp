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
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int fa[kN], siz[kN], p_siz[kN], flag[kN];

int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
bool Merge(int x, int y) {
	int f_x = Find(x), f_y = Find(y);
	if(f_x == f_y) {
		if(!flag[f_x] && x == y) {
			return flag[f_x] = true;
		}
		return false;
	}
	if(flag[f_x] && flag[f_y]) return false;
	fa[f_x] = f_y;
	p_siz[f_y] += p_siz[f_x];
	flag[f_y] = (flag[f_x] || flag[f_y]);
	return true;
}

int n, m, u[kN], v[kN]; std::vector <int> ans;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m); std::swap(n, m);
		for(int i = 1; i <= n; ++i) fa[i] = i, p_siz[i] = 1;
		for(int i = 1; i <= m; ++i) {
			int k; rd(k);
			if(k == 1) { rd(u[i]); v[i] = u[i]; }
			else rd(u[i], v[i]);
			if(Merge(u[i], v[i])) ans.push_back(i);
		}
		ll tot = QPow(2, ans.size());
		std::sort(ans.begin(), ans.end());
		printf("%lld %d\n", tot, ans.size());
		for(auto i : ans) printf("%d ", i);
		printf("\n");
	} return 0;
}