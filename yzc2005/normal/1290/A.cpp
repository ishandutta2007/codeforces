
#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define fu(i, a, b) for(rint i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rint i = a, I = (b) - 1; i > I; --i)
#define reset(a) memset(a, 0, sizeof(a))
#define finish(a) a, exit(0)
#define fail puts("NO"), exit(0)
typedef long long ll;
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T> inline void ckmin(T &a, T b) {a = min(a, b);}
 
const int N = 3505;
int t, n, m, k, a[N];
 
int main() {
	rd(t);
	while(t--) {
		rd(n), rd(m), rd(k); --m;
		int ans = 0;
		fu(i, 1, n) rd(a[i]);
		ckmin(k, m);
		fu(x, 0, k) {
			int l = x + 1, r = n - (k - x);
			int val = 0x3f3f3f3f;
			fu(j, 0, m - k) ckmin(val, max(a[l + j], a[r - ((m - k) - j)]));
			ckmax(ans, val);
		}
		printf("%d\n", ans);
	}
	return 0;
}