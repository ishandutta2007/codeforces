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
const int N = 32, Inf = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

void Plus(int &x, int y) { x = x + y >= Mod ? x + y - Mod : x + y; }
void Minus(int &x, int y) { x = x - y < 0 ? x - y + Mod : x - y; }

int f[2][2][2][N], g[2][2][2][N];
int Solve(int X, int Y, int K) {
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	f[1][1][1][N] = 1;
	for(int i = N - 1; ~i; --i) {
		int v_x = (X >> i) & 1, v_y = (Y >> i) & 1, v_k = (K >> i) & 1;
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				for(int l = 0; l < 2; ++l)
					for(int v_r = 0; v_r < 2; ++v_r)
						for(int v_c = 0; v_c < 2; ++v_c) {
							int nj = j, nk = k, nl = l;
							if(j) {
								if(v_r > v_x) continue;
								nj = (v_r == v_x);
							}
							if(k) {
								if(v_c > v_y) continue;
								nk = (v_c == v_y);
							}
							if(l) {
								if((v_r ^ v_c) > v_k) continue;
								nl = ((v_r ^ v_c) == v_k);
							}
							Plus(f[nj][nk][nl][i], f[j][k][l][i + 1]);
							Plus(g[nj][nk][nl][i], g[j][k][l][i + 1]);
							Plus(g[nj][nk][nl][i],
								1LL * f[j][k][l][i + 1] * ((v_r ^ v_c) << i) % Mod
							);
						}
	}
	return (g[0][0][0][0] + f[0][0][0][0]) % Mod;
}

int Solve(int xl, int yl, int xr, int yr, int k) {
	int ret = 0;
	Plus(ret, Solve(xr, yr, k));
	Minus(ret, Solve(xr, yl - 1, k));
	Minus(ret, Solve(xl - 1, yr, k));
	Plus(ret, Solve(xl - 1, yl - 1, k));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int xl, yl, xr, yr, k; rd(xl, yl, xr, yr, k);
		//printf("%d\n", Solve(0, 0, k));
		printf("%d\n", Solve(xl, yl, xr, yr, k));
	} return 0;
}