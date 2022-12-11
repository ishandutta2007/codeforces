#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll T,d,m,pw2[31],a[31],ans=1;
int main()
{
	scanf("%lld",&T);
	pw2[0]=1;
	for(int i=1;i<31;i++)pw2[i]=pw2[i-1]*2;
	while(T--)
	{
		ans=1;
		scanf("%lld%lld",&d,&m);
		for(int i=0;i<31;i++)a[i]=0;
		for(int i=30;i>=0;i--)
		{
			if((d&(1<<i))==0)continue;
			for(int j=0;j<i;j++)a[j]=(a[j]+pw2[j])%m;
			a[i]=d-(1<<i)+1;
			break;
		}
		for(int i=0;i<31;i++)ans=1ll*ans*(a[i]+1)%m;
		ans=(ans-1+m)%m;
		printf("%lld\n",ans);
	}
	return 0;
}