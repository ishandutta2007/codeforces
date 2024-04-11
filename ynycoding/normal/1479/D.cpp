#include <cstdio>
#include <cstring>
#include <vector>
#include <random>
#include <algorithm>
#define llu unsigned long long
#define pb push_back
using std::vector;
std::mt19937 rnd(114);
const int N=300005, B=30;
int n, q, a[N], bs[N];
int dep[N], sz[N], son[N], up[N], pa[N];
vector<int> e[N];
void dfs(int u, int fa)
{
	dep[u]=dep[fa]+1;
	sz[u]=1;
	pa[u]=fa;
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs1(int u, int fa, int top)
{
	up[u]=top;
	if(son[u]) dfs1(son[u], u, top);
	for(int v:e[u]) if(v!=fa&&v!=son[u])
		dfs1(v, u, v);
}
inline int lca(int x, int y)
{
	while(up[x]!=up[y])
	{
		if(dep[up[x]]<dep[up[y]]) std::swap(x, y);
		x=pa[up[x]];
	}
	if(dep[x]<dep[y]) std::swap(x, y);
	return y;
}
#define ls ch[u][0]
#define rs ch[u][1]
int top, ch[N*B][2], hs[N*B], rt[N];
void ins(int u1, int &u, int l, int r, int p, int v)
{
	u=++top;
	hs[u]=hs[u1]^v;
	ls=ch[u1][0], rs=ch[u1][1];
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid) ins(ch[u1][0], ls, l, mid, p, v);
	else ins(ch[u1][1], rs, mid+1, r, p, v);
}
void pdfs(int u, int fa)
{
	ins(rt[fa], rt[u], 1, n, a[u], bs[a[u]]);
	for(int v:e[u]) if(v!=fa)
		pdfs(v, u);
}
int ru[4];
int ask(int l, int r, int l1, int r1)
{
	int h=0;
	for(int i=0; i<4; ++i) h^=hs[ru[i]];
	if(!h) return -1;
	if(l==r) return l;
	int mid=(l+r)>>1;
	h=0;
	for(int i=0; i<4; ++i) h^=hs[ch[ru[i]][0]];
	int t=-1;
	int tmp[4];
	memcpy(tmp, ru, sizeof(ru));
	if(l1<=mid&&h)
	{
		for(int i=0; i<4; ++i) ru[i]=ch[ru[i]][0];
		t=ask(l, mid, l1, r1);
	}
	if(t==-1&&r1>mid) 
	{
		for(int i=0; i<4; ++i) ru[i]=ch[tmp[i]][1];
		t=ask(mid+1, r, l1, r1);
	}
	return t;
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), bs[i]=rnd();
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	dfs1(1, 0, 1);
	pdfs(1, 0);
//	printf("top %d\n", top);
	for(int i=1, x, y, l, r; i<=q; ++i)
	{
		scanf("%d%d%d%d", &x, &y, &l, &r);
		int lc=lca(x, y);
//		printf("lca %d %d %d\n", x, y, lc);
		ru[0]=rt[x], ru[1]=rt[y], ru[2]=rt[lc], ru[3]=rt[pa[lc]];
		printf("%d\n", ask(1, n, l, r));
	}
	return 0;
}