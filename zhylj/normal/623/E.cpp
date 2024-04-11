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
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll A = 998244353, B = 7 * (1 << 26) + 1, C = 1004535809, kMod = 1e9 + 7;

ll QPow(ll a, ll b, ll p) {
	ll ret = 1, bas = a % p;
	for(; b; b >>= 1, bas = bas * bas % p) if(b & 1) ret = ret * bas % p;
	return ret;
}
ll Inv(ll a, ll p) { return QPow(a, p - 2, p); }

int rev[kN];
int GetRev(int x, int y) {
	int len = 1, h_bit = 0;
	for(x += y; len < x; len <<= 1, ++h_bit);
	for(int i = 1; i < len; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h_bit - 1));
	return len;
}
void NTT(ll f[], int len, bool flag, ll p, ll r) {
	if(!flag) r = Inv(r, p);
	for(int i = 0; i < len; ++i) if(i < rev[i])
		std::swap(f[i], f[rev[i]]);
	for(int i = 1; i < len; i <<= 1) {
		ll ur = QPow(r, (p - 1) / (i << 1), p);
		for(int j = 0; j < len; j += (i << 1)) {
			ll bas = 1;
			for(int k = 0; k < i; ++k, bas = bas * ur % p) {
				ll fl = f[j + k], fr = f[i + j + k] * bas % p;
				f[j + k] = (fl + fr) % p;
				f[i + j + k] = (fl - fr + p) % p;
			}
		}
	}
	if(!flag) {
		ll len_inv = Inv(len, p);
		for(int i = 0; i < len; ++i) f[i] = f[i] * len_inv % p;
	}
}
ll tmp[kN];
void PolyMul(ll f[], ll g[], int n, ll p, ll r) {
	memcpy(tmp, g, sizeof(tmp));
	int len = GetRev(n, n);
	NTT(f, len, true, p, r); NTT(tmp, len, true, p, r);
	for(int i = 0; i < len; ++i) f[i] = f[i] * tmp[i] % p;
	NTT(f, len, false, p, r);
	for(int i = n; i < len; ++i) f[i] = 0;
}
ll tmp_f[3][kN];
void PolyMul(ll f[], ll g[], int n) {
	memcpy(tmp_f[0], f, sizeof(tmp_f[0]));
	memcpy(tmp_f[1], f, sizeof(tmp_f[1]));
	memcpy(tmp_f[2], f, sizeof(tmp_f[2]));
	PolyMul(tmp_f[0], g, n, A, 3);
	PolyMul(tmp_f[1], g, n, B, 3);
	PolyMul(tmp_f[2], g, n, C, 3);
	const ll A_inv = Inv(A, B), AB_inv = Inv(A * B, C);
	for(int i = 0; i < n; ++i) {
		ll x = tmp_f[0][i], x1 = tmp_f[1][i], x2 = tmp_f[2][i];
		x = (x + (x1 - x % B + B) % B * A_inv % B * A) % (A * B);
		x = (x + (x2 - x % C + C) % C * AB_inv % C * A % kMod * B % kMod) % kMod;
		f[i] = x;
	}
}

ll F[kN], tmp_F[kN], fac[kN], fac_inv[kN];
void Init(int k) {
	fac[0] = 1;
	for(int i = 1; i <= k; ++i) fac[i] = fac[i - 1] * i % kMod;
	fac_inv[k] = Inv(fac[k], kMod);
	for(int i = k - 1; ~i; --i) fac_inv[i] = fac_inv[i + 1] * (i + 1) % kMod;
}
ll Choose(int n, int m) {
	if(n < m) return 0;
	return fac[n] * fac_inv[m] % kMod * fac_inv[n - m] % kMod;
}
void Add(int n, int k) {
	if(n == 0) {
		for(int i = 1; i <= k; ++i) F[i] = 1;
		F[0] = 0;
	} else {
		ll bas = 1;
		for(int i = 0; i <= k; ++i, bas = bas * 2 % kMod)
			F[i] = F[i] * fac_inv[i] % kMod * bas % kMod;
		for(int i = 1; i <= k; ++i)
			tmp_F[i] = fac_inv[i] % kMod;
		PolyMul(F, tmp_F, k + 1);
		for(int i = 0; i <= k; ++i) F[i] = F[i] * fac[i] % kMod;
		memset(tmp_F, 0, sizeof(tmp_F));
	}
}
void Mov(int n, int k) {
	if(n == 0) return;
	ll bas = 1, t = QPow(2, n, kMod);
	for(int i = 0; i <= k; ++i) F[i] = F[i] * fac_inv[i] % kMod;
	for(int i = 0; i <= k; ++i, bas = bas * t % kMod)
		tmp_F[i] = F[i] * bas % kMod;
	PolyMul(F, tmp_F, k + 1);
	for(int i = 0; i <= k; ++i) F[i] = F[i] * fac[i] % kMod;
	memset(tmp_F, 0, sizeof(tmp_F));
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		int n, k; rd(n, k);
		if(n > k) { printf("0\n"); break; }
		Init(k);
		F[0] = 1;
		int x = 0;
		for(int i = 16; ~i; --i) {
			Mov(x, k); x <<= 1;
			if((n >> i) & 1) {
				Add(x, k); x |= 1;
			}
		}
		ll ans = 0;
		for(int i = 1; i <= k; ++i) {
			ans = (ans + F[i] * Choose(k, i) % kMod) % kMod;
		}
		printf("%lld\n", ans);
	} return 0;
}