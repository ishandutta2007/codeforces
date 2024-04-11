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
const int N = 2e5 + 5, MOD = 998244353;

void Upd(int &x, int y) { x += y; x -= x >= MOD ? MOD : 0; }

int f[N][2][2][2];

int n, w, a[N];
char s[N];

int Calc1() {
	memset(f, 0, sizeof(f));
	f[0][1][1][1] = 1;
	for(int t = 1; t <= n; ++t) {
		for(int i = 0; i < 2; ++i) for(int p = 0; p < 2; ++p) if(i == 0 || p <= a[t])
			for(int j = 0; j < 2; ++j) for(int q = 0; q < 2; ++q) if(j == 0 || q <= a[t])
				for(int k = 0; k < 2; ++k) for(int r = 0; r < 2; ++r) if(k == 0 || r <= a[t]) {
					if((p ^ q) + (q ^ r) == (p ^ r)) {
						int _i = i ^ (i == 1 && p < a[t]),
							_j = j ^ (j == 1 && q < a[t]),
							_k = k ^ (k == 1 && r < a[t]);
						Upd(f[t][_i][_j][_k], f[t - 1][i][j][k]);
					}
				}
	}
	int ret = 0;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				Upd(ret, f[n][i][j][k]);
	return ret;
}

int Calc2() {
	memset(f, 0, sizeof(f));
	f[0][1][1][1] = 1;
	for(int t = 1; t <= n; ++t) {
		for(int i = 0; i < 2; ++i) for(int p = 0; p < 2; ++p) if(i == 0 || p <= a[t])
			for(int j = 0; j < 2; ++j) for(int q = 0; q < 2; ++q) if(j == 0 || q <= a[t])
				for(int k = 0; k < 2; ++k) for(int r = 0; r < 2; ++r) if(k == 0 || r <= a[t]) {
					if((p ^ q) - (q ^ r) == (p ^ r)) {
						int _i = i ^ (i == 1 && p < a[t]),
							_j = j ^ (j == 1 && q < a[t]),
							_k = k ^ (k == 1 && r < a[t]);
						Upd(f[t][_i][_j][_k], f[t - 1][i][j][k]);
					}
				}
	}
	int ret = 0, ret_2 = 0;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				Upd(ret, f[n][i][j][k]);
	memset(f, 0, sizeof(f));
	f[0][1][1][1] = 1;
	for(int t = 1; t <= n; ++t) {
		for(int i = 0; i < 2; ++i) for(int p = 0; p < 2; ++p) if(i == 0 || p <= a[t])
			for(int j = 0; j < 2; ++j) for(int q = 0; q < 2; ++q) if(j == 0 || q <= a[t])
				for(int k = 0; k < 2; ++k) for(int r = 0; r < 2; ++r) if(k == 0 || r <= a[t]) {
					if((p ^ q) == (q ^ r)) {
						int _i = i ^ (i == 1 && p < a[t]),
							_j = j ^ (j == 1 && q < a[t]),
							_k = k ^ (k == 1 && r < a[t]);
						Upd(f[t][_i][_j][_k], f[t - 1][i][j][k]);
					}
				}
	}
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				Upd(ret_2, f[n][i][j][k]);
	return (ret * 2LL - ret_2 + MOD) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 1; i <= n; ++i) {
			a[i] = s[i] - '0';
			w = (w * 2LL + a[i]) % MOD;
		}
		ll tot = 1LL * (w + 1) * (w + 1) % MOD * (w + 1) % MOD,
			ans = (Calc1() + Calc2() - 2LL * (w + 1) * (w + 1) % MOD + (w + 1)) % MOD;
		ll cnt = 0;
		ans = (tot - ans) % MOD;
		ans = (ans + MOD) % MOD;
		printf("%lld\n", ans);
	} return 0;
}