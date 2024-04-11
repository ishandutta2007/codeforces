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
const int kN = 1e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, A[kN][kN], opt[kN * kN], cnt = 0; char str[kN][kN];
void Print(int a1, int a2, int a3, int a4, int a5, int a6) {
	opt[++cnt] = a1; opt[++cnt] = a2; opt[++cnt] = a3;
	opt[++cnt] = a4; opt[++cnt] = a5; opt[++cnt] = a6;
}
void Print(int a1, int a2) {
	opt[++cnt] = a1; opt[++cnt] = a2;
}
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		cnt = 0;
		rd(n, m);
		for(int i = 1; i <= n; ++i) {
			scanf("%s", str[i] + 1);
			for(int j = 1; j <= m; ++j)
				A[i][j] = (str[i][j] == '1');
		}
		if(n % 2 != 0) {
			for(int i = 1; i < m; ++i)
				if(A[n][i] == 1) {
					Print(n, i, n - 1, i + 1, n - 1, i);
					A[n][i] ^= 1; A[n - 1][i + 1] ^= 1; A[n - 1][i] ^= 1;
				}
			if(A[n][m] == 1) {
				Print(n, m, n - 1, m - 1, n - 1, m);
				A[n][m] ^= 1; A[n - 1][m - 1] ^= 1; A[n - 1][m] ^= 1;
			}
		}
		if(m % 2 != 0) {
			if(A[1][m] == 1) {
				Print(1, m, 1, m - 1, 2, m - 1);
				A[1][m] ^= 1; A[1][m - 1] ^= 1; A[2][m - 1] ^= 1;
			}
			for(int i = 2; i <= (n % 2 != 0 ? n - 1 : n); ++i)
				if(A[i][m] == 1) {
					Print(i, m, i, m - 1, i - 1, m - 1);
					A[i][m] ^= 1; A[i][m - 1] ^= 1; A[i - 1][m - 1] ^= 1;
				}
			//printf("?");
		}
		/*for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j)
				printf("%d ", A[i][j]);
			printf("\n");
		}*/
		for(int i = 1; i <= n - n % 2; i += 2) {
			for(int j = 1; j <= m - m % 2; j += 2) {
				int s[2][2] = { { 0, 0 }, { 0, 0 } };
				for(int k1 = 0; k1 < 2; ++k1)
					for(int k2 = 0; k2 < 2; ++k2) {
						if(A[i + k1][j + k2]) {
							for(int p1 = 0; p1 < 2; ++p1)
								for(int p2 = 0; p2 < 2; ++p2)
									if(p1 != k1 || p2 != k2)
										s[p1][p2] ^= 1;
						}
					}
				for(int k1 = 0; k1 < 2; ++k1)
					for(int k2 = 0; k2 < 2; ++k2)
						if(s[k1][k2]) {
							for(int p1 = 0; p1 < 2; ++p1)
								for(int p2 = 0; p2 < 2; ++p2)
									if(p1 != k1 || p2 != k2) {
										Print(i + p1, j + p2);
									}
						}
			}
		}
		printf("%d\n", cnt / 6);
		for(int i = 1; i <= cnt; ++i) {
			printf("%d ", opt[i]);
			if(i % 6 == 0) printf("\n");
		}
	} return 0;
}