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
const int N = 6e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, p[N], q[N], b[N];
bool vis[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(p[i]);
		for(int i = 0; i <= n; ++i) b[i] = 0;
		for(int i = 1; i <= n; ++i) {
			int d = 0;
			if(p[i] <= i) d = i - p[i];
			else d = i + n - p[i];
			++b[d];
		}
		std::vector <int> ans;
		for(int i = 0; i < n; ++i) if(b[i] >= n / 3) {
			for(int j = 1; j <= n; ++j) {
				q[j] = p[(j - 1 + i) % n + 1];
				vis[j] = false;
			}
			int cnt = 0;
			for(int j = 1; j <= n; ++j) if(!vis[j]) {
				vis[j] = true; ++cnt;
				for(int cur = q[j]; cur != j; cur = q[cur]) vis[cur] = true;
			}
			if(n - cnt <= m) ans.push_back(i);
		}
		printf("%d ", ans.size());
		for(auto i : ans) printf("%d ", i);
		printf("\n");
	} return 0;
}