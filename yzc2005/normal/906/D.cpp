#include <bits/stdc++.h> 
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 1e5 + 5;
int n, p, T, a[N], l, r;
map <int, int> phi;

inline void prework(int p) {
	phi[p] = p;
	if(p == 1) return;
	int x = p;
	fu(i, 2, sqrt(p)) {
		if(!(x % i)) {
			phi[p] = phi[p] / i * (i - 1);
			while(!(x % i)) x /= i; 
		}
	}
	if(x > 1) phi[p] = phi[p] / x * (x - 1);
	prework(phi[p]);
} 

inline int getmod(long long a, int b) {
	return a >= b ? a % b + b : a % b;
}

inline int qpow(int a, int b, int p) {
	int res = 1;
	while(b) {
		if(b & 1) res = getmod(1LL * res * a, p);
		a = getmod(1LL * a * a, p), b >>= 1; 
	}
	return res;
}

int solve(int l, int r, int p) {
	if(p == 1 || l == r) return getmod(a[l], p);
	return qpow(a[l], solve(l + 1, r, phi[p]), p);
}

int main() {
	rd(n), rd(p); fu(i, 1, n) rd(a[i]);
	for(rd(T), prework(p); T; --T) rd(l), rd(r), printf("%d\n", solve(l, r, p) % p);
	return 0;
}