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
const int kN = 1e6 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, k, m[kN], c[kN], mt[kN], cnt = 0;
std::vector <int> tc[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) rd(m[i]), ++mt[m[i]];
		for(int i = 1; i <= k; ++i) rd(c[i]);
		int lst = 0;
		for(int i = k; i; --i) {
			if(c[i] != c[i + 1])
				lst = 1;
			for(int j = lst; mt[i]; ++j) {
				while(mt[i] && tc[j].size() < c[i]) --mt[i], tc[j].push_back(i);
				cnt = std::max(j, cnt);
				lst = j;
			}
		}
		printf("%d\n", cnt);
		for(int i = 1; i <= cnt; ++i) {
			printf("%d ", (int)tc[i].size());
			for(auto j : tc[i]) printf("%d ", j);
			printf("\n");
		}
	} return 0;
}