#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long s[10000],c[10000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);memset(c,0,sizeof(c));for(int i=1;i<=n;i++)scanf("%lld",&s[i]);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=max(0ll,s[i]-c[i]-1);
			for(int j=i+2;j<=i+s[i]&&j<=n;j++)c[j]++;
			if(s[i]<=c[i])c[i+1]+=(c[i]-s[i]+1);
		}
		printf("%lld\n",ans);
	}
}