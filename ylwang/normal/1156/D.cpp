#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
struct Edge {
	int v, w, nxt;
}e[MAXN << 1];
int lst[MAXN], tot = 0;
inline void addedge(int u, int v, int w){
	e[++tot] = (Edge) {v, w, lst[u]};
	lst[u] = tot;
}
int n, f[MAXN], //1 
    g[MAXN]; //0
int nowf[MAXN], nowg[MAXN];
ll ans = 0;
void dfs1(int u, int fa) {
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v == fa) continue;
		dfs1(v, u);
		if(!e[i].w) g[u] += g[v] + 1;
		else f[u] += f[v] + g[v] + 1;
	}
}
void dfs2(int u, int fa) {
	ans += nowf[u] + nowg[u];
	for(int i = lst[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v != fa) {
			if(!e[i].w) nowf[v] = f[v], nowg[v] = nowg[u];
			else nowf[v] = (nowf[u] - g[v]) + nowg[u], nowg[v] = g[v];
			dfs2(v, u);
		}
	}
}
signed main()
{
	n = read();
	For(i, 1, n-1) {
		int u = read(), v = read(), w = read();
		addedge(u, v, w);
		addedge(v, u, w);
	}
	dfs1(1, -1);
	nowf[1] = f[1], nowg[1] = g[1];
	dfs2(1, -1);  
	cout << ans << endl;
    return 0;
}