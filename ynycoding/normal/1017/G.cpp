#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define N 100005
using std::max;
using std::vector;
int n, q, in[N], out[N], son[N], up[N], fa[N], cnt;
vector<int> e[N];
int dfs1(int u)
{
	int mx=0, ret=1;
	for(int v:e[u])
	{
		int sz=dfs1(v);
		sz>mx?mx=sz, son[u]=v:0;
		ret+=sz;
	}
	return ret;
}
void dfs2(int u, int top)
{
	in[u]=++cnt;
	up[u]=top;
	if(son[u]) dfs2(son[u], top);
	for(int v:e[u]) if(v!=son[u]) dfs2(v, v);
	out[u]=cnt;
}
namespace tree{
	#define lid (id<<1)
	#define rid (id<<1|1)
	int sz[N<<2], sum[N<<2], rmx[N<<2], tag[N<<2];
	void reset(int id) { sum[id]=-sz[id], tag[id]=1, rmx[id]=-1; }
	void pushdown(int id) { if(tag[id]) reset(lid), reset(rid), tag[id]=0; }
	void update(int id) { sum[id]=sum[lid]+sum[rid], rmx[id]=max(rmx[rid], sum[rid]+rmx[lid]); }
	void build(int id, int l, int r)
	{
		sz[id]=r-l+1;
		if(l==r) { rmx[id]=sum[id]=-1; return; }
		int mid=(l+r)>>1;
		build(lid, l, mid), build(rid, mid+1, r);
		update(id);
	}
	void modify(int id, int l, int r, int p, int v)
	{
		if(l==r) { sum[id]+=v, rmx[id]=sum[id]; return; }
		pushdown(id);
		int mid=(l+r)>>1;
		if(p<=mid) modify(lid, l, mid, p, v); else modify(rid, mid+1, r, p, v);
		update(id);
	}
	void reset(int id, int l, int r, int lp, int rp)
	{
		if(l==lp&&r==rp) { reset(id); return; }
		pushdown(id);
		int mid=(l+r)>>1;
		if(rp<=mid) reset(lid, l, mid, lp, rp);
		else if(lp>mid) reset(rid, mid+1, r, lp, rp);
		else reset(lid, l, mid, lp, mid), reset(rid, mid+1, r, mid+1, rp);
		update(id);
	}
	int askr(int id, int l, int r, int lp, int rp, int &sm)
	{
		if(l==lp&&r==rp) return sm=sum[id], rmx[id];
		pushdown(id);
		int mid=(l+r)>>1;
		if(rp<=mid) return askr(lid, l, mid, lp, rp, sm);
		else if(lp>mid) return askr(rid, mid+1, r, lp, rp, sm);
		else
		{
			int ls=0, rs=0;
			int sr=askr(rid, mid+1, r, mid+1, rp, rs);
			int sl=askr(lid, l, mid, lp, mid, ls);
			sm=ls+rs;
			int ret=max(sr, sl+rs);
			return ret;
		}
	}
}
using namespace tree;
int query(int u)
{
	int cur=0, ret=-0x3f3f3f3f, tmp;
	while(u) ret=max(cur+askr(1, 1, n, in[up[u]], in[u], tmp), ret), cur+=tmp, u=fa[up[u]];
	return ret;
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i=2, x; i<=n; ++i) scanf("%d", &x), e[x].pb(i), fa[i]=x;
	build(1, 1, n);
	dfs1(1);
	dfs2(1, 1);
	for(int i=1, t, v; i<=q; ++i)
	{
		scanf("%d%d", &t, &v);
		if(t==1) modify(1, 1, n, in[v], 1);
		if(t==2) reset(1, 1, n, in[v], out[v]), modify(1, 1, n, in[v], -query(v)-1);
		if(t==3) puts(query(v)<0?"white":"black");
	}
	return 0;
}