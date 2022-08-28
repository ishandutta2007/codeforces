#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll mpow(ll n,ll t)
{
	if(t==0) return n==0?0:1;
	ll ret=mpow(n*n%MOD,t/2);
	if(t%2==1) ret=ret*n%MOD;
	return ret;
}
ll inv(ll x)
{
	return mpow(x%MOD,MOD-2);
}
ll gt[SIZE];
void make()
{
	gt[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		gt[i]=MOD-gt[MOD%i]*(MOD/i)%MOD;
	}
}
int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	if(n<=k+1)
	{
		ll ret=0;
		for(ll i=1;i<=n;i++)
		{
			ll vl=mpow(i,k);
			ret+=vl;
			if(ret>=MOD) ret-=MOD;
		}
		printf("%lld\n",ret);
	}
	else
	{
		make();
		//0`k
		ll mul=1;
		for(int i=0;i<=k+1;i++) mul=mul*(ll) (n-i)%MOD;
		ll sum=0,mt=1;
		for(int i=1;i<=k+1;i++) mt=mt*(MOD-gt[i])%MOD;
		ll ret=0;
		for(int i=0;i<=k+1;i++)
		{
			sum+=mpow(i,k);
			if(sum>=MOD) sum-=MOD;
			ret+=(sum*mt%MOD)*(mul*inv(n-i)%MOD)%MOD;
			if(ret>=MOD) ret-=MOD;
			mt=mt*(MOD+i-(k+1))%MOD;
			mt=mt*gt[i+1]%MOD;
		}
		printf("%lld\n",ret);
	}
	return 0;
}