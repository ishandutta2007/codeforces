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
const int N = 100 + 5;

int n, b[N][N];
char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		printf("? %d %d\n", 1, n);
		fflush(stdout);
		for(int i = 1; i <= n * (n + 1) / 2; ++i) {
			scanf("%s", s + 1);
			int m = strlen(s + 1);
			for(int j = 1; j <= m; ++j)
				++b[m][s[j] - 'a'];
		}
		if(n > 1) {
			printf("? %d %d\n", 2, n);
			fflush(stdout);
			for(int i = 1; i <= n * (n - 1) / 2; ++i) {
				scanf("%s", s + 1);
				int m = strlen(s + 1);
				for(int j = 1; j <= m; ++j)
					--b[m][s[j] - 'a'];
			}
		}
		printf("! ");
		for(int i = 1; i <= n; ++i) {
			int c = -1;
			for(int j = 0; j < 26; ++j)
				if(b[i][j]) {
					assert(c == -1);
					c = j;
				}
			assert(c != -1);
			printf("%c", c + 'a');
			for(int j = i + 1; j <= n; ++j)
				--b[j][c];
		}
		printf("\n");
		fflush(stdout);
	} return 0;
}