#include <bits/stdc++.h>
#define SIZE 2005
#define MOD 998244353

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll inv[SIZE],fac[SIZE],finv[SIZE];
void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
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
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	ll ret=C(n-1,k)*(ll) m%MOD;
	for(int i=0;i<k;i++) ret=ret*(ll) (m-1)%MOD;
	printf("%lld\n",ret);
	return 0;
}