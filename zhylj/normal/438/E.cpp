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
const int kN = 5e5 + 5, kMod = 998244353, kg = 3, kgInv = 332748118, k2Inv = 499122177;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % kMod)
		if(b & 1) ret = 1LL * ret * bas % kMod;
	return ret;
}

namespace Poly {

int rev[kN], ur[kN];
int GetRev(int x, int y) {
	ur[0] = 1;
	int len = 1, h_bit = 0;
	for(x += y; len < x; len <<= 1, ++h_bit);
	for(int i = 1; i < len; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h_bit - 1));
	return len;
}
void NTT(int f[], int len, bool flag) {
	for(int i = 0; i < len; ++i)
		if(i < rev[i]) std::swap(f[i], f[rev[i]]);
	for(int i = 1; i < len; i <<= 1) {
		int ur_1 = QPow(flag ? kg : kgInv, (kMod - 1) / (i << 1));
		for(int j = 1; j < i; ++j) ur[j] = 1LL * ur[j - 1] * ur_1 % kMod;
		for(int j = 0; j < len; j += (i << 1)) {
			for(int k = 0; k < i; ++k) {
				int fl = f[j + k], fr = 1LL * f[i + j + k] * ur[k] % kMod;
				f[j + k] = (fl + fr) % kMod;
				f[i + j + k] = (fl - fr + kMod) % kMod;
			}
		}
	}
	if(!flag) {
		int len_inv = QPow(len, kMod - 2);
		for(int i = 0; i < len; ++i)
			f[i] = 1LL * f[i] * len_inv % kMod;
	}
}
int tmp_f[kN];
void Inv(int f[], int f_inv[], int n) {
	if(n == 1) { f_inv[0] = QPow(f[0], kMod - 2); return; }
	Inv(f, f_inv, (n + 1) / 2);
	int len = GetRev(n, n);
	for(int i = 0; i < len; ++i) tmp_f[i] = f[i] * (i < n);
	for(int i = n; i < len; ++i) f_inv[i] = 0;
	NTT(tmp_f, len, true); NTT(f_inv, len, true);
	for(int i = 0; i < len; ++i)
		f_inv[i] = 1LL * f_inv[i] * (2 - 1LL * tmp_f[i] * f_inv[i] % kMod + kMod) % kMod;
	NTT(f_inv, len, false);
	for(int i = n; i < len; ++i) f_inv[i] = 0;
}
int tmp_f_inv[kN];
void Sqrt(int f[], int f_sq[], int n) {
	if(n == 1) { f_sq[0] = 1; return; }
	Sqrt(f, f_sq, (n + 1) / 2);
	Inv(f_sq, tmp_f_inv, n);
	int len = GetRev(n, n);
	for(int i = 0; i < len; ++i) tmp_f[i] = f[i] * (i < n);
	for(int i = n; i < len; ++i)
		f_sq[i] = tmp_f_inv[i] = 0;
	NTT(tmp_f, len, true); NTT(f_sq, len, true); NTT(tmp_f_inv, len, true);
	for(int i = 0; i < len; ++i)
		f_sq[i] = (1LL * f_sq[i] * f_sq[i] + tmp_f[i]) % kMod * tmp_f_inv[i] % kMod * k2Inv % kMod;
	NTT(f_sq, len, false);
	for(int i = n; i < len; ++i) f_sq[i] = 0;
}

};

int n, m, G[kN], G_inv[kN], G_sq[kN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m); ++m;
		int c_mn = m;
		for(int i = 1; i <= n; ++i) {
			int c; rd(c);
			if(c > m) continue;
			if(c < c_mn) c_mn = c;
			G[c] = 1;
		}
		Poly::Inv(G + c_mn, G_inv, c_mn + m);
		G[0] = 1;
		for(int i = 1; i < m; ++i)
			G[i] = 1LL * (kMod - 4) * G[i] % kMod;
		Poly::Sqrt(G, G_sq, c_mn + m);
		G_sq[0] = 0;
		for(int i = 1; i < c_mn + m; ++i)
			G_sq[i] = (kMod - G_sq[i]) % kMod;
		int len = Poly::GetRev(c_mn + m, c_mn + m);
		Poly::NTT(G_sq, len, true); Poly::NTT(G_inv, len, true);
		for(int i = 0; i < len; ++i)
			G_sq[i] = 1LL * G_sq[i] * G_inv[i] % kMod * k2Inv % kMod;
		Poly::NTT(G_sq, len, false);
		for(int i = c_mn + 1; i < c_mn + m; ++i)
			printf("%d\n", G_sq[i]);
	} return 0;
}