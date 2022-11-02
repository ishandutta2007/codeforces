#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cctype>
#include<set>
#include<vector>
using namespace std;
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
inline char getalpha()
{
	char ch;
	while(!isalpha(ch=getchar())) ;
	return ch;
}
const int N=100010,M=100010,Inf=1<<30;
struct node
{
	int l,r,minv;
}t[N<<2]={};
int n,m,q,w[N]={},last[N]={},end[M+M]={},next[M+M]={},total_edge=0;
int c[N]={},add[N]={},totc=0,fa[N]={},is_cut[N]={};
int size[N]={},hson[N]={},top[N]={},d[N]={},pos[N]={},rpos[N]={},ptot=0;
multiset<int> minw[N];
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	n=getint(),m=getint(),q=getint();
	for(int i=1;i<=n;++i)
		w[i]=getint();
	for(int i=1,u=0,v=0;i<=m;++i)
	{
		u=getint(),v=getint();
		add_edge(u,v),add_edge(v,u);
	}
}
void Tarjan(int now,int f)
{
	static int dfn[N]={},low[N]={},tot_dfn=0;
	static int s[N]={},top=0;
	dfn[now]=low[now]=++tot_dfn;
	s[++top]=now;
	for(int i=last[now];i;i=next[i])
	{
		int j=end[i];
		if(j==f)
			continue;
		if(!dfn[j])
		{
			Tarjan(j,now);
			if(low[j]>=dfn[now])
			{
				is_cut[now]=true;
				add[++totc]=now;
				while(s[top+1]!=j)
					c[s[top--]]=totc;
				c[now]=totc;
			}
			else
				low[now]=min(low[now],low[j]);
		}
		else
			low[now]=min(low[now],dfn[j]);
	}
}
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
		t[k].minv=min(t[k<<1].minv,t[(k<<1)|1].minv);
	}
	else
		t[k].minv=*minw[rpos[l]].begin();
	t[k].l=l;
	t[k].r=r;
}
void change(int pos,int k)
{
	if(t[k].l==t[k].r)
	{
		t[k].minv=*minw[rpos[pos]].begin();
		return;
	}
	if(t[k<<1].r>=pos)
		change(pos,k<<1);
	else
		change(pos,(k<<1)|1);
	t[k].minv=min(t[k<<1].minv,t[(k<<1)|1].minv);
}
int minv(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].minv;
	int v=Inf;
	if(t[k<<1].r>=l)
		v=min(v,minv(l,r,k<<1));
	if(t[(k<<1)|1].l<=r)
		v=min(v,minv(l,r,(k<<1)|1));
	return v;
}
void Tarjan()
{
	Tarjan(1,0);
	vector<pair<int,int> > e;
	for(int s=1;s<=n;++s)
		for(int i=last[s];i;i=next[i])
			if(c[s]!=c[end[i]])
				e.push_back(make_pair(c[s],c[end[i]]));
	sort(e.begin(),e.end());
	e.erase(unique(e.begin(),e.end()),e.end());
	fill(last+1,last+n+1,0);
	total_edge=0;
	for(int i=e.size()-1;i>=0;--i)
		add_edge(e[i].first,e[i].second);
	for(int i=1;i<=n;++i)
		minw[c[i]].insert(w[i]);
	n=totc;
	make_tree(1,n,1);
}
void dfs1(int s,int f)
{
	size[s]=1;
	fa[s]=f;
	for(int i=last[s];i;i=next[i])
		if(end[i]!=f)
		{
			d[end[i]]=d[s]+1;
			dfs1(end[i],s);
			if(size[end[i]]>size[hson[s]])
				hson[s]=end[i];
			size[s]+=size[end[i]];
		}
}
void dfs2(int s,int f)
{
	pos[s]=++ptot;
	rpos[ptot]=s;
	if(!top[s])
		top[s]=s;
	if(hson[s])
	{
		top[hson[s]]=top[s];
		dfs2(hson[s],s);
	}
	for(int i=last[s];i;i=next[i])
		if(end[i]!=f && end[i]!=hson[s])
			dfs2(end[i],s);
}
void HLD()
{
	dfs1(c[1],0);
	dfs2(c[1],0);
	make_tree(1,n,1);
}
int calc(int a,int b)
{
	if(a==b)
		return w[a];
	int x=c[a],y=c[b];
	if(d[x]>d[y])
		swap(x,y),swap(a,b);
	if(x==y)
		return min(*minw[x].begin(),w[add[x]]);
	int ans=Inf,tx=top[x],ty=top[y],cx=is_cut[a]*a,cy=is_cut[b]*b;
	while(tx!=ty)
	{
		if(d[tx]<d[ty])
			swap(x,y),swap(tx,ty),swap(cx,cy);
		ans=min(ans,minv(pos[tx],pos[x],1));
		cx=add[tx];
		x=fa[tx];
		tx=top[x];
	}
	if(d[x]>d[y])
		swap(x,y),swap(cx,cy);
	if(d[x]<d[y])
		ans=min(ans,minv(pos[x]+1,pos[y],1)),y=rpos[pos[x]+1],cy=add[y];
	if(cx==cy)
		ans=min(ans,w[cx]);
	else
		ans=min(ans,min(*minw[x].begin(),w[add[x]]));
	return ans;
}
void query()
{
	for(int i=1;i<=q;++i)
	{
		if(getalpha()=='C')
		{
			int x=getint(),y=getint();
			minw[c[x]].erase(minw[c[x]].find(w[x]));
			minw[c[x]].insert(w[x]=y);
			change(pos[c[x]],1);
		}
		else
		{
			int a=getint(),b=getint();
			printf("%d\n",calc(a,b));
		}
	}
}
int main()
{	
	init();
	Tarjan();
	HLD();
	query();
	return 0;
}