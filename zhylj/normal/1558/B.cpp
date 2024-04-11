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
const int N = 4e6 + 5, Inf = 0x3f3f3f3f;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, p, f[N], s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, p);
		f[1] = s[1] = 1;
		for(int i = 1; i <= n; ++i) {
			s[i] = (s[i] + s[i - 1]) % p;
			f[i] = s[i];
			if(i > 1) {
				for(int j = 1; j <= i && i * j <= n; ++j) {
					s[j * i] = (s[j * i] + f[j]) % p;
					int r = std::min((j + 1) * i, n + 1);
					s[r] = (s[r] - f[j] + p) % p;
				}
			}
			for(int j = 1; j < i && i * j <= n; ++j) {
				s[i * j] = (s[i * j] + f[i]) % p;
				int r = std::min((i + 1) * j, n + 1);
				s[r] = (s[r] - f[i] + p) % p;
			}
			s[i + 1] = (s[i + 1] + f[i]) % p;
		}
		printf("%d\n", f[n]);
	} return 0;
}