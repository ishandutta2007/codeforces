#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010,M=200020;
int n,m,totn=0,totm=0,t[2]={},last[N]={},end[M]={},next[M]={},total_edge=0;
int v[N]={},c[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
}
bool dfs(int s)
{
	v[s]=true;
	++totn;
	++t[c[s]];
	bool flag=false;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		++totm;
		if(v[j])
		{
			if(c[j]==c[s])
				flag=true;
			continue;
		}
		c[j]=c[s]^1;
		flag|=dfs(j);
	}
	return flag;
}
void work()
{
	if(m==0)
	{
		cout<<3<<' '<<n*(n-1ll)*(n-2ll)/6<<endl;
		return;
	}
	int ans1=2;
	long long ans2=m*(n-2ll);
	for(int i=1;i<=n;++i)
		if(!v[i])
		{
			totn=totm=t[0]=t[1]=0;
			if(dfs(i))
			{
				puts("0 1");
				return;
			}
			totm/=2;
			
			if(totm>1)
			{
				if(ans1==2)
					ans1=1,ans2=0;
				ans2+=t[0]*(t[0]-1ll)/2 + t[1]*(t[1]-1ll)/2;
			}
		}
	cout<<ans1<<' '<<ans2<<endl;
}
int main()
{
	init();
	work();
	return 0;
}