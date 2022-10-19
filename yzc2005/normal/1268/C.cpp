#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

const int N = 2e5 + 5;
int n, a[N], p[N];

struct BIT {
	ll s[N];
	inline void add(int p, int v) {
		while(p <= n) {
			s[p] += v;
			p += p & -p;
		}
	}
	inline ll query(int p) {
		ll res = 0;
		while(p) {
			res += s[p];
			p -= p & -p;
		}
		return res;
	}
	inline int find(ll v) {
		int res = 0;
		fd(k, 17, 0) {
			if((res | (1 << k)) > n) continue;
			if(s[res | (1 << k)] >= v) continue; 
			res |= 1 << k, v -= s[res | (1 << k)];
		} 
		return res + 1;
	}
} b1, b2;

int main() {
	rd(n); fu(i, 1, n) rd(a[i]), p[a[i]] = i;
	ll cnt = 0;
	fu(i, 1, n) {
		cnt += b1.query(n) - b1.query(p[i] - 1);
		b1.add(p[i], 1), b2.add(p[i], p[i]);
		int mid = b1.find((i >> 1) + 1);
		ll s1 = (i >> 1) + 1, s2 = i - s1, s3 = b2.query(mid), s4 = b2.query(n) - s3;
		ll ans = mid * s1 - s1 * (s1 - 1) / 2 - s3 + s4 - mid * s2 - s2 * (s2 + 1) / 2;
		printf("%lld ", cnt + ans);
	}
	return 0;
}