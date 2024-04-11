#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
inline void add(int &a, int b) { (a += b) >= mod && (a -= mod); }
inline int Add(int a, int b) { return add(a, b), a; }
inline void sub(int &a, int b) { (a -= b) < 0 && (a += mod); }
inline int Sub(int a, int b) { return sub(a, b), a; }
inline void mul(int &a, int b) { a = 1ll * a * b % mod; }
inline int Mul(int a, int b) { return 1ll * a * b % mod; }
inline int qpow(int a, int b) {
    int res = 1; 
    for(; b; b >>= 1, mul(a, a)) if(b & 1) mul(res, a); 
    return res;
}
inline int getinv(int x) {return qpow(x, mod - 2);}
const int N = 200005; 
int inv[N], fac[N], fac_inv[N];
inline void prework(int n) {
    for(int i = 0; i <= 1; ++i) inv[i] = fac[i] = fac_inv[i] = 1;
    for(int i = 2; i <= n; ++i) fac[i] = Mul(i, fac[i - 1]);
    for(int i = 2; i <= n; ++i) inv[i] = Mul(inv[mod % i], mod - mod / i);
    for(int i = 2; i <= n; ++i) fac_inv[i] = Mul(inv[i], fac_inv[i - 1]); 
}
inline int C(int n, int m) {return Mul(fac[n], Mul(fac_inv[m], fac_inv[n - m]));}

int main() {
	long long n, k;
	cin >> n >> k, prework(n);
	if(k >= n) cout << "0", exit(0);
	if(k == 0) cout << fac[n], exit(0);
	k = n - k; int ans = 0;
	for(int i = 0; i <= k; ++i) {
		if(i & 1) sub(ans, Mul(C(k, i), qpow(k - i, n)));
		else add(ans, Mul(C(k, i), qpow(k - i, n)));
	} 
	cout << Mul(Mul(C(n, k), ans), 2);
	return 0; 
}