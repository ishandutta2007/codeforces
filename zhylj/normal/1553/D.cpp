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

int n, m; char s[N], t[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1); m = strlen(t + 1);
		if(n % 2 != m % 2) {
			for(int i = m; i; --i)
				t[i + 1] = t[i];
			t[1] = s[1];
			++m;
		}
		int i = 0, j = 0;
		for(; i < n && j < m; ) {
			if(s[i + 1] == t[j + 1]) ++i, ++j;
			else i += 2;
		}
		if(j == m) {
			printf("YES\n");
		} else printf("NO\n");
	} return 0;
}