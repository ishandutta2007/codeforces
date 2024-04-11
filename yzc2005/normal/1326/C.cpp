#include <bits/stdc++.h> 
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PI;
#define fi first
#define se second
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

const int N = 200005, mod = 998244353;
typedef long long ll;
int n, k, a[N], b[N], f[N], s[N];
ll ans;

int main() {
	rd(n), rd(k);
	fu(i, 1, n) rd(a[i]);
	fu(i, 1, k) ans += n - i + 1;
	printf("%lld ", ans);
	int lst = 0;
	f[0] = s[0] = 1;
	fu(i, 1, n) {
		if(a[i] >= n - k + 1) {
			if(!lst) f[i] = 1;
			else f[i] = s[i - 1] - s[lst - 1];
			if(f[i] < 0) f[i] += mod;
			lst = i;
		} else f[i] = f[i - 1];
		s[i] = (s[i - 1] + f[i]) % mod;
	} 
	printf("%d", f[n]);
}