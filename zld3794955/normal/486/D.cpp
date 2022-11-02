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
const int N=2020,mod=1000000007;
int d,n,a[N]={},now=0,nowp=0,nowv=0,v[N]={};
int last[N]={},next[N+N]={},end[N+N]={},total_edge=0;
long long f[N][2]={};
bool b[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	cin>>d>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1,u=0,v=0;i<n;++i)
	{
		cin>>u>>v;
		add_edge(u,v);
		add_edge(v,u);
	}
}
void dp(int s,int fa)
{
	f[s][0]=f[s][1]=1;
	v[s]=now;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		if(j==fa || a[j]<nowv-d || !b[j])
			continue;
		dp(j,s);
		f[s][1]=f[s][1]*(f[j][0]+f[j][1])%mod;
		f[s][0]=f[s][0]*f[j][0]%mod;
	}
	if(a[s]==nowv)
		f[s][0]=0;
	else
		f[s][1]=(f[s][1]-f[s][0]+mod)%mod;
	++f[s][0];
}
void work()
{
	long long ans=0;
	a[0]=1<<30;
	for(int i=1;i<=n;++i)
	{
		int now=0;
		for(int j=1;j<=n;++j)
			if(!b[j] && a[j]<a[now])
				now=j;
		nowv=a[now];
		b[now]=true;
		for(int j=1;j<=n;++j)
			f[j][0]=f[j][1]=0;
		dp(now,0);
		ans+=f[now][1];
	}
	ans%=mod;
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}