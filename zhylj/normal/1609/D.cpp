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
const int N = 5e5 + 5;

int n, d, siz[N], fa[N];
int Find(int x) {
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Merge(int x, int y) {
	int f_x = Find(x), f_y = Find(y);
	if(f_x != f_y) {
		fa[f_x] = f_y;
		siz[f_y] += siz[f_x];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, d);
		for(int i = 1; i <= n; ++i)	
			fa[i] = i, siz[i] = 1;
		for(int i = 1; i <= d; ++i) {
			int u, v; rd(u, v);
			Merge(u, v);
			std::vector <int> a;
			int ans = 0, tot = 0;
			for(int j = 1; j <= n; ++j)
				if(j == Find(j)) {
					++tot;
					a.push_back(siz[j]);
				}
			int res = i - (n - tot);
			std::sort(a.begin(), a.end());
			std::reverse(a.begin(), a.end());
			for(int j = 0; j < res + 1 && j < a.size(); ++j)
				ans += a[j];
			printf("%d\n", ans - 1);
		}
	} return 0;
}