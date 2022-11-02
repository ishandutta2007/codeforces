#include<bits/stdc++.h>
using namespace std;
const int N=300300,C=26;
const long long mod=233333333333333ll,Base=233;
struct node
{
	int s[C+1],size,w;
}t[N]={};
int n,c[N]={},last[N]={},next[N+N]={},end[N+N]={},total_edge=0;
int ans1=0,ans2=0,root[N]={},tot=0;
char ch[N]={};
void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	scanf("\n%s\n",ch+1);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
}
void merge(int &r1,int &r2)
{
	if(r1==0)
	{
		r1=r2;
		return;
	}
	if(r2==0)
		return;
	t[r1].size=1;
	for(int i=1;i<=C;++i)
	{
		merge(t[r1].s[i],t[r2].s[i]);
		t[r1].size+=t[t[r1].s[i]].size;
	}
}
void dfs(int s)
{
	cout<<"w="<<t[s].w<<" size="<<t[s].size<<endl;
	for(int i=1;i<=C;++i)
		if(t[s].s[i])
			dfs(t[s].s[i]);
}
void tryy(int s,int f)
{
	root[s]=++tot;
	t[root[s]].size=1;
	t[root[s]].w=ch[s]-'a'+1;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==f)
			continue;
		tryy(j,s);
		merge(t[root[s]].s[ch[j]-'a'+1],root[j]);
	}
	t[root[s]].size=1;
	for(int i=1;i<=C;++i)
		t[root[s]].size+=t[t[root[s]].s[i]].size;
	int v=c[s]+t[root[s]].size;
	if(v>ans1)
		ans1=v,ans2=0;
	if(v==ans1)
		++ans2;
}
void work()
{
	tryy(1,0);
	printf("%d\n%d\n",ans1,ans2);
}
int main()
{	
	init();
	work();
	return 0;
}