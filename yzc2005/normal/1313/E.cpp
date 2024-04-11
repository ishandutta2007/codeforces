#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a; i <= b; ++i)
#define fd(i, a, b) for(int i = a; i >= b; --i)
inline void rd(int &x) {
    x = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}

const int N = 500005;
int n, m, za[N], zb[N], zc[N * 3];
char a[N], b[N], c[N * 3];
long long ans;

struct BIT {
	long long s[N << 1];
	inline void add(int p, int v) {
		if(!p) return; 
		for(; p <= m; p += p & -p) s[p] += v;
	}
	inline long long query(int p) {
		long long res = 0; 
		for(; p; p -= p & -p) res += s[p]; 
		return res;
	}
	inline long long query(int l, int r) {
		return query(r) - query(l - 1);
	} 
} bit1, bit2;

inline void Z_algorithm(char a[], int z[]) {
	for(int i = 1, j = m + 1; i <= n; ++i, ++j) c[j] = a[i];
	zc[1] = m + n;
	for(int i = 2, r = 0, l = 0; i <= m + n; ++i) {
		zc[i] = 0;
		if(i <= r) zc[i] = min(r - i + 1, zc[i - l + 1]);
		while(i + zc[i] <= m + n && c[i + zc[i]] == c[zc[i] + 1]) ++zc[i];
		if(i + zc[i] - 1 > r) r = i + zc[i] - 1, l = i;
	}
	for(int i = 1, j = m + 1; i <= n; ++i, ++j) z[i] = min(zc[j], m - 1);	
} 

int main() {
	rd(n), rd(m);
	scanf("%s%s%s", a + 1, b + 1, c + 1);
	Z_algorithm(a, za); 
	reverse(c + 1, c + m + 1), reverse(b + 1, b + n + 1);
	Z_algorithm(b, zb), reverse(zb + 1, zb + n + 1);
	fu(i, 1, min(m - 1, n)) bit1.add(zb[i], 1), bit2.add(zb[i], zb[i]);
	fu(i, 1, n) {
		if(za[i]) ans += bit2.query(m - za[i], m) - bit1.query(m - za[i], m) * (m - za[i] - 1);
		bit1.add(zb[i], -1), bit2.add(zb[i], -zb[i]);
		if(i + m - 1 <= n) bit1.add(zb[i + m - 1], 1), bit2.add(zb[i + m - 1], zb[i + m - 1]);
	} 
	printf("%lld\n", ans);
	return 0;
}