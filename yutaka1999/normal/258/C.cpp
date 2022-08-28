#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int imos[SIZE];
int lr[SIZE],rl[SIZE];

ll mpow(ll x,int t)
{
	ll ret=1;
	while(t)
	{
		if(t%2==1) ret=(ret*x%MOD);
		x=x*x%MOD;
		t/=2;
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		imos[a]++;
	}
	for(int i=SIZE-2;i>=0;i--) imos[i]+=imos[i+1];
	ll ret=0;
	for(int i=SIZE-1;i>=1;i--)
	{
		if(imos[i]==0) continue;
		int ls=0,rs=0;
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				lr[ls++]=j;
				if(j!=i/j) rl[rs++]=i/j;
			}
		}
		ll pd=1;
		int bef=imos[0];
		for(int j=0;j<ls;j++)
		{
			int cnt=bef-imos[lr[j]];
			pd=pd*mpow(j,cnt)%MOD;
			bef=imos[lr[j]];
		}
		for(int j=rs-1;j>=0;j--)
		{
			int cnt=bef-imos[rl[j]];
			pd=pd*mpow(rs-j+ls-1,cnt)%MOD;
			bef=imos[rl[j]];
		}
		ll zan=mpow(ls+rs,bef)-mpow(ls+rs-1,bef);
		if(zan<0) zan+=MOD;
		pd=pd*zan%MOD;
		ret=(ret+pd)%MOD;
	}
	printf("%llld\n",ret);
	return 0;
}