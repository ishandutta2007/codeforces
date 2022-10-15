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
const int N = 4e3 + 5, K = 800 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, k, s[N][N], dp[K][N];

int F(int x, int y) {
	return s[x][x] - s[x][y] - s[y][x] + s[y][y];
}

std::deque <pii> que;
void Calc(int g[], int f[]) {
	que.clear();
	for(int i = 0; i <= n; ++i) {
		while(que.size() > 1 && que[1].se <= i)
			que.pop_front();
		if(!que.empty()) {
			int j = que.front().fi;
			f[i] = g[j] + F(j, i);
		}
		while(!que.empty()) {
			int j = que.back().fi, k = que.back().se;
			if(g[j] + F(j, k) < g[i] + F(i, k)) break;
			que.pop_back();
		}
		if(que.empty()) que.push_back(mkp(i, i + 1));
		else {
			int j = que.back().fi, l = std::max(que.back().se + 1, i + 1), r = n + 1;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(g[j] + F(j, mid) < g[i] + F(i, mid))
					l = mid + 1;
				else r = mid;
			}
			if(l < n + 1) que.push_back(mkp(i, l));
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) {
				rd(s[i][j]);
				s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			}
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		for(int i = 1; i <= k; ++i)
			Calc(dp[i - 1], dp[i]);
		printf("%d\n", dp[k][n] / 2);
	} return 0;
}