#include<bits/stdc++.h>
using namespace std;
const int N=100100,M=100100,A=10,Inf=1000000;
struct node
{
	int l,r,num[A];
}t[N<<2]={};
int n,m,q,last[N]={},next[N+N]={},end[N+N]={},total_edge=0;
int size[N]={},hson[N]={},top[N]={},w[N]={},fa[N]={},d[N]={},tot=0;
int ans[A+A]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void dfs1(int s,int f)
{
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==f)
			continue;
		fa[j]=s;
		d[j]=d[s]+1;
		dfs1(j,s);
		size[s]+=size[j];
		if(size[j]>size[hson[s]])
			hson[s]=j;
	}
	++size[s];
}
void dfs2(int s,int f)
{
	if(!top[s])
		top[s]=s;
	w[s]=++tot;
	if(hson[s])
	{
		top[hson[s]]=top[s];
		dfs2(hson[s],s);
	}
	for(int i=last[s];i;i=next[i])
		if(end[i]!=f && end[i]!=hson[s])
			dfs2(end[i],s);
}
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
	fill(t[k].num,t[k].num+A,Inf);
}
void add(int p,int v,int k)
{
	if(t[k].l==t[k].r)
	{
		for(int i=0;i<A;++i)
			if(t[k].num[i]==Inf)
			{
				t[k].num[i]=v;
				break;
			}
		return;
	}
	if(t[k<<1].r>=p)
		add(p,v,k<<1);
	else
		add(p,v,(k<<1)|1);
	
	copy(t[k<<1].num,t[k<<1].num+A,ans);
	copy(t[(k<<1)|1].num,t[(k<<1)|1].num+A,ans+A);
	sort(ans,ans+A+A);
	copy(ans,ans+A,t[k].num);
}
void query(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
	{
		copy(t[k].num,t[k].num+A,ans+A);
		sort(ans,ans+A+A);
		return;
	}
	if(t[k<<1].r>=l)
		query(l,r,k<<1);
	if(t[(k<<1)|1].l<=r)
		query(l,r,(k<<1)|1);
}
void print_tree(int k)
{
	if(t[k].l!=t[k].r)
		print_tree(k<<1);
	if(t[k].l!=t[k].r)
		print_tree((k<<1)|1);
	cout<<"l="<<t[k].l<<" r="<<t[k].r<<endl;
	for(int i=0;i<A;++i)
		cout<<t[k].num[i]<<' ';
	cout<<endl;
}
void init()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=2,u,v;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	make_tree(1,n,1);
	for(int i=1,c;i<=m;++i)
	{
		scanf("%d",&c);
		add(w[c],i,1);
	}
}
void work()
{
	for(int i=1,v,u,a;i<=q;++i)
	{
		scanf("%d%d%d",&v,&u,&a);
		fill(ans,ans+A+A,Inf);
		int tu=top[u],tv=top[v];
		while(tu!=tv)
		{
			if(d[tu]<d[tv])
				swap(u,v),swap(tu,tv);
			query(w[tu],w[u],1);
			u=fa[tu];
			tu=top[u];
		}
		if(d[u]<d[v])
			swap(u,v);
		query(w[v],w[u],1);
		int tot=0;
		for(int j=0;j<a;++j)
			tot+=(ans[j]!=Inf);
		printf("%d",tot);
		for(int j=0;j<tot;++j)
			printf(" %d",ans[j]);
		printf("\n");
	}
}
int main()
{	
	init();
	work();
	return 0;
}