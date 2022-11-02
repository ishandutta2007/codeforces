#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n,last[202000]={},end[402000]={},next[402000]={},t[402000]={},total_edge=0;
int q[202000]={},head=0,tail=0,ans=0;
bool b[202000]={},chosen[202000]={},r[202000]={},checked[202000]={};
inline void add_edge(int &u,int &v,int &l)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	t[total_edge]=l;
}
void init()
{
	scanf("%d",&n);
	int u,v,t;
	for(int i=1;i!=n;++i)
	{
		scanf("%d%d%d",&u,&v,&t);
		add_edge(u,v,t);
		add_edge(v,u,t);
	}
}
void bfs()
{
	q[++tail]=1;
	b[1]=true;
	while(head<tail)
		for(int s=q[++head],i=last[s];i;i=next[i])
			if(!b[end[i]])
				q[++tail]=end[i],b[end[i]]=true;
}
void deal()
{
	for(int T=tail;T>=1;--T)
	{
		int s=q[T];
		int f=0;
		bool flag=0;
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(!checked[j])
				continue;
			if(r[j])
			{	
				if(r[s] && t[i]==2)
					chosen[j]=true,++ans;
				flag=true;
			}
			if(!r[j] && t[i]==2)
				chosen[j]=true,++ans,flag=true,r[j]=true;
		}
		r[s]=flag;
		checked[s]=true;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		if(chosen[i])
			printf("%d ",i);
	cout<<endl;
}	
int main()
{	
	init();
	bfs();
	deal();
	return 0;
}