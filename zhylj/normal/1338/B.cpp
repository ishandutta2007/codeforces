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
typedef std::pair<int, int> pii;
const int kN = 1e5 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

std::vector <int> E[kN];
int fa[kN], d[kN], cnt[2], hf[kN], mx = 0;
void Dfs(int x) {
	bool flag = true;
	for(auto v : E[x]) if(v != fa[x]) {
		fa[v] = x; d[v] = (d[x] + 1) % 2;
		Dfs(v);
		flag = false;
	}
	if(flag) {
		if(!hf[fa[x]]) ++mx;
		hf[fa[x]] = 1;
		++cnt[d[x]];
	} else ++mx;
}

int main() { int T = 1; //rd(T);
	while(T--) {
		int n; rd(n);
		for(int i = 1; i < n; ++i) {
			int a, b; rd(a, b);
			E[a].push_back(b); E[b].push_back(a);
		}
		int rt;
		for(int i = 1; i <= n; ++i) 
			if(E[i].size() != 1) { rt = i; break; }
		Dfs(rt);
		int mi = 1;
		if(cnt[1] && cnt[0]) mi = 3;
		printf("%d %d\n", mi, mx - 1);
	} return 0;
}