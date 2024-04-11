#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char str[SIZE];
ll inv[SIZE],fac[SIZE],finv[SIZE];
ll sum[SIZE],rt[SIZE],rui[SIZE];

void make()
{
	inv[1]=1;
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*10LL%MOD;
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
ll get(int a,int b)
{
	return (sum[b]-(a==0?0:sum[a-1]*rt[b-a+1]%MOD)+MOD)%MOD;
}
ll get2(int a,int b)
{
	return (rui[b]-(a==0?0:rui[a-1])+MOD)%MOD;
}
int main()
{
	make();
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",&str);
	for(int i=0;i<n;i++)
	{
		sum[i]=str[i]-'0';
		if(i>0)
		{
			sum[i]+=sum[i-1]*10LL;
			sum[i]%=MOD;
		}
		rui[i]=sum[i];
		if(i>0)
		{
			rui[i]+=rui[i-1];
			if(rui[i]>=MOD) rui[i]-=MOD;
		}
	}
	ll ret=0;
	if(k==0)
	{
		printf("%I64d\n",sum[n-1]);
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		int zan=n-i-2;
		ret+=sum[i]*C(zan,k-1);
		ret%=MOD;
	}
	for(int i=1;i<n;i++)
	{
		int zan=i-1;
		ret+=get(i,n-1)*C(zan,k-1);
		ret%=MOD;
	}
	if(k>=2)
	{
		for(int L=1;L<=n-2;L++)
		{
			ll v1=get2(L,n-2);
			ll v2=get2(0,n-L-2)*rt[L]%MOD;
			ll v3=(v1-v2+MOD)%MOD;
			ret+=v3*C(n-L-2,k-2);
			ret%=MOD;
		}
	}
	printf("%I64d\n",ret);
	return 0;
}