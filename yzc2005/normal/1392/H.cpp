#include <cstdio>

const int MOD = 998244353, MAXN = 2e6;
int n, m, inv[MAXN + 5];

inline int qkpow ( int a, int b, const int p = MOD ) {
	int ret = 1;
	for ( ; b; a = 1ll * a * a % p, b >>= 1 ) ret = 1ll * ret * ( b & 1 ? a : 1 ) % p;
	return ret;
}

int main () {
	scanf ( "%d %d", &n, &m );
	int turn = ( n + m + 1ll ) * qkpow ( m + 1, MOD - 2 ) % MOD, times = 1;
	for ( int i = 1; i <= n; ++ i ) {
		inv[i] = i ^ 1 ? 1ll * inv[MOD % i] * ( MOD - MOD / i ) % MOD : 1;
		times = ( times + 1ll * m * inv[i] ) % MOD;
	}
	printf ( "%d\n", int ( 1ll * turn * times % MOD ) );
	return 0;
}