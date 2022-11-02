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
const int N=1010,K=8;
int n,k,a[K][N]={},w[N][K]={},to[N]={},dis[N]={};
int last[N]={},end[N*N]={},next[N*N]={},total_edge=0;
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	++to[v];
}
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
}
void work()
{
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
			w[a[i][j]][i]=j;/*
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=k;++j)
			cout<<w[i][j]<<' ';
		cout<<endl;
	}*/
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			int type=w[i][1]>w[j][1] ? 1 : -1;
			for(int x=2;x<=k && type;++x)
			{
				if(w[i][x]>w[j][x] && type<0)
					type=0;
				if(w[i][x]<w[j][x] && type>0)
					type=0;
			}
			if(type>0)
			{
				add_edge(j,i);
				//cout<<"u="<<j<<" v="<<i<<endl;
			}
			if(type<0)
			{
				add_edge(i,j);
				//cout<<"u="<<i<<" v="<<j<<endl;
			}
		}
}
void get_ans()
{
	queue<int>q;
	for(int i=1;i<=n;++i)
		if(to[i]==0)
		{
			q.push(i);
			dis[i]=1;
		}
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			dis[j]=max(dis[j],dis[s]+1);
			if((--to[j])==0)
				q.push(j);
		}
	}
	printf("%d\n",*max_element(dis+1,dis+n+1));
}
int main()
{	
	init();
	work();
	get_ans();
	return 0;
}