#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 2e5 + 10;

namespace MOD {
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
	inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
};
using namespace MOD;

char s[N];
int n, f[N][2][2][2], ans, g[N][2][2][2];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	f[0][0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int v = s[i] - '0';
		ans = add(mul(ans, 2), v);
		for (int t1 = 0; t1 < 2; t1++)
			for (int t2 = 0; t2 < 2; t2++)
				for (int t3 = 0; t3 < 2; t3++) {
					if (!f[i - 1][t1][t2][t3]) continue;
					for (int a = 0; a < (t1 == 1 ? 2 : v + 1); a++)
						for (int b = 0; b < (t2 == 1 ? 2 : v + 1); b++)
							for (int c = 0; c < (t3 == 1 ? 2 : v + 1); c++) {
								int to1 = t1 == 0 && a == v ? 0 : 1;
								int to2 = t2 == 0 && b == v ? 0 : 1;
								int to3 = t3 == 0 && c == v ? 0 : 1;
								int x = (a ^ b), y = (b ^ c), z = (c ^ a);
								if (x == 0 && y == 1 && z == 1) continue;
								inc(f[i][to1][to2][to3], f[i - 1][t1][t2][t3]);
							}
				}
	}
	g[0][0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int v = s[i] - '0';
		for (int t1 = 0; t1 < 2; t1++)
			for (int t2 = 0; t2 < 2; t2++)
				for (int t3 = 0; t3 < 2; t3++) {
					if (!g[i - 1][t1][t2][t3]) continue;
					for (int a = 0; a < (t1 == 1 ? 2 : v + 1); a++)
						for (int b = 0; b < (t2 == 1 ? 2 : v + 1); b++)
							for (int c = 0; c < (t3 == 1 ? 2 : v + 1); c++) {
								int to1 = t1 == 0 && a == v ? 0 : 1;
								int to2 = t2 == 0 && b == v ? 0 : 1;
								int to3 = t3 == 0 && c == v ? 0 : 1;
								int x = (a ^ b), y = (b ^ c), z = (c ^ a);
								if (x == y && z == 0)
									inc(g[i][to1][to2][to3], g[i - 1][t1][t2][t3]);
							}
				}
	}
	inc(ans, 1);
	ans = sub(add(mul(mul(ans, ans), ans), 0), ans);
	int tmp = 0, tmp2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++) {
				dec(ans, mul(f[n][i][j][k], 3));
				inc(ans, mul(g[n][i][j][k], 3));
				tmp += f[n][i][j][k];
				tmp2 += g[n][i][j][k];
			}
	printf("%d\n", ans);
	return 0;
}