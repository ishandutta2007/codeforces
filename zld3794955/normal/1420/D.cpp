#include<bits/stdc++.h>
using namespace std;
const int N=300030,mod=998244353;
int n,k,l,r,now=0;
pair<int,int> event[N+N];
long long ans=0,fac[N]={},refac[N]={};
long long power(long long x,long long y)
{
	long long t=1;
	while(y)
	{
		if(y&1) t=t*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return t;
}
long long C(int x,int y)
{
	if(x<y) return 0;
	return fac[x]*refac[y]%mod*refac[x-y]%mod;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<N;++i)
		fac[i]=fac[i-1]*i%mod;
	refac[N-1]=power(fac[N-1],mod-2);
	for(int i=N-2;i>=0;--i)
		refac[i]=refac[i+1]*(i+1)%mod;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&l,&r);
		event[i+i-1]=make_pair(l,1);
		event[i+i]=make_pair(r+1,-1);
	}
	sort(event+1,event+n+n+1);
	for(int i=1;i<=n+n;++i)
	{
		if(event[i].second==-1)
			--now;
		else
			ans=(ans+C(now++,k-1))%mod;
	}
	cout<<ans<<endl;
}