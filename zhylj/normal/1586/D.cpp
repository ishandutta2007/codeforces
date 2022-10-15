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
const int N = 1e5 + 5;

int p[N], dg[N];
std::vector <int> E[N];
void Dfs(int u, int cur) {
	p[u] = cur;
	for(int v : E[u])
		Dfs(v, cur - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n; rd(n);
		for(int i = 1; i <= n; ++i) {
			printf("? ");
			for(int j = 1; j <= n; ++j) {
				if(i == j) printf("1 ");
				else printf("2 ");
			}
			printf("\n");
			fflush(stdout);
			int x; rd(x);
			if(i != x && x != 0) { E[i].push_back(x); ++dg[x]; }
			printf("? ");
			for(int j = 1; j <= n; ++j) {
				if(i == j) printf("2 ");
				else printf("1 ");
			}
			printf("\n");
			fflush(stdout);
			rd(x);
			if(i != x && x != 0) { E[x].push_back(i); ++dg[i]; }
		}
		for(int i = 1; i <= n; ++i)
			if(!dg[i]) {
				Dfs(i, n);
				break;
			}
		printf("! ");
		for(int i = 1; i <= n; ++i) 
			printf("%d ", p[i]);
		printf("\n");
	} return 0;
}