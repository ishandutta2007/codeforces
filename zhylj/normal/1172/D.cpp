#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e3 + 5, M = 5e5 + 5;

int n, r[N], c[N], cur[N], b[N][N], p_cnt;
std::vector <pii> p[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(r[i]);
		for(int i = 1; i <= n; ++i) rd(c[i]);
		for(int i = 1; i <= n; ++i) cur[i] = i;
		for(int i = 1; i < n; ++i) {
			for(int j = 1; j <= n; ++j)
				if(r[cur[j]] == i) {
					if(i != j) b[j][i] = b[i][i] = ++p_cnt;
					std::swap(cur[j], cur[i]);
					break;
				}
		}
		for(int i = 1; i <= n; ++i) cur[i] = i;
		for(int i = 1; i < n; ++i) {
			for(int j = 1; j <= n; ++j)
				if(c[cur[j]] == i) {
					if(b[i][i]) std::swap(b[i][i], b[i][j]);
					else if(i != j) b[i][j] = b[i][i] = ++p_cnt;
					std::swap(cur[j], cur[i]);
					break;
				}
		}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(b[i][j]) p[b[i][j]].push_back(mkp(i, j));
		printf("%d\n", p_cnt);
		for(int i = 1; i <= p_cnt; ++i) {
			for(pii j : p[i]) printf("%d %d ", j.fi, j.se);
			printf("\n");
		}
	} return 0;
}