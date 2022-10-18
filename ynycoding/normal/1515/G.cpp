#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using std::abs;
using std::vector;
const int N=200005;
int n, m, q, x[N], y[N], l[N], vis[N], dfn[N], low[N], stk[N], in[N], cnt, top, ccol, col[N];
ll dis[N], ans[N];
inline ll gcd(ll x, ll y) { while(y) x%=y, std::swap(x, y); return x; }
vector<int> e[N], w[N];
void tarjan(int u)
{
	stk[++top]=u;
	low[u]=dfn[u]=++cnt;
	in[u]=1;
	for(int i=0; i<e[u].size(); ++i)
	{
		int v=e[u][i], c=w[u][i];
		if(!dfn[v])
		{
			dis[v]=dis[u]+c;
			tarjan(v);
			low[u]=std::min(low[u], low[v]);
		}
		else if(in[v]) low[u]=std::min(low[u], dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++ccol;
		while(stk[top+1]!=u) in[stk[top]]=0, col[stk[top--]]=ccol;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d%d", x+i, y+i, l+i);
		e[x[i]].pb(y[i]), w[x[i]].pb(l[i]);
	}
	for(int i=1; i<=n; ++i) if(!dfn[i]) tarjan(i);
	for(int i=1; i<=m; ++i) if(col[x[i]]==col[y[i]])
		ans[col[x[i]]]=gcd(ans[col[x[i]]], abs(dis[x[i]]-dis[y[i]]+l[i]));
	scanf("%d", &q);
	for(int i=1, v, s, t; i<=q; ++i)
	{
		scanf("%d%d%d", &v, &s, &t);
		int x=col[v];
		if(!s||(ans[x]&&s%gcd(t, ans[x])==0)) puts("YES");
		else puts("NO");
	}
	return 0;
}