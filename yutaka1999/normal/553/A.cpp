#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000007
#define SIZE 100005

using namespace std;
typedef long long int ll;

ll inv[SIZE],fac[SIZE],finv[SIZE];

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
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
int main()
{
	make();
	int k;
	scanf("%d",&k);
	int now=0;
	ll ret=1;
	for(int i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		ret*=C(now+a-1,now);
		ret%=MOD;
		now+=a;
	}
	printf("%I64d\n",ret);
	return 0;
}