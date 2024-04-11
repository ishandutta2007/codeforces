#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=100010;
struct node
{
	int l,r,lazy,s;
}t[N<<2]={};
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
	}
	t[k].l=l;
	t[k].r=r;
	t[k].lazy=t[k].s=0;
}
void update(int k)
{
	if(t[k].lazy)
		t[k].s=t[k].r-t[k].l+1;
	else
		if(t[k].l==t[k].r)
			t[k].s=0;
		else
			t[k].s=t[k<<1].s+t[(k<<1)|1].s;
}
void add(int l,int r,int c,int k)
{
	if(t[k].l>=l && t[k].r<=r)
	{
		t[k].lazy+=c;
		return update(k);
	}
	if(t[k<<1].r>=l)
		add(l,r,c,k<<1);
	if(t[(k<<1)|1].l<=r)
		add(l,r,c,(k<<1)|1);
	update(k);
}
int query(int p,int k)
{
	if(t[k].lazy)
		return 1;
	if(t[k].l==t[k].r)
		return 0;
	return t[k<<1].r>=p ? query(p,k<<1) : query(p,(k<<1)|1);
}
struct event
{
	int x,l,r,c;
}e[M<<3]={};
bool event_cmp(const event &e1,const event &e2)
{
	return e1.x<e2.x;
}
int n,m,q,last[N]={},next[N+N]={},end[N+N]={},total_edge=0;
int l[N]={},r[N]={},tot=0,ans[N]={};
void dfs(int s,int f)
{
	l[s]=++tot;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==f)
			continue;
		dfs(j,s);
	}
	r[s]=tot;
}
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=2,u,v;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	dfs(1,0);
	make_tree(1,n,1);
	for(int i=1,a,b;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		e[++q]=(event){l[b],l[a],r[a],1};
		e[++q]=(event){r[b]+1,l[a],r[a],-1};
		e[++q]=(event){l[a],l[b],r[b],1};
		e[++q]=(event){r[a]+1,l[b],r[b],-1};
		e[++q]=(event){l[a],l[a],r[a],1};
		e[++q]=(event){r[a]+1,l[a],r[a],-1};
		e[++q]=(event){l[b],l[b],r[b],1};
		e[++q]=(event){r[b]+1,l[b],r[b],-1};
	}
	sort(e+1,e+q+1,event_cmp);
}
void work()
{
	int pos=1;
	for(int i=1;i<=n;++i)
	{
		while(pos<=q && e[pos].x==i)
		{
			add(e[pos].l,e[pos].r,e[pos].c,1);
			++pos;
		}
		ans[i]=t[1].s-query(i,1);
	}
	for(int i=1;i<=n;++i)
		printf("%d ",ans[l[i]]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}