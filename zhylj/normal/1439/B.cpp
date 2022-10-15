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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 2e7 + 3, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, dg[kN]; bool del[kN]; ll k;
std::unordered_set <ll> s;
std::vector <int> E[kN], ans;
std::priority_queue <pii, std::vector <pii>, std::greater <pii> > pq;
void Add(int u, int v) {
	E[u].push_back(v); E[v].push_back(u);
	++dg[u]; ++dg[v];
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		//srand(time(0));
		ans.clear();
		rd(n, m, k);
		while(!pq.empty()) pq.pop();
		s.clear();
		for(int i = 1; i <= n; ++i) dg[i] = 0;
		for(int i = 1; i <= n; ++i) del[i] = false;
		for(int i = 1; i <= n; ++i) E[i].clear();
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
			if(u > v) std::swap(u, v);
			s.insert((u - 1) * (ll)n + v);
		}
		if((k - 1) * (k - 1) > 2 * m) {
			printf("-1\n");
			continue;
		}
		for(int i = 1; i <= n; ++i) {
			pq.push(mkp(dg[i], i));
		}
		int flag = -1;
		while(!pq.empty()) {
			pii cur = pq.top(); pq.pop();
			int d = cur.fi, u = cur.se;
			//printf("dg = %d\n", dg[u]);
			if(del[u]) continue;
			//printf("%d\n", u);
			if(d < k - 1) {
				del[u] = true;
				for(auto v : E[u]) if(!del[v]) {
					--dg[v]; pq.push(mkp(dg[v], v));
				}
			} else if(d == k - 1) {
				ans.clear();
				del[u] = true;
				bool cli = true;
				ans.push_back(u);
				for(auto v : E[u]) if(!del[v]) {
					ans.push_back(v);
				}
				for(auto v : E[u]) if(!del[v]) {
					for(auto w : E[u]) if(!del[w] && v < w && !s.count((v - 1) * (ll)n + w)) {
						cli = false;
						break;
					}
					if(!cli) break;
				}
				if(cli) {
					flag = 2;
					break;
				} else {
					for(auto v : E[u]) if(!del[v]) {
						--dg[v]; pq.push(mkp(dg[v], v));
					}
				}
			} else if(d > k - 1) {
				//printf("d = %d\n", d);
				flag = 1;
				break;
			}
		}
		printf("%d ", flag);
		if(flag == 2) {
			printf("\n");
			for(auto v : ans) printf("%d ", v);
		} else if(flag == 1) {
			int cnt = 0;
			for(int i = 1; i <= n; ++i) cnt += !del[i];
			printf("%d\n", cnt);
			for(int i = 1; i <= n; ++i) if(!del[i]) {
				printf("%d ", i);
			}
		}
		printf("\n");
	} return 0;
}