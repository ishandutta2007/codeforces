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
const int kN = 5e5 + 5, kB = 22, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, q, a[kN], ans[kN], b[kB], pos[kB];
std::vector <pii> Q[kN];
void Insert(int v, int p) {
	for(int i = kB - 1; (~i) && v; --i)
		if((v >> i) & 1) {
			if(!b[i]) { b[i] = v; pos[i] = p; break; }
			else if(pos[i] < p) {
				std::swap(pos[i], p);
				std::swap(b[i], v);
			}
			v ^= b[i];
		}
}
int Query(int l) {
	int ret = 0;
	for(int i = kB - 1; ~i; --i)
		if(pos[i] >= l && (ret ^ b[i]) > ret)
			ret ^= b[i];
	return ret;
}
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		rd(q);
		for(int i = 1; i <= q; ++i) {
			int l, r; rd(l, r);
			Q[r].push_back(mkp(l, i));
		}
		for(int i = 1; i <= n; ++i) {
			Insert(a[i], i);
			for(auto j : Q[i])
				ans[j.se] = Query(j.fi);
		}
		for(int i = 1; i <= q; ++i)
			printf("%d\n", ans[i]);
	} return 0;
}