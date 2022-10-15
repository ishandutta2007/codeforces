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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

struct Dsu {
	int fa[N];
	void Init(int n) {
		for(int i = 1; i <= n; ++i) fa[i] = i;
	}
	int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
	void Merge(int x, int y) {
		fa[Find(x)] = Find(y);
	}
} A, B;

int n, m1, m2;
std::vector <pii> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m1, m2);
		A.Init(n); B.Init(n);
		for(int i = 1; i <= m1; ++i) {
			int u, v; rd(u, v);
			A.Merge(u, v);
		}
		for(int i = 1; i <= m2; ++i) {
			int u, v; rd(u, v);
			B.Merge(u, v);
		}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(A.Find(i) != A.Find(j) && B.Find(i) != B.Find(j)) {
					ans.push_back(mkp(i, j));
					A.Merge(i, j);
					B.Merge(i, j);
				}
		printf("%d\n", (int)ans.size());
		for(auto i : ans)
			printf("%d %d\n", i.fi, i.se);
	} return 0;
}