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
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 600 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;
const ff Eps = 1e-20;

int n, k; ff f[N], p[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		ff ans = 0;
		p[1] = 1;
		for(int i = 1; i <= n; ++i) {
			for(int j = std::min(i + 1, N - 1); j >= 0; --j) {
				if(f[j] > Eps || p[j] > Eps)
					f[j] = f[j] * (k - 1 + j / (ff)(j + 1)) + p[j] * j / (ff)2;
				if(p[j] > Eps)
					p[j] = p[j] * (k - 1 + j / (ff)(j + 1));
				if(j) {
					if(f[j - 1] > Eps || p[j - 1] > Eps)
						f[j] += (f[j - 1] + p[j - 1] * (j - 1)) / j;
					if(p[j - 1] > Eps)
						p[j] += p[j - 1] / j;
				}
				f[j] /= k; p[j] /= k;
			}
		}
		for(int i = 1; i < N; ++i)
			ans += f[i];
		printf("%.12lf\n", (double)ans * k);
	} return 0;
}