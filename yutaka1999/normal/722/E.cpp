#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000007
#define SIZE 200005
#define MX 2005
#define ALL 32

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll fac[SIZE],finv[SIZE],inv[SIZE];
ll dp[MX][ALL];
P pos[MX];

void make()
{
	inv[1]=1;
	fac[0]=fac[1]=finv[0]=finv[1]=1;
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
ll invC(int a,int b)
{
	if(a<b) return 0;
	return finv[a]*(fac[b]*fac[a-b]%MOD)%MOD;
}
int main()
{
	make();
	int n,m,k,S;
	scanf("%d %d %d %d",&n,&m,&k,&S);
	for(int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		pos[i]=P(a,b);
	}
	pos[k++]=P(n-1,m-1);
	sort(pos,pos+k);
	for(int i=0;i<k;i++)
	{
		int x=pos[i].first,y=pos[i].second;
		for(int j=1;j<ALL;j++)
		{
			dp[i][j]=C(x+y,y);
			for(int p=0;p<i;p++)
			{
				int a=pos[p].first,b=pos[p].second;
				if(a<=x&&b<=y)
				{
					dp[i][j]-=dp[p][j]*C((x-a)+(y-b),x-a)%MOD;
					if(dp[i][j]<0) dp[i][j]+=MOD;
				}
			}
		}
		for(int j=ALL-1;j>=1;j--)
		{
			dp[i][j]-=dp[i][j-1];
			if(dp[i][j]<0) dp[i][j]+=MOD;
		}
		//for(int j=1;j<=5;j++) printf("%lld ",dp[i][j]);
		//puts("");
	}
	ll ret=C(n+m-2,n-1);
	for(int j=1;j<ALL;j++)
	{
		ret+=dp[k-1][j]*(ll) (S-1)%MOD;
		if(ret>=MOD) ret-=MOD;
		//if(j<=10) printf("%d %d : %lld\n",j,S,dp[k-1][j]);
		S=(S+1)/2;
	}
	ret=ret*invC(n+m-2,n-1)%MOD;
	printf("%lld\n",ret);
	return 0;
}