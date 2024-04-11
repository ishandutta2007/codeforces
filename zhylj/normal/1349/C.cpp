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
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 1e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, t, a[kN][kN], d[kN][kN]; char c[kN];
const int step[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool Check(int i, int j) {
	for(int k = 0; k < 4; ++k) {
		int ni = i + step[k][0], nj = j + step[k][1];
		if(ni > 0 && nj > 0 && ni <= n && nj <= m && a[ni][nj] == a[i][j]) return true;
	}
	return false;
}
std::queue <pii> que;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m, t);
		for(int i = 1; i <= n; ++i) {
			scanf("%s", c + 1);
			for(int j = 1; j <= m; ++j) a[i][j] = c[j] - '0';
		}
		for(int i = 1; i <= n; ++i) 
			for(int j = 1; j <= m; ++j) {
				if(Check(i, j)) { que.push(mkp(i, j)); d[i][j] = 1; }
			}
		while(!que.empty()) {
			pii cur = que.front(); que.pop();
			for(int k = 0; k < 4; ++k) {
				int ni = cur.fi + step[k][0], nj = cur.se + step[k][1];
				if(ni > 0 && nj > 0 && ni <= n && nj <= m && !d[ni][nj]) {
					d[ni][nj] = d[cur.fi][cur.se] + 1;
					que.push(mkp(ni, nj));
				}
			}
		}
		/*for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) 
				printf("%d ", d[i][j]);
			printf("\n");
		}*/
		while(t--) {
			int i, j; ll p; rd(i, j, p);
			if(!d[i][j] || p < d[i][j]) {
				printf("%d\n", a[i][j]);
			} else {
				//printf("%d ", (p - d[i][j] + 1) & 1);
				printf("%d\n", a[i][j] ^ ((p - d[i][j] + 1) & 1));
			}
		}
	} return 0;
}