#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int mod = 998244353, N = 200005;
template <class T> inline void addmod(T &a, T b) {a = (a + b) % mod;}
template <class T> inline void mulmod(T &a, T b) {a = 1LL * a * b % mod;}
inline int add(int a, int b) {return (a + b) % mod;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int quickpow(int a, int b) {
    int res = 1;
   while(b) {
    	if(b & 1) mulmod(res, a);
      mulmod(a, a), b >>= 1;
   }
   return res;
}
inline int inv(int x) {return quickpow(x, mod - 2);}
int n, m, fac[N], ans;

inline int C(int n, int m) {
	return mul(mul(fac[n], inv(fac[m])), inv(fac[n - m]));
}

int main() {
	rd(n), rd(m);
	fac[0] = 1;
	fu(i, 1, m) fac[i] = mul(fac[i - 1], i);
	fu(i, 2, n - 1) addmod(ans, C(n - 3, i - 2));
	printf("%d\n", mul(ans, mul(n - 2, C(m, n - 1))));
}