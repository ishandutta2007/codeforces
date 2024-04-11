#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int T,n,cnt[60],po[60];
long long x[500050];
int main()
{
	po[0]=1;
	for(int i=1;i<60;++i)po[i]=2*po[i-1]%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
		for(int i=1;i<=n;++i)
			for(int j=0;j<60;++j)if(x[i]>>j&1)++cnt[j];
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			int sum1=0,sum2=0;
			for(int j=0;j<60;++j)
				if(x[i]>>j&1)
				{
					sum1=(sum1+1ll*cnt[j]*po[j])%mod;
					sum2=(sum2+1ll*n*po[j])%mod;
				}
				else
				{
					sum2=(sum2+1ll*cnt[j]*po[j])%mod;
				}
			ans=(ans+1ll*sum1*sum2)%mod;
		}
		printf("%d\n",ans);
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}