// luogu-judger-enable-o2
#include <bits/stdc++.h>

typedef std::complex<double> cpd;

const int kMaxN = 8e5 + 5;
const double kPi = acos(-1);

int n, x, s[kMaxN], rev[kMaxN];
cpd f[kMaxN], g[kMaxN];

void Convolution(cpd p[], int len, int sign) {
	for(int i = 1; i < len; ++i)
		if(i < rev[i]) std::swap(p[i], p[rev[i]]);
	for(int i = 1; i < len; i <<= 1) {
		cpd ur(cos(kPi / i), sign * sin(kPi / i));
		for(int j = 0; j < len; j += (i << 1)) {
			cpd tmp(1, 0);
			for(int k = 0; k < i; k++, tmp *= ur) {
				cpd pr = p[i + j + k], pl = p[j + k];
				p[j + k] = pl + tmp * pr;
				p[i + j + k] = pl - tmp * pr;
			}
		}
	}
}

int main() {
	int cnt = 0; long long ans0 = 0;
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; ++i) {
		int u;
		scanf("%d", &u);
		s[i] = s[i - 1] + (u < x);
		f[s[i]] += 1;
		if(s[i] == s[i - 1]) ++cnt;
		else ans0 += 1LL * (cnt - 1) * cnt / 2 + cnt, cnt = 0;
	}
	ans0 += 1LL * (cnt - 1) * cnt / 2 + cnt;
	f[0] += 1;
	for(int i = 0; i <= n; ++i) g[i] = f[n - i];
	int len = 1, max_bit = 0;
	for(n <<= 1; len <= n; len <<= 1, ++max_bit);
	for(int i = 1; i < len; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (max_bit - 1));
	Convolution(f, len, 1); Convolution(g, len, 1);
	for(int i = 0; i < len; ++i) f[i] *= g[i];
	Convolution(f, len, -1);
	printf("%lld ", ans0);
	for(int i = n / 2 + 1; i <= n; ++i)
		printf("%.0lf ", floor(fabs(f[i].real() / len + 0.5)));
	return 0;
}