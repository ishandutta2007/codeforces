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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, tot, w[kN], s[kN], ord[kN], x[kN], y[kN], cnt = 0; V <int> fd[kN];
bool vis[kN], done[kN]; std::queue <int> que;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(w[i]);
		for(int i = 1; i <= m; ++i) {
			rd(x[i], y[i]); ++s[x[i]]; ++s[y[i]];
			fd[x[i]].push_back(i); fd[y[i]].push_back(i);
		}
		tot = n;
		for(int i = 1; i <= n; ++i)
			if(w[i] >= s[i]) vis[i] = true, que.push(i), --tot;
		while(!que.empty()) {
			int cur = que.front(); que.pop();
			for(auto i : fd[cur])
				if(!done[i]) {
					done[i] = true;
					ord[++cnt] = i;
					int tar = x[i] ^ y[i] ^ cur;
					--s[tar];
					if(!vis[tar] && w[tar] >= s[tar]) {
						vis[tar] = true; que.push(tar); --tot;
					}
				}
		}
		if(tot) printf("DEAD\n");
		else {
			printf("ALIVE\n");
			for(int i = cnt; i; --i)
				printf("%d ", ord[i]);
		}
	} return 0;
}