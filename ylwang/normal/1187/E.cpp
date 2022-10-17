#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 400005
struct Edge {
	int v, nxt;
}e[MAXN];
int lst[MAXN], tot = 0, n;
inline void addedge(int u, int v) {
	e[++tot] = (Edge) {v, lst[u]};
	lst[u] = tot;
}
ll dp[MAXN], siz[MAXN], ans = 0;
void dfs1(int u, int fa) {
	siz[u] = 1;
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			dfs1(v, u);
			siz[u] += siz[v];
			dp[u] += dp[v];
		}
	}
	dp[u] += siz[u];
}
void dfs2(int u, int fa) {
//	cout << u << ' ' << dp[u] << endl;
	ans = max(ans, dp[u]);
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			dp[v] = (-siz[v]) + n + (dp[u] - siz[v]);
			dfs2(v, u);
		}
	}
}
signed main()
{
    n = read();
    for(int i = 1; i < n; i++) {
    	int u = read(), v = read();
    	addedge(u, v); addedge(v, u);
	}
	dfs1(1, -1);
//	For(i, 1, n) cout << dp[i] << endl;
	dfs2(1, -1);
	cout << ans << endl;
//	cout << dp[1] << endl;
    return 0;
}