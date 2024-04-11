#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000007
#define SIZE 300005
#define MX 20

using namespace std;
typedef long long int ll;

ll inv[SIZE],fac[SIZE],finv[SIZE];
int cnt[SIZE][MX];
ll rt[SIZE];

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
	return fac[a]*(finv[a-b]*finv[b]%MOD)%MOD;
}
int main()
{
	make();
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		for(int j=2;j*j<=t;j++)
		{
			if(t%j==0)
			{
				int c=0;
				while(t%j==0)
				{
					c++;
					t/=j;
				}
				cnt[j][c]++;
			}
		}
		if(t>1) cnt[t][1]++;
	}
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*2LL%MOD;
	ll ret=0;
	for(int i=2;i<SIZE;i++)
	{
		int nm=0;
		for(int j=1;j<MX;j++) nm+=cnt[i][j];
		if(nm==0) continue;
		cnt[i][0]=n-nm;
		//l
		int sum=0;
		for(int j=0;j<MX;j++)
		{
			sum+=cnt[i][j];
			//sum <-> n-sum 
			//E
			ll left=0,right=rt[sum];
			for(int k=0;k<=n-sum;k++)
			{
				ll way=C(sum,k);
				right-=way;
				if(right<0) right+=MOD;
				left+=way*(ll) k%MOD;
				if(left>=MOD) left-=MOD;
				ll vl=C(n-sum,k);
				ret+=left*vl%MOD;
				if(ret>=MOD) ret-=MOD;
				ret+=right*vl%MOD*(ll) k%MOD;
				if(ret>=MOD) ret-=MOD;
			}
			//if(j<=5) printf("%lld ",ret);
		}
		//printf(": %d %lld\n",i,ret);
	}
	printf("%lld\n",ret);
	return 0;
}