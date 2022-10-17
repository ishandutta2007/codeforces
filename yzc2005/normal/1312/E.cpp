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

const int N = 505;
int n, a[N], w[N][N], g[N];
bool f[N][N], vis[N][N];

void dfs(int l, int r) {
	if(vis[l][r]) return;
	vis[l][r] = 1;
	if(l == r) return w[l][r] = a[l], f[l][r] = 1, void();
	fu(k, l, r - 1) {
		dfs(l, k), dfs(k + 1, r);
		if(f[l][k] && f[k + 1][r] && w[l][k] == w[k + 1][r]) 
			return w[l][r] = w[l][k] + 1, f[l][r] = 1, void();
	}
}

int main() {
	rd(n);
	fu(i, 1, n) rd(a[i]);
	dfs(1, n);
	fu(i, 1, n) {
		g[i] = 1e9;
		fu(j, 1, n) if(f[j][i]) ckmin(g[i], g[j - 1] + 1);
	}
	cout << g[n] << endl;
}