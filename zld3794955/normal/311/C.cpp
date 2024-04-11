#include<bits/stdc++.h>
using namespace std;
const int M=100010,K=10100,D=25;
const long long Inf=1ll<<60;
int n,m,k,c[M]={},tot=0;
long long h,a[M]={},dis[K]={0},l[D]={};
set<pair<int,int> > now;
void init()
{
	scanf("%I64d%d%d%d",&h,&n,&m,&k);
	fill(dis+1,dis+k,Inf);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d%d",&a[i],&c[i]);
		--a[i];
	}
}
void spfa()
{
	queue<int> q;
	bool in[K]={};
	for(int i=0;i<k;++i)
	{
		q.push(i);
		in[i]=true;
	}
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		in[s]=false;
		for(int i=1;i<=tot;++i)
		{
			long long j=(s+l[i])%k;
			if(dis[s]+l[i]<dis[j])
			{
				dis[j]=dis[s]+l[i];
				if(!in[j])
				{
					in[j]=true;
					q.push(j);
				}
			}
		}
	}
}
void build()
{
	for(int i=0;i<k;++i)
		now.clear();
	for(int i=1;i<=n;++i)
		if(a[i]>=dis[a[i]%k] && c[i])
			now.insert({-c[i],i});
}
void work()
{
	int type=0,x,y;
	build();
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%I64d",&l[++tot]);
			spfa();
			build();
		}
		if(type==2)
		{
			scanf("%d%d",&x,&y);
			int tmp=-c[x];
			if(c[x])
				c[x]-=y;
			if(now.erase({tmp,x}))
				now.insert({-c[x],x});
		}
		if(type==3)
		{
			if(now.empty())
			{
				puts("0");
				continue;
			}
			auto p=*now.begin();
			now.erase(p);
			c[p.second]=0;
			printf("%d\n",-p.first);
		}
	}
}
int main()
{
	init();
	work();
	return 0;
}