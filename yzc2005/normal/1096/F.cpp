#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, a[N], s[N], tot, ans, ans1, ans2;

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

struct BIT {
	int t[N];
	inline void add(int p) {
		for(; p <= n; p += p & -p) ++t[p];
	} 
	inline int query(int p) {
		int res = 0;
		for(; p; p -= p & -p) res += t[p];
		return res;
	}
} bit;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(~a[i]) {
			s[a[i]] = 1;
			add(ans, bit.query(n) - bit.query(a[i]));
			bit.add(a[i]);
		} else {
			++tot;
		}
	}	
	ans1 = (1ll * tot * (tot - 1) / 2) % mod;
	for(int i = 1; i <= n; ++i) s[i] ^= 1, s[i] += s[i - 1];
	for(int i = 1, cnt = 0; i <= n; ++i) {
		if(~a[i]) add(cnt, s[a[i]]);
		else add(ans2, cnt); 
	} 
	for(int i = n, cnt = 0; i; --i) {
		if(~a[i]) add(cnt, tot - s[a[i]]);
		else add(ans2, cnt);
	}
	ans1 = Mul(Mul(tot, tot - 1), getinv(4));
	mul(ans2, getinv(tot));
	printf("%d\n", Add(ans, Add(ans1, ans2)));
	return 0;
}