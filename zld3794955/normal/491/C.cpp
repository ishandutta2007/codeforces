#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int L=200,N=2000020,K=60,S=0,T=110,P=120,E=K*K*2,Inf=0x3f3f3f3f;
int n,k,a[K][K]={},last[P]={},next[E]={},end[E]={},f[E]={},c[E]={};
int total_edge=1;
char buf[L]={},ch[N]={},ch2[N]={};
inline void add_edge(int u,int v,int flow,int cost)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	f[total_edge]=flow;
	c[total_edge]=cost;
}
void init()
{
	gets(buf);
	sscanf(buf,"%d%d",&n,&k);
	gets(ch);
	gets(ch2);
	for(int i=0;i<n;++i)
	{
		int v1=tolower(ch[i])-'a'+(isupper(ch[i]) ? 26 : 0);
		int v2=tolower(ch2[i])-'a'+(isupper(ch2[i]) ? 26 : 0);
		++a[v1][v2];
	}
	for(int i=0;i<k;++i)
		for(int j=0;j<k;++j)
		{
			add_edge(i+1,j+k+1,1,a[i][j]);
			add_edge(j+k+1,i+1,0,-a[i][j]);
		}
	for(int i=0;i<k;++i)
	{
		add_edge(S,i+1,1,0);
		add_edge(i+1,S,0,0);
	}
	for(int i=0;i<k;++i)
	{
		add_edge(i+k+1,T,1,0);
		add_edge(T,i+k+1,0,0);
	}
}
int spfa()
{
	queue<int> q;
	int dis[P]={},fe[P]={};
	bool in[P]={};
	fill(dis,dis+P,-Inf);
	q.push(S);
	in[S]=true;
	dis[S]=0;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		in[s]=false;
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(f[i] && dis[s]+c[i]>dis[j])
			{
				dis[j]=dis[s]+c[i];
				fe[j]=i;
				if(!in[j])
				{
					in[j]=true;
					q.push(j);
				}
			}
		}
	}
	if(dis[T]==-Inf)
		return 0;
	int pos=T;
	while(pos)
	{
		int i=fe[pos];
		--f[i];
		++f[i^1];
		pos=end[i^1];
	}
	return dis[T]+1;
}
void work()
{
	int ans=0;
	while(int tmp=spfa())
		ans+=tmp-1;
	cout<<ans<<endl;
	for(int s=1;s<=k;++s)
		for(int i=last[s];i;i=next[i])
			if(f[i]==0)
			{
				int tmp=end[i]-k-1;
				if(tmp>=26)
					cout<<char(toupper('a'+tmp-26));
				else
					cout<<char('a'+tmp);
			}
	cout<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}