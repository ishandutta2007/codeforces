#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define lg2(x) (31 - __builtin_clz(x))

typedef long long ll;
const int N = 54, M = 108, TM = 20054, INF = 0x3f3f3f3f;
typedef double vec[TM], *pvec;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int V, E, T, cost;
int G[N][N];
vec p[M], sp[M], fv[N], fe[M];
vec f, g, h;

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline void down(double &x, const double y) {x > y ? x = y : 0;}

namespace Poly {
	struct C {
		double r, i;
		C (double real = 0.0, double imag = 0.0) : r(real), i(imag) {}
		inline C operator + (const C &B) const {return C(r + B.r, i + B.i);}
		inline C operator - (const C &B) const {return C(r - B.r, i - B.i);}
		inline C operator * (const C &B) const {return C(r * B.r - i * B.i, r * B.i + i * B.r);}
		inline C operator * (double k) const {return C(r * k, i * k);}
		inline C operator / (double k) const {return *this * (1.0 / k);}
	};

	const int N = 66666;
	int l, n, rev[N];
	C x[N], y[N], B1[N], B2[N], B3[N];

	void FFT_init(int len) {
		if (l == len) return; n = 1 << (l = len);
		int i; double angle = M_PI;
		for (i = l - 1; i >= 0; angle *= .5, --i) x[1 << i] = C(cos(angle), sin(angle));
		for (i = 3; i < n; ++i) if (i & (i - 1)) x[i] = x[i & -i] * x[i ^ (i & -i)];
		*x = C(1.), *rev = 0;
		for (i = 1; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
	}

	void DFT(C *d, C *t) {
		int i, len = 1, delta = n; C *j, *k, R;
		for (i = 0; i < n; ++i) t[rev[i]] = d[i];
		for (i = 0; i < l; ++i) {
			delta >>= 1;
			for (k = x, j = y; j < y + len; k += delta, ++j) *j = *k;
			for (j = t; j < t + n; j += len << 1)
				for (k = j; k < j + len; ++k)
					R = y[k - j] * k[len], k[len] = *k - R, *k = *k + R;
			len <<= 1;
		}
	}

	void Mul(int degA, int degB, double *a, double *b, double *c) {
		if (degA == 0 && degB == 1) {*c = *a * *b, c[1] = *a * b[1]; return;}
		FFT_init(lg2(degA + degB) + 1);
		int i; double iv = 1.0 / n;
		for (i = 0; i <= degA; ++i) B1[i] = C(a[i]); std::fill(B1 + i, B1 + n, C());
		for (i = 0; i <= degB; ++i) B2[i] = C(b[i]); std::fill(B2 + i, B2 + n, C());
		DFT(B1, B3), DFT(B2, B1);
		for (i = 0; i < n; ++i) B1[i] = B1[i] * B3[i];
		DFT(B1, B3), std::reverse(B3 + 1, B3 + n);
		for (i = 0; i <= degA + degB; ++i) c[i] = B3[i].r * iv;
	}
}

void solve(int L, int R) {
	int i, j, M = (L + R + 1) / 2;
	if (L + 1 == R) {
		for (i = 1; i <= V; ++i) fv[i][L] = INFINITY; fv[V][L] = 0.;
		for (i = 0; i < E; ++i) down(fv[ e[i].u ][L], fe[i][L] += (G[ e[i].v ][V] + cost) * (1. - sp[i][L]) + e[i].w);
		return;
	}
	solve(L, M);
	for (i = 0; i < E; ++i) {
		memcpy(f, fv[ e[i].v ] + L, (M - L) << 3);
		memcpy(g, p[i], (R - L) << 3);
		Poly::Mul(M - L - 1, R - L - 1, f, g, h);
		for (j = M; j < R; ++j) fe[i][j] += h[j - L];
	}
	solve(M, R);
}

int main() {
	int i, j, u, v, w;
	scanf("%d%d%d%d", &V, &E, &T, &cost);
	for (i = 1; i <= V; ++i) memset(G[i], 63, (V + 1) << 2), G[i][i] = 0;
	for (i = 0; i < E; ++i) {
		scanf("%d%d%d", &u, &v, &w), e[i] = edge(u, v, w), down(G[u][v], w);
		for (j = 1; j <= T; ++j) scanf("%d", &w), p[i][j] = (double)w * 1e-5;
		std::partial_sum(p[i], p[i] + (T + 1), sp[i]);
	}
	for (i = 1; i <= V; ++i)
		for (u = 1; u <= V; ++u)
			for (v = 1; v <= V; ++v) down(G[u][v], G[u][i] + G[i][v]);
	solve(0, T + 1);
	printf("%.12lg\n", fv[1][T]);
	return 0;
}