#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long

#define int long long

using namespace std;
inline int read() {
    int num = 0, flag = 1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 600005
int n = 0, a[MAXN];
struct Edge {
	int v, w, nxt;
}e[MAXN];
int lst[MAXN], tot = 0;
inline void addedge(int u, int v, int w) {
	e[++tot] = (Edge) {v, w, lst[u]};
	lst[u] = tot;
}
int ans = 0;
int dp[MAXN][2];

void dfs(int u, int fa) {
	dp[u][0] = dp[u][1] = a[u];
	int maxi1 = 0, maxi2 = 0;
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			dfs(v, u);
			maxi1 = max(maxi1, dp[v][0] - e[i].w);
		}
	}
//	cout << u << ' ' << fa << endl;
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa)
			if(dp[v][0]-e[i].w < maxi1 && dp[v][0]-e[i].w > maxi2)
				maxi2 = dp[v][0] - e[i].w;
	}
	dp[u][0] = maxi1 + a[u];
	dp[u][1] = maxi2 + maxi1 + a[u];
	ans = max(ans, max(dp[u][0], dp[u][1]));
}
signed main()
{
    n = read();
    For(i, 1, n) a[i] = read();
    For(i, 1, n-1) {
    	int u = read(), v = read(), w = read();
    	addedge(u, v, w); addedge(v, u, w);
	}
	dfs(1, -1);
	cout << ans << endl;
    return 0;
}