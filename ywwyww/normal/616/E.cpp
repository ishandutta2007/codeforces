#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll p=1000000007;
ll inv2=500000004;
ll sum(ll l,ll r)
{
	return (l+r)%p*((r-l+1)%p)%p*inv2%p;
}
int main()
{
	ll n,m;
	scanf("%I64d%I64d",&n,&m);
	ll ans=0;
	if(m>n)
	{
		ans+=(m-n)%p*(n%p)%p;
		ans%=p;
		m=n;
	}
	ans+=n%p*(m%p)%p;
	ans%=p;
	ll i,j;
	for(i=1;i<=m;i=j+1)
	{
		j=min(m,n/(n/i));
		ans-=n/i*sum(i,j);
		ans%=p;
	}
	ans=(ans+p)%p;
	printf("%I64d\n",ans);
	return 0;
}