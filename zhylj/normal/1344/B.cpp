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
const int kN = 5e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, fa[kN]; char g[kN][kN];
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) { fa[Find(x)] = Find(y); }

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) {
			scanf("%s", g[i] + 1);
		}
		for(int i = 1; i <= n + m; ++i) fa[i] = i;
		int cnt = 0;
		bool flag = true, emp_row = false, emp_col = false;
		for(int i = 1; i <= n; ++i) {
			bool bg = false, ed = false;
			for(int j = 1; j <= m; ++j) {
				if(!bg && g[i][j] == '#') bg = true;
				if(bg && !ed && g[i][j] == '.') ed = true;
				if(ed && g[i][j] == '#') flag = false;
			}
			if(!bg) emp_row = true, --cnt;
		}
		for(int j = 1; j <= m; ++j)  {
			bool bg = false, ed = false;
			for(int i = 1; i <= n; ++i) {
				if(!bg && g[i][j] == '#') bg = true;
				if(bg && !ed && g[i][j] == '.') ed = true;
				if(ed && g[i][j] == '#') flag = false;
			}
			if(!bg) emp_col = true, --cnt;
		}
		if(!flag || (emp_col != emp_row)) printf("-1\n");
		else {
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= m; ++j)
					if(g[i][j] == '#') Merge(i, j + n);
			for(int i = 1; i <= n + m; ++i)
				if(fa[i] == i) ++cnt;
			printf("%d\n", cnt);
		}
	} return 0;
}