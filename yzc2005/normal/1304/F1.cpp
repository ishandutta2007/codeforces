#include <bits/stdc++.h>
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
using namespace std;
const int N = 50 + 5, M = 2e4 + 5;

inline void ckmax(int &a, int b) {a = max(a, b);}
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
int n, m, k, a[N][M], s[N][M], f[N][M], g[M][2], qu[M], l, r, ans;

int main() {
	rd(n), rd(m), rd(k);
	fu(i, 1, n) fu(j, 1, m) rd(a[i][j]), s[i][j] = s[i][j - 1] + a[i][j];
	fu(i, 2, n + 1) {
		l = 1, r = 0;
		fu(j, k, m) {
			f[i][j] = g[j - k][0] + s[i - 1][j] - s[i - 1][j - k];
			while(l <= r && qu[l] <= j - k) ++l;
			while(l <= r && f[i - 1][j] - s[i - 1][j] >= f[i - 1][qu[r]] - s[i - 1][qu[r]]) --r;
			qu[++r] = j;
			if(l <= r) ckmax(f[i][j], f[i - 1][qu[l]] + s[i - 1][j] - s[i - 1][qu[l]]);
		}
		l = 1, r = 0;
		fd(j, m, k) {
			ckmax(f[i][j], (j + k <= m ? g[j + k][1] : 0) + s[i - 1][j] - s[i - 1][j - k]);
			while(l <= r && qu[l] >= j + k) ++l;
			while(l <= r && f[i - 1][j] + s[i - 1][j - k] >= f[i - 1][qu[r]] + s[i - 1][qu[r] - k]) --r;
			qu[++r] = j;
			if(l <= r) ckmax(f[i][j], f[i - 1][qu[l]] + s[i - 1][qu[l] - k] - s[i - 1][j - k]);
		}
		fu(j, k, m) f[i][j] += s[i][j] - s[i][j - k];
		fu(j, k, m) g[j][0] = max(f[i][j], g[j - 1][0]);
		fd(j, m, k) g[j][1] = max(f[i][j], g[j + 1][1]);
	}
	fu(j, k, m) ckmax(ans, f[n + 1][j]);
	return printf("%d\n", ans), 0;	
}