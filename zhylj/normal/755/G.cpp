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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kg = 3, kgInv = 332748118, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int rev[kN];
int GetRev(int x, int y) {
	int len = 1, h_bit = 0;
	for(x += y; len < x; len <<= 1, ++h_bit);
	for(int i = 1; i < len; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h_bit - 1));
	return len;
}
void NTT(ll f[], int len, bool flag) {
	for(int i = 0; i < len; ++i) if(i < rev[i])
		std::swap(f[i], f[rev[i]]);
	for(int i = 1; i < len; i <<= 1) {
		ll ur = QPow(flag ? kg : kgInv, (kMod - 1) / (i << 1));
		for(int j = 0; j < len; j += (i << 1)) {
			ll bas = 1;
			for(int k = 0; k < i; ++k, bas = bas * ur % kMod) {
				ll fl = f[j + k], fr = f[i + j + k] * bas % kMod;
				f[j + k] = (fl + fr) % kMod;
				f[i + j + k] = (fl - fr + kMod) % kMod;
			}
		}
	}
	if(!flag) {
		ll len_inv = QPow(len, kMod - 2);
		for(int i = 0; i < len; ++i) f[i] = f[i] * len_inv % kMod;
	}
}

ll f[5][kN]; int k, len;
void Mov() {
	for(int i = 3; i < 5; ++i) {
		f[i][0] = f[i - 1][0];
		for(int j = 1; j <= k; ++j)
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] + f[i - 2][j - 1]) % kMod;
		for(int j = k + 1; j < len; ++j)
			f[i][j] = 0;
	}
	memcpy(f[0], f[2], sizeof(f[0]));
	memcpy(f[1], f[3], sizeof(f[1]));
	memcpy(f[2], f[4], sizeof(f[2]));
}
void Mul() {
	NTT(f[0], len, true); NTT(f[1], len, true); NTT(f[2], len, true);
	for(int i = 0; i < len; ++i) {
		ll f0 = f[0][i], f1 = f[1][i], f2 = f[2][i];
		f[0][i] = f1 * f1 % kMod;
		f[1][i] = f1 * f2 % kMod;
		f[2][i] = f2 * f2 % kMod;
		f[3][i] = f0 * f0 % kMod;
		f[4][i] = f0 * f1 % kMod;
	}
	NTT(f[0], len, false); NTT(f[1], len, false); NTT(f[2], len, false);
	NTT(f[3], len, false); NTT(f[4], len, false);
	for(int i = k; i; --i) {
		f[0][i] = (f[0][i] + f[3][i - 1]) % kMod;
		f[1][i] = (f[1][i] + f[4][i - 1]) % kMod;
		f[2][i] = (f[2][i] + f[0][i - 1]) % kMod;
	}
	for(int i = k + 1; i < len; ++i)
		f[0][i] = f[1][i] = f[2][i] = 0;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		int n, nn; rd(n, k); nn = n + (n & 1);
		len = GetRev(k + 1, k + 1);
		f[0][0] = f[1][0] = f[1][1] = f[2][0] = f[2][2] = 1;
		f[2][1] = 3;
		bool flag = false;
		for(int i = 30; i; --i) {
			if(flag) Mul();
			if((nn >> i) & 1) {
				if(flag) Mov();
				flag = true;
			}
		}
		n = 2 - (n & 1);
		for(int i = 1; i <= k; ++i)
			printf("%lld ", f[n][i]);
		printf("\n");
	} return 0;
}