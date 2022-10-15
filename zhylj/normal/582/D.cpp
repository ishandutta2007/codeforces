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
const int N = 3500 + 5, MOD = 1e9 + 7;

int n_d[N], n[N], n_d_len, n_len, p, a;
char n_s[N];

void GetN() {
	while(n_d_len) {
		ll r = 0;
		for(int i = n_d_len; i; --i) {
			r = r * 10 + n_d[i];
			n_d[i] = r / p;
			r %= p;
		}
		n[++n_len] = r;
		for(; n_d_len && !n_d[n_d_len]; --n_d_len);
	}
}

int f[N][N][2][2];
void Upd(int &x, int y, int c = 1) { x = (x + 1LL * y * c % MOD + MOD) % MOD; }
int C(int x) { return x < 0 ? 0 : 1LL * x * (x - 1) / 2 % MOD; }
int Solve() {
	int res = 0;
	f[n_len][0][0][1] = 1;
	for(int i = n_len; i; --i)
		for(int j = 0; j <= n_len; ++j) {
			Upd(f[i - 1][j][0][0], f[i][j][0][0], C(p + 1));
			Upd(f[i - 1][j + 1][1][0], f[i][j][0][0], C(p));

			Upd(f[i - 1][j][0][0], f[i][j][1][0], C(p));
			Upd(f[i - 1][j + 1][1][0], f[i][j][1][0], C(p + 1));

			Upd(f[i - 1][j][0][1], f[i][j][0][1], n[i] + 1);
			Upd(f[i - 1][j + 1][1][1], f[i][j][0][1], n[i]);
			Upd(f[i - 1][j][0][0], f[i][j][0][1], C(n[i] + 1));
			Upd(f[i - 1][j + 1][1][0], f[i][j][0][1], C(n[i]));

			int tot = 1LL * n[i] * p % MOD;

			Upd(f[i - 1][j][0][1], f[i][j][1][1], p - (n[i] + 1));
			Upd(f[i - 1][j + 1][1][1], f[i][j][1][1], p - n[i]);
			Upd(f[i - 1][j][0][0], f[i][j][1][1], tot - C(n[i] + 1));
			Upd(f[i - 1][j + 1][1][0], f[i][j][1][1], tot - C(n[i]));
		}
	for(int i = a; i <= n_len; ++i)
		for(int j = 0; j < 2; ++j)
			Upd(res, f[0][i][0][j]);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(p, a);
		scanf("%s", n_s + 1);
		n_d_len = strlen(n_s + 1);
		for(int i = 1; i <= n_d_len; ++i)
			n_d[n_d_len - i + 1] = n_s[i] - '0';
		GetN();
		printf("%d\n", Solve());
	} return 0;
}