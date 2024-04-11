#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

const int N = 1e6 + 10, P = 1e9 + 7;

inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
inline int mul(int x, int y) {return 1ll * x * y % P;}
inline int Pow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = mul(ret, x);
		x = mul(x, x), y >>= 1;
	}
	return ret;
}

int n, q;
int A[3][N << 2], pw[N << 2], inv[N << 2];

int v[N << 2];

void init() {
	pw[0] = inv[0] = 1;
	for (int i = 1; i <= 3 * n + 10; i++)
		pw[i] = mul(pw[i - 1], i);
	int T = Pow(pw[3 * n + 10], P - 2);
	for (int i = 3 * n + 10; i >= 1; i--)
		inv[i] = T, T = mul(T, i);
}

int C(int x, int y) {
	if (x < y) return 0;
	return mul(pw[x], mul(inv[y], inv[x - y]));
}

int main() {
	read(n), read(q), init();
	int inv3 = Pow(3, P - 2);
	for (int i = 0; i <= n; i++)
		A[0][1] = add(A[0][1], C(3 * i, 1));
	for (int i = 0; i <= n; i++)
		A[1][1] = add(A[1][1], C(3 * i + 1, 1));
	for (int i = 2; i <= 3 * n; i++) {
		A[0][i] = mul(sub(C(3 * n + 3, i + 1), add(mul(A[0][i - 1], 2), A[1][i - 1])), inv3);
		A[1][i] = add(A[0][i], A[0][i - 1]);
	}
	for (int i = 1; i <= q; i++) {
		int x; read(x);
		print(A[0][x], '\n');
	}
	return 0;
}