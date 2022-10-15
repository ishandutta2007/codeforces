#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,cnt[200020];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1,x;i<=n;++i)
		{
			scanf("%d",&x),++cnt[x];
		}
		for(int i=1;i<=2*n;++i)if(cnt[i]>1)++cnt[i+1];
		int ans=0;
		for(int i=1;i<=2*n+1;++i)ans+=cnt[i]>0,cnt[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}