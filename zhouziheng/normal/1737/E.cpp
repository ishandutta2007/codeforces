#include<cstdio>
#include<algorithm>

using namespace std;

const long long MOD=1e9+7,INV2=(MOD+1)>>1;

int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}

long long pw2[2000000],inv2[2000000];
void init(int n)
{
	pw2[0]=inv2[0]=1;
	for(int i=1;i<=n;i++)pw2[i]=pw2[i-1]*2%MOD,inv2[i]=inv2[i-1]*INV2%MOD;
}

long long dp[2000000],sdp[2000000];

int main()
{
	init(1000000);
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0;scanf("%d",&n);
		dp[n]=1;sdp[n]=1,sdp[n+1]=0;
		for(int i=n-1;i>=1;i--)
		{
			int l=i+1,r=min(2*i-1,n);
			dp[i]=sub(sdp[l],sdp[r+1]);
			sdp[i]=add(dp[i],sdp[i+1]);
		}
		for(int i=1;i<=n;i++)
		{
			printf("%lld\n",dp[i]*pw2[i/2]%MOD*inv2[n-1]%MOD);
		}
	}
}