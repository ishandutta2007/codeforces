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
const int N = 250 + 5, MOD = 1e9 + 7;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}
int Inv(int a) { return QPow(a, MOD - 2); }

int n, K, m;

struct Eq {
	int x[N];
	Eq() { memset(x, 0, sizeof(x)); }
	int& operator [](int i) { return x[i]; }
	Eq operator +(Eq rhs) {
		Eq ret;
		for(int i = 0; i <= m; ++i)
			ret[i] = (x[i] + rhs[i]) % MOD;
		return ret;
	}
	Eq operator -(Eq rhs) {
		Eq ret;
		for(int i = 0; i <= m; ++i)
			ret[i] = (x[i] - rhs[i] + MOD) % MOD;
		return ret;
	}
	Eq operator *(int rhs) {
		Eq ret;
		for(int i = 0; i <= m; ++i)
			ret[i] = 1LL * x[i] * rhs % MOD;
		return ret;
	}
	Eq operator /(int rhs) {
		return (*this) * Inv(rhs);
	}
} f[N][N], s[N][N], s_d[N][N];
int mat[N][N];
void Solve() {
	for(int i = 1; i <= m - 2; ++i) {
		for(int j = i; !mat[i][i] && j <= m - 1; ++j)
			if(mat[j][i]) {
				for(int k = 1; k <= m + 1; ++k)
					std::swap(mat[j][k], mat[i][k]);
				break;
			}
		int d = Inv(mat[i][i]);
		for(int j = 1; j <= m - 1; ++j)
			mat[i][j] = 1LL * mat[i][j] * d % MOD;
		for(int j = 1; j <= m - 2; ++j)
			if(i != j) {
				d = mat[j][i];
				for(int k = 1; k <= m - 1; ++k)
					mat[j][k] = (mat[j][k] - 1LL * mat[i][k] * d % MOD + MOD) % MOD;
			}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, K, m);
		for(int i = 3; i <= m; ++i) f[i][2][i] = 1;
		for(int i = 1; i <= m; ++i) f[i][1][0] = f[i][i][0] = i;
		for(int j = 2; j <= m; ++j) {
			for(int i = j + 1; i < m; ++i) {
				s[i - 1][j] = s[i - 2][j] + f[i - 1][j];
				s_d[i - 1][j - 1] = s_d[i - 2][j - 2] + f[i - 1][j - 1];

				int d = 1LL * (m - i) * (i + 1 - j) % MOD *
						Inv(1LL * m * (i + 1) % MOD) % MOD,
					d_2 = 1LL * i * Inv(1LL * m * (i - 1) % MOD) % MOD,
					d_3 = 1LL * (m - i) * j % MOD *
						Inv(1LL * m * (i + 1) % MOD) % MOD;

				f[i + 1][j + 1] = f[i][j]
					- f[i + 1][j] * d
					- s[i - 1][j] * d_2
					- s_d[i - 1][j - 1] * d_2;
				
				f[i + 1][j + 1] = f[i + 1][j + 1] / d_3;
			}
			if(j == m) continue;
			s[m - 1][j] = s[m - 2][j] + f[m - 1][j];
			s_d[m - 1][j - 1] = s_d[m - 2][j - 2] + f[m - 1][j - 1];
			int d = Inv(m - 1);
			Eq tmp = (s[m - 1][j] + s_d[m - 1][j - 1]) * d;
			for(int k = 3; k <= m; ++k)
				mat[j - 1][k - 2] = (tmp[k] - f[m][j][k] + MOD) % MOD;
			mat[j - 1][m - 1] = (f[m][j][0] - tmp[0] + MOD) % MOD;
		}
		Solve();
		int ans = f[n][K][0];
		for(int i = 3; i <= m; ++i) {
			ans = (ans + 1LL * mat[i - 2][m - 1] * f[n][K][i]) % MOD;
		}
		printf("%d\n", ans);
	} return 0;
}