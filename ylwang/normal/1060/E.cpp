#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long

//#define int long long

using namespace std;
inline int read() {
    int num = 0, flag = 1; char c=' '; 
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
int n;
#define MAXN 1000005
struct Edge {
	int v, nxt;
}e[MAXN << 1];
int lst[MAXN], tot;
inline void addedge(int u, int v) {
	e[++tot] = (Edge) {v, lst[u]};
	lst[u] = tot;
}
ll dp[MAXN];
int dis1[MAXN], dis2[MAXN];
void dfs1(int u, int fa) {
	dis2[u] = 1;
	for(register int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			dfs1(v, u);
			dis1[u] += dis2[v];
			dis2[u] += dis1[v];
			dp[u] += (dp[v] + dis2[v]);
		}
	}
}
ll ans = 0;
void dfs2(int u, int fa) {
	ans += dp[u];
	for(register int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			dp[v] = (dp[u] - dis2[v] + dis2[u] - dis1[v]);
			dis1[v] = dis2[u];
			dis2[v] = dis1[u];
			dfs2(v, u);
		}
	}
}
signed main()
{
    n = read();
    For(i, 1, n-1) {
    	int u = read(), v = read();
    	addedge(u, v); addedge(v, u);
	}
	dfs1(1, -1);
	dfs2(1, -1);
	cout << ans / 2 << endl;
    return 0;
}