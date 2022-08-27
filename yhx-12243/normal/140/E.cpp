#include <bits/stdc++.h>
#define N 1000054
#define L 5400
#define gcd std::__gcd

typedef long long ll;

int n, l = 0, col, mod;
int len[N], fact[L];
int dp[2][L], *cur = *dp, *nxt = dp[1], C[L], S2[L][L];
int product[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline ll fy(int Len, int Col) {return Len < Col ? 0 : (ll)fact[Col] * S2[Len - 1][Col - 1] % mod;}

void initBinomial(int n) {
	int i, j, d, div, cnt = 1;
	*C = 1, C[1] = n % mod, product[0] = n;
	for (i = 2; i <= l; ++i) {
		product[cnt++] = n - i + 1, div = i;
		for (j = 0; j < cnt && div != 1; ++j)
			if ((d = gcd(div, product[j])) > 1)
				if (div /= d, (product[j] /= d) == 1)
					std::swap(product[j--], product[--cnt]);
		int &res = C[i]; res = 1;
		for (j = 0; j < cnt; ++j) res = (ll)res * product[j] % mod;
	}
}

int main() {
	int i, j; ll ALL, BLL;
	scanf("%d%d%d", &n, &col, &mod);
	for (i = 1; i <= n; ++i) scanf("%d", len + i), up(l, len[i]);
	// factorials
	for (*fact = i = 1; i <= l; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	// Stirlings
	for (*S2[0] = i = 1; i <= l; ++i)
		for (j = 1; j <= l; ++j) S2[i][j] = ((ll)S2[i - 1][j] * j + S2[i - 1][j - 1]) % mod;
	// binomials
	initBinomial(col);
	for (BLL = 0, j = 1; j <= col && j <= len[1]; ++j) BLL += nxt[j] = (ll)C[j] * fy(len[1], j) % mod;
	for (i = 2; i <= n; ++i) {
		std::swap(cur, nxt);
		for (ALL = BLL % mod, BLL = 0, j = 1; j <= col && j <= len[i]; ++j) BLL += nxt[j] = (ALL * C[j] % mod - cur[j]) * fy(len[i], j) % mod;
		memset(cur, 0, (len[i - 1] + 1) << 2);
	}
	ALL = BLL % mod;
	printf("%lld\n", ALL + (ALL >> 63 & mod));
	return 0;
}