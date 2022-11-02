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
const int mod=1000000007,N=200200,MaxN=200000;
long long d[N]={1},re[N]={0,1},red[N]={1,1};
int prime[N]={},ptot=0,minp[N]={},n,f;
int a[N]={},tot=0;
void init()
{
	bool v[N]={};
	for(int i=2;i<=MaxN;++i)
	{
		if(!v[i])
			prime[++ptot]=i,minp[i]=i;
		for(int j=1;j<=ptot && i*prime[j]<=MaxN;++j)
		{
			v[i*prime[j]]=true;
			minp[i*prime[j]]=prime[j];
			if(i%prime[j]==0)
				break;
		}
	}
	for(int i=1;i<=MaxN;++i)
		d[i]=d[i-1]*i%mod;
	for(int i=2;i<=MaxN;++i)
	{
		long long a=mod%i,b=mod/i;
		re[i]=((-b*re[a])%mod+mod)%mod;
		red[i]=red[i-1]*re[i]%mod;
	}
}
void get_factor(int x)
{
	while(x!=1)
	{
		if(minp[x]!=a[tot])
			a[++tot]=minp[x];
		x/=minp[x];
	}
}
long long tryy(int t,int x)
{
	if(t>tot)
	{
		if(n/x<f)
			return 0ll;
		int x1=n/x-1,x2=f-1;
		long long s=d[x1]*red[x2]%mod*red[x1-x2]%mod;
		return s;
	}
	long long s1=tryy(t+1,x);
	long long s2=tryy(t+1,x*a[t]);
	return (s1-s2+mod)%mod;
}
void work()
{
	tot=0;
	get_factor(n);
	printf("%I64d\n",tryy(1,1));
}
int main()
{	
	init();
	int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&f);
		work();
	}
	return 0;
}