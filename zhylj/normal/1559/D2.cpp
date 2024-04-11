/*
ran ran, wei le ni, wo yao a le zhe dao ti.
*/
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

int n, m1, m2;
std::vector <int> s1, s2;
std::vector <pii> ans;

struct Dsu {
	int fa[N];
	void Init(int x) {
		for(int i = 1; i <= x; ++i) fa[i] = i;
	}
	int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
	void Merge(int x, int y) { fa[Find(x)] = Find(y); }
} A, B;

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
		for(int i = 2; i <= n; ++i)
			if(A.Find(i) != A.Find(1) && B.Find(i) != B.Find(1)) {
				A.Merge(1, i), B.Merge(1, i);
				ans.push_back(mkp(1, i));
			}
		int p = 1;
		for(int i = 1; i <= n; ++i) {
			if(A.Find(i) != A.Find(1)) s1.push_back(i);
			if(B.Find(i) != B.Find(1)) s2.push_back(i);
		}
		while(true) {
			while(!s1.empty() && A.Find(s1.back()) == A.Find(1))
				s1.pop_back();
			while(!s2.empty() && B.Find(s2.back()) == B.Find(1))
				s2.pop_back();
			if(s1.empty() || s2.empty()) break;
			A.Merge(s1.back(), s2.back());
			B.Merge(s1.back(), s2.back());
			ans.push_back(mkp(s1.back(), s2.back()));
		}
		printf("%d\n", ans.size());
		for(auto i : ans)
			printf("%d %d\n", i.fi, i.se);
	} return 0;
}