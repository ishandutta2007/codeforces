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
const int mod=1000000007,maxn=40000;
long long n,m,a[550]={};
long long d[20500]={1,1},re[20500]={0,1},red[20500]={1,1},ans=1;
int prime[20100]={},p=0;
bool b[40400]={};
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=2;i<=maxn;++i)
	{
		if(!b[i])
			prime[++p]=i;
		for(int j=1;j<=p && i*prime[j]<=maxn;++j)
		{
			b[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}
void work()
{
	for(int i=2;i<=n*40;++i)
	{
		d[i]=d[i-1]*i%mod;
		long long a=mod/i,b=mod%i;
		re[i]=((-a*re[b])%mod+mod)%mod;
		red[i]=re[i]*red[i-1]%mod;
	}
	for(int i=1;i<=p;++i)
	{	
		int t=0;
		for(int j=1;j<=n;++j)
		{	
			while(a[j]%prime[i]==0)
			{
				a[j]/=prime[i];
				++t;
			}
		}
		(ans*=d[t+n-1]*red[n-1]%mod*red[t]%mod)%=mod;
	}
	for(int i=1;i<=n;++i)
	{
		int t=0;
		if(a[i]!=1)
		{
			for(int j=n;j>=i;--j)
				if(a[j]%a[i]==0)
				{
					a[j]/=a[i];
					++t;
				}
			(ans*=d[t+n-1]*red[n-1]%mod*red[t]%mod)%=mod;
		}
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}