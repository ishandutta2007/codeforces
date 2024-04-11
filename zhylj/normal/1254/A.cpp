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
const int kN = 1e2 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

char g[kN][kN], o[kN][kN], chk[233] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		int n, m, k, tot_R = 0, cur_c = 0;
		rd(n, m, k);
		for(int i = 1; i <= n; ++i)
			scanf("%s", g[i] + 1);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(g[i][j] == 'R') ++tot_R;
		//printf("%d\n", tot_R);
		for(int i = 1, j = 0; cur_c < k; ++cur_c) {
			int x = tot_R / k + (cur_c < tot_R % k);
			//std::cout << x << std::endl;
			for(; x; o[i][j] = chk[cur_c], x -= (g[i][j] == 'R')) {
				j += (i & 1) ? 1 : -1;
				//std::cout << i << " " << j << std::endl;
				if(j > m) j = m, ++i;
				if(j < 1) j = 1, ++i;
			}
		/*	for(int i = 1; i <= n; ++i)
				printf("%s\n", o[i] + 1);*/
		}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(!o[i][j]) o[i][j] = chk[k - 1];
		for(int i = 1; i <= n; ++i)
			printf("%s\n", o[i] + 1);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				o[i][j] = g[i][j] = 0;
		//std::cout << "====" << std::endl;
	} return 0;
}