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
const int kN = 505, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m; char s[kN][kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		for(int i = 1; i <= n + 2; ++i)
			for(int j = 1; j <= m + 2; ++j)
				s[i][j] = 0;
		rd(n, m);
		for(int i = 1; i <= n; ++i)
			scanf("%s", s[i] + 1);
		for(int i = 1; i <= n; i += 3) {
			for(int j = 1; j <= m; ++j)
				s[i][j] = 'X';
			bool flag = false;
			for(int j = 1; j <= m; ++j) {
				if(s[i + 1][j] == 'X' || s[i + 2][j] == 'X') {
					s[i + 1][j] = s[i + 2][j] = 'X';
					flag = true;
					if(i + 3 <= n) break;
				}
			}
			if(!flag) {
				s[i + 1][1] = s[i + 2][1] = 'X';
			}
		}
		for(int i = 1; i <= n; ++i) {
			printf("%s\n", s[i] + 1);
		}
	} return 0;
}