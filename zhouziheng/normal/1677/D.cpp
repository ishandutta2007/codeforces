#include<cstdio>

using namespace std;

const long long MOD=998244353;

int v[2000000];

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0,k=0;scanf("%d%d",&n,&k);for(int i=1;i<=n;i++)scanf("%d",&v[i]);
		long long ans=1;
		for(int i=n-k+1;i<=n;i++){if(v[i]>=1)ans=0;else ans=ans*(n-i+1)%MOD;}
		for(int i=1;i<=n-k;i++)
		{
			if(v[i]==-1)ans=ans*(i+k)%MOD;
			else if(v[i]==0)ans=ans*(k+1)%MOD;
		}
		printf("%lld\n",ans);
	}
}