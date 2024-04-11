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
#define MAXN 600005
struct Edge {
	int v, nxt;
}e[MAXN];
int lst[MAXN], tot = 0, n;
inline void addedge(int u, int v) {
	e[++tot] = (Edge) {v, lst[u]};
	lst[u] = tot;
}
int opt[MAXN], k, dp[MAXN];
void dfs(int u, int fa) {
	if(e[lst[u]].v == fa || !e[lst[u]].nxt) {
//		cout << "(";
		k++, dp[u] = 1;
		return;
	}
	if(opt[u] == 1) dp[u] = n;
	else dp[u] = 0;
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			dfs(v, u);
			if(opt[u] == 1) dp[u] = min(dp[u], dp[v]);
			else dp[u] += dp[v];
		}
	}
}
signed main()
{
    n = read();
    For(i, 1, n) opt[i] = read();
    for(int u = 2; u <= n; u++) {
    	int v = read();
    	addedge(u, v); addedge(v, u);
	}
	dfs(1, -1);
//	For(i, 1, n) cout << dp[i] << ' ';
	cout << k - dp[1] + 1 << endl;
    return 0;
}