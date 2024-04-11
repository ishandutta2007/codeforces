#include<bits/stdc++.h>
#define N 200100
using namespace std;

int n;
bool A,B;
vector<int>ans[2];
struct Tree
{
    int tt,son[N],top[N],fa[N],deep[N],in[N];
    bool gg[N];
    struct Node
    {
	int ls,rs;
	vector<int>num;
    }node[N<<1];
    vector<int>to[N];
    void add(int u,int v){to[u].push_back(v);}
    int dfs(int now)
    {
	int i,t,tmp,res=1,mx=0;
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    fa[t]=now;
	    deep[t]=deep[now]+1;
	    res+=tmp=dfs(t);
	    if(tmp>mx)
	    {
		mx=tmp;
		son[now]=t;
	    }
	}
	return res;
    }
    void Dfs(int now)
    {
	int i,t;
	in[now]=++tt;
	if(son[now])
	{
	    top[son[now]]=top[now];
	    Dfs(son[now]);
	}
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    if(t==son[now]) continue;
	    top[t]=t;
	    Dfs(t);
	}
    }
    void build(int now,int l,int r)
    {
	if(l==r) return;
	int mid=((l+r)>>1);
	node[now].ls=++tt;
	build(tt,l,mid);
	node[now].rs=++tt;
	build(tt,mid+1,r);
    }
    void add(int now,int l,int r,int u,int v,int w)
    {
	if(u<=l&&r<=v)
	{
	    node[now].num.push_back(w);
	    return;
	}
	int mid=((l+r)>>1);
	if(u<=mid) add(node[now].ls,l,mid,u,v,w);
	if(mid<v) add(node[now].rs,mid+1,r,u,v,w);
    }
    void del(int now,int l,int r,int u)
    {
//	cerr<<now<<' '<<l<<" "<<r<<' '<<u<<" "<<node[now].num.size()<<endl;
	int i,t;
	for(i=0;i<node[now].num.size();i++)
	{
	    t=node[now].num[i];
	    if(!gg[t])
	    {
		gg[t]=1;
		ans[A].push_back(t);
	    }
	}
	node[now].num.clear();
	if(l==r) return;
	int mid=((l+r)>>1);
	if(u<=mid) del(node[now].ls,l,mid,u);
	else del(node[now].rs,mid+1,r,u);
    }
    void pre()
    {
	int i,j;
	deep[1]=top[1]=1;
	dfs(1);
	Dfs(1);
//	for(i=1;i<=n;i++) cout<<top[i]<<" ";puts("");
//	for(i=1;i<=n;i++) cout<<fa[i]<<" ";puts("");puts("");
	build(tt=1,1,n);
    }
    void ad(int u,int v,int w)
    {
	for(;top[u]!=top[v];)
	{
	    if(deep[top[u]]<deep[top[v]]) swap(u,v);
	    add(1,1,n,in[top[u]],in[u],w);
	    u=fa[top[u]];
	}
	if(deep[u]>deep[v]) swap(u,v);
	if(u!=v) add(1,1,n,in[u]+1,in[v],w);
    }
    void del(int u){del(1,1,n,in[u]);}
}tree[2];

int main()
{
    int i,j,p,q;
    cin>>n;
    for(i=2;i<=n;i++) scanf("%d",&p),tree[0].add(p,i);
    for(i=2;i<=n;i++) scanf("%d",&p),tree[1].add(p,i);
    tree[0].pre(),tree[1].pre();
    for(i=2;i<=n;i++)
    {
	tree[0].ad(tree[1].fa[i],i,i);
	tree[1].ad(tree[0].fa[i],i,i);
    }
    cin>>p,ans[A=1].push_back(p+1),tree[1].gg[p+1]=1;
    for(i=0;;i^=1)
    {
	swap(A,B);
	puts(i&1?"Red":"Blue");
	sort(ans[B].begin(),ans[B].end());
	for(j=0;j<ans[B].size();j++) printf("%d ",ans[B][j]-1);puts("");
	ans[A].clear();
	for(j=0;j<ans[B].size();j++) tree[i].del(ans[B][j]);
	if(!ans[A].size()) return 0;
    }
}