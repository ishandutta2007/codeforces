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
const int N = 2e6 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int deg[N], n; char str[N];
std::vector <int> E[N];
void Add(int u, int v) {
	++deg[u]; ++deg[v];
	E[u].push_back(v);
	E[v].push_back(u);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n << 2; ++i) E[i].clear(), deg[i] = 0;
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		for(int i = 1; i <= len; ++i)
			if(str[i] == 'W') {
				Add(i, n + 1);
				Add(n + 1, n + 2);
				Add(n + 1, n + 3);
				n += 3;
			}
		bool flag = false;
		for(int i = 1; i <= n; ++i) {
			if(deg[i] >= 4) flag = true;
			if(deg[i] == 3) {
				int cnt = 0;
				for(auto v : E[i])
					if(deg[v] > 1) ++cnt;
				if(cnt >= 2) flag = true;
			}
			if(flag) break;
		}
		int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0;
		for(int i = 1; i <= n; ++i) {
			if(deg[i] == 1) ++cnt_1;
			if(deg[i] == 2) ++cnt_2;
			if(deg[i] == 3) ++cnt_3;
		}
		if(cnt_3 == 2 && cnt_2 % 2 == 1) flag = true;
		printf(flag ? "White\n" : "Draw\n");
	} return 0;
}