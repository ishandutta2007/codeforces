#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
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

const int N = 100005, K = 7;
int n, m, k, a[N][K + 1], rk[N];
ll f[N][1 << K];

struct node {
	int id, val;
	inline bool operator < (const node &n1) const {
		return val > n1.val;
	}
} b[N];

int main() {
	rd(n), rd(m), rd(k);
	fu(i, 1, n) rd(b[i].val), b[i].id = i;
	sort(b + 1, b + n + 1);
	fu(i, 1, n) rk[b[i].id] = i;
	fu(i, 1, n) fu(j, 1, m) rd(a[rk[i]][j]); 
	fu(i, 1, n) {
		fu(mask, 0, (1 << m) - 1) {
			int mask1 = mask;
			if(i > __builtin_popcount(mask) && i - __builtin_popcount(mask) <= k) f[i][mask] = f[i - 1][mask] + b[i].val;
			else f[i][mask] = f[i - 1][mask];  
			while(mask1) {
				ckmax(f[i][mask], f[i - 1][mask ^ (mask1 & -mask1)] + a[i][__builtin_ffs(mask1)]);
				mask1 -= mask1 & -mask1;
			}
		}
	}
	printf("%lld\n", f[n][(1 << m) - 1]);
	return 0;
}