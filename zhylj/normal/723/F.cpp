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

int n, m, ds, dt, s, t, cs, ct, cb, fa[kN]; V <pii> E, spt;
bool ls[kN], lt[kN];
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) { fa[Find(y)] = Find(x); }
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) fa[i] = i;
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			E.push_back(mkp(u, v));
		}
		rd(s, t, ds, dt);
		for(auto i : E) {
			int u = i.fi, v = i.se;
			if(u != s && u != t && v != s && v != t && Find(u) != Find(v)) {
				spt.push_back(i); Merge(u, v);
			}
		}
		for(auto i : E) {
			int u = i.fi, v = i.se;
			if(u == s || v == s) ls[Find(v ^ u ^ s)] = true;
			if(u == t || v == t) lt[Find(v ^ u ^ t)] = true;
		}
		ls[s] = ls[t] = lt[s] = lt[t] = false;
		for(int i = 1; i <= n; ++i) {
			cs += ls[i]; ct += lt[i]; cb += (ls[i] && lt[i]);
		}
		cs -= cb; ct -= cb;
		if(cs <= ds - 1 && ct <= dt - 1 && cb + cs + ct <= ds + dt - (!cb) - 1) {
			printf("Yes\n");
			for(auto i : spt) printf("%d %d\n", i.fi, i.se);
			for(auto i : E) {
				int u = i.fi, v = i.se;
				if((u == s || v == s) && !lt[Find(v ^ u ^ s)] && ls[Find(v ^ u ^ s)]) {
					ls[Find(v ^ u ^ s)] = false;
					printf("%d %d\n", u, v); --ds;
				}
				if((u == t || v == t) && !ls[Find(v ^ u ^ t)] && lt[Find(v ^ u ^ t)]) {
					lt[Find(v ^ u ^ t)] = false;
					printf("%d %d\n", u, v); --dt;
				}
			}
		//	printf("---\n");
			if(cb) {
				int x;
				for(int i = 1; i <= n; ++i)
					if(ls[Find(i)] && lt[Find(i)]) { x = Find(i); break; }
				for(auto i : E) {
					int u = i.fi, v = i.se;
					if(ls[x] && (u == s || v == s) && Find(v ^ u ^ s) == x) {
						printf("%d %d\n", u, v); ls[x] = false; --ds;
					}
					if(lt[x] && (u == t || v == t) && Find(v ^ u ^ t) == x) {
						printf("%d %d\n", u, v); lt[x] = false; --dt;
					}
				}
			} else printf("%d %d\n", s, t), --ds, --dt;
		//	printf("---");
			for(auto i : E) {
				int u = i.fi, v = i.se;
				if((u == s || v == s) && lt[Find(v ^ u ^ s)] && ds) {
					printf("%d %d\n", u, v); --ds;
					lt[Find(v ^ u ^ s)] = ls[Find(v ^ u ^ s)] = false;
				}
				if((u == t || v == t) && ls[Find(v ^ u ^ t)] && dt) {
					printf("%d %d\n", u, v); --dt;
					lt[Find(v ^ u ^ t)] = ls[Find(v ^ u ^ t)] = false;
				}
			}
		} else {
			printf("No\n");
		}
	} return 0;
}