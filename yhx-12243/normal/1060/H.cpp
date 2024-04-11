#include <bits/stdc++.h>

const int N = 13, MUL = 2999, ZERO = 4999, ONE = 4997;

typedef long long ll;

int d, p;
int C[N][N];
int m[N][N], b[N];
int buf[5555];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % p) if (n & 1) c = c * a % p; return c;}

inline void add(int x, int y, int z) {printf("+ %d %d %d\n", x, y, z); /*buf[z] = (buf[x] + buf[y]) % p;*/}
inline void Pow(int x, int y) {printf("^ %d %d\n", x, y); /*buf[y] = PowerMod(buf[x], d);*/}
inline void fin(int x) {printf("f %d\n", x); /*fprintf(stderr, "buf[%d] = %d\n", x, buf[x]);*/}
inline void zero(int x) {add(ZERO - 1, ZERO, x);}

void mul(int x, int c, int y) {
	zero(y); add(x, ZERO, MUL);
	for (; c; c >>= 1) {
		if (c & 1) add(y, MUL, y);
		add(MUL, MUL, MUL);
	}
}

void init() {
	int c = p - 1, n = 5000;
	for (; c; c >>= 1) {
		if (c & 1) add(n - 1, n, n - 1), add(n - 2, n, n - 2);
		add(n, n, n);
	}
}

inline void get_pow(int x, int y) {
	if (d == 2) return Pow(x, y);
	int i; add(x, ZERO, 10);
	for (i = 0; i < d; ++i) add(10 + i, ONE, 11 + i);
	for (i = 0; i <= d; ++i) Pow(10 + i, 21 + i);
	for (i = 0; i <= d; ++i) mul(21 + i, b[i], 32 + i);
	for (i = 0; i < d; ++i) add(32, 33 + i, 32);
	add(32, ZERO, y);
}

void gauss() {
	int i, j, k; ll coe;
	for (*C[0] = i = 1; i <= d; ++i)
		for (*C[i] = j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
	for (i = 0; i <= d; ++i)
		for (j = 0; j <= d; ++j)
			m[i][j] = PowerMod(j, d - i, C[d][i]);
	b[2] = 1;
	for (k = 0; k <= d; ++k) {
		for (i = k; i <= d; ++i) if (m[i][k]) break;
		if (i != k) {
			std::swap(b[i], b[k]);
			for (j = 0; j <= d; ++j) std::swap(m[i][j], m[k][j]);
		}
		coe = PowerMod(m[k][k], p - 2);
		for (j = 0; j <= d; ++j) m[k][j] = m[k][j] * coe % p;
		b[k] = b[k] * coe % p;
		for (i = 0; i <= d; ++i) {
			if (i == k) continue;
			coe = m[i][k];
			for (j = 0; j <= d; ++j)
				m[i][j] = (m[i][j] - coe * m[k][j]) % p,
				m[i][j] += m[i][j] >> 31 & p;
			b[i] = (b[i] - coe * b[k]) % p;
			b[i] += b[i] >> 31 & p;
		}
	}
}

int main() {
	buf[1] = 4; buf[2] = 5; for (int i = 3; i <= 5000; ++i) buf[i] = 1;
	scanf("%d%d", &d, &p); init();
	if (d > 2) gauss();
	add(1, 2, 3), get_pow(1, 4), get_pow(2, 5), get_pow(3, 6);
	mul(4, p - 1, 7), mul(5, p - 1, 8);
	add(6, 7, 6), add(6, 8, 6);	
	mul(6, (p + 1) / 2, 9);
	fin(9);
	return 0;
}