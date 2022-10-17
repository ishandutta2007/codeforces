#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
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
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

int n, k, a, cnt[N], f[N][N], bg[N], tot[N];

int main() {
	rd(n);
	fu(i, 1, n) rd(a), ckmax(k, a), ++cnt[a];
	fu(i, 2, k) {
		fu(j, 2, i - 1) f[i][j] = f[i - 1][j];
		int x = i;
		for(int j = 2; j * j <= i; ++j) 
			while(x % j == 0) {
				++f[i][j];
				x /= j;
			} 
		if(x > 1) ++f[i][x];
	}
	ll ans = 0;
	fu(i, 1, k) fu(j, 2, i) ans += 1ll * f[i][j] * cnt[i];
	fu(i, 1, k) fd(j, i, 2) if(f[i][j]) {bg[i] = j; break;} 
	while(*max_element(bg + 1, bg + k + 1)) {
		memset(tot, 0, sizeof(tot));
		fu(i, 1, k) if(bg[i]) tot[bg[i]] += cnt[i];
		int p = max_element(tot + 2, tot + k + 1) - tot;
		if(tot[p] * 2 <= n) break;
		ans -= tot[p] * 2 - n;
		fu(i, 1, k) {
			if(bg[i] != p) {
				bg[i] = 0;
				continue;
			}
			--f[i][p], bg[i] = 0;
			fd(j, p, 2) if(f[i][j]) {bg[i] = j; break;}
		}
	}
	printf("%lld\n", ans);
	return 0;
}