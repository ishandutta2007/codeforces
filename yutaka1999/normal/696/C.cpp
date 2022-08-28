#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll mpow(ll a,ll t)
{
	if(t==0) return 1LL;
	ll ret=mpow(a,t/2);
	ret=ret*ret%MOD;
	if(t%2==1) ret=ret*a%MOD;
	return ret;
}
ll inv(ll a)
{
	return mpow(a,MOD-2);
}
int main()
{
	int k;
	scanf("%d",&k);
	ll mt=2LL;
	bool up=false;
	for(int i=0;i<k;i++)
	{
		ll a;
		scanf("%lld",&a);
		mt=mpow(mt,a);
		if(a%2==0) up=true;
	}
	mt=mt*inv(2)%MOD;
	ll ch=mt+(up?1:-1);
	if(ch>=MOD) ch-=MOD;
	if(ch<0) ch+=MOD;
	ch=ch*inv(3)%MOD;
	printf("%lld/%lld\n",ch,mt);
	return 0;
}