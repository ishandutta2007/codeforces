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
const int N = 2e5 + 5;

int a[N], b[N], s[N], buk[N], buk_2[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(buk, 0, sizeof(buk));
		memset(buk_2, 0, sizeof(buk_2));
		int n; rd(n);
		int m = 0;
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1, j = 0; i <= n; ++i) {
			++buk[a[i]];
			while(buk[j]) ++j;
			s[i] = j;
		}
		int tot_mex = s[n];
		for(int i = 1, lst = 0, k = 0; i <= n; ++i) {
			++buk_2[a[i]];
			while(buk_2[k]) ++k;
			if(k == tot_mex) {
				b[++m] = k;
				for(int j = lst + 1; j <= i; ++j) {
					--buk[a[j]];
					if(!buk[a[j]]) tot_mex = std::min(tot_mex, a[j]);
					--buk_2[a[j]];
				}
				lst = i;
				k = 0;
			}
		}
		printf("%d\n", m);
		for(int i = 1; i <= m; ++i)
			printf("%d ", b[i]);
		printf("\n");
	} return 0;
}