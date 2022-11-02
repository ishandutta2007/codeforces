#include<bits/stdc++.h>
using namespace std;
const int N=100100;
struct query
{
	int x,y;
}a[N]={},b[N]={},c[N]={},d[N]={};
struct event
{
	int type,x,y;
}e[N+N]={};
bool event_cmp(const event &e1,const event &e2)
{
	return e1.x<e2.x || (e1.x==e2.x && e1.type<e2.type);
}
int n,L,W,last[N]={},end[N+N]={},next[N+N]={},w[N+N]={},total_edge=0;
int size[N]={},v[N]={},now=0,tot=0,t[N]={};
bool del[N]={};
long long ans1=0,ans2=0;
inline void add(int pos,int c)
{
	for(int i=pos;i<=n;i+=i&(-i))
		t[i]+=c;
}
inline int sum(int pos)
{
	int s=0;
	for(int i=pos;i;i-=i&(-i))
		s+=t[i];
	return s;
}
void get_query(query *point,query *ask,int m,int c)
{
	int n=0;
	for(int i=1;i<=m;++i)
	{
		e[++n]=(event){1,point[i].y,point[i].x};
		e[++n]=(event){2,ask[i].y,ask[i].x};
	}
	sort(e+1,e+n+1,event_cmp);
	long long s=0;
	for(int i=1;i<=n;++i)
		if(e[i].type==1)
			add(e[i].y,1);
		else
			s+=sum(e[i].y);
	for(int i=1;i<=n;++i)
		if(e[i].type==1)
			add(e[i].y,-1);
	ans2+=c*s;
}
inline void add_edge(int u,int v,int len)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	w[total_edge]=len;
}
void init()
{
	scanf("%d%d%d",&n,&L,&W);
	for(int i=2,u=0,w=0;i<=n;++i)
	{
		scanf("%d%d",&u,&w);
		add_edge(u,i,w),add_edge(i,u,w);
	}
}
int get_core(int s,int f,int S)
{
	size[s]=1;
	bool flag=true;
	int r=0;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(del[j] || j==f)
			continue;
		if(int tmp=get_core(j,s,S))
			r=tmp;
		flag&=size[j]<=S/2;
		size[s]+=size[j];
	}
	if(r)
		return r;
	flag&=(S-size[s])<=S/2;
	return flag ? s : 0;
}
void dfs(int s,int f,int l1,int l2)
{
	if(l1>L || l2>W)
		return;
	++ans1;
	++tot,a[tot]=(query){l1,l2},b[tot]=(query){L-l1,W-l2};
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(del[j] || j==f)
			continue;
		dfs(j,s,l1+1,l2+w[i]);
	}
}
void work(int s,int S)
{
	//cout<<"s="<<s<<" S="<<S<<endl;
	if(S==1)
		return;
	++now;
	int root=get_core(s,0,S),m=0;
	//cout<<"root="<<root<<endl;
	del[root]=true;
	for(int i=last[root];i;i=next[i])
	{
		if(del[end[i]])
			continue;
		tot=0;
		dfs(end[i],root,1,w[i]);
		get_query(a,b,tot,-1);
		for(int j=1;j<=tot;++j)
			++m,c[m]=a[j],d[m]=b[j];
	}
	//cout<<"ans1="<<ans1<<" ans2="<<ans2<<endl;
	get_query(c,d,m,1);
	//cout<<"ans1="<<ans1<<" ans2="<<ans2<<endl;
	for(int i=last[root];i;i=next[i])
		if(!del[end[i]])
			work(end[i],size[end[i]]>size[root] ? S-size[root] : size[end[i]]);
}
int main()
{
	init();
	work(1,n);
	cout<<ans1+ans2/2<<endl;
	return 0;
}