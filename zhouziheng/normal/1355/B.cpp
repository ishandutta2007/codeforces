#include<cstdio>
#include<algorithm>

using namespace std;

int e[300000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&e[i]);
		sort(e+1,e+n+1);
		int ans=0;
		for(int i=1,cnt=0,maxn=0;i<=n;i++)
		{
			cnt++;maxn=e[i];
			if(cnt>=maxn){ans++;maxn=cnt=0;}
		}
		printf("%d\n",ans);
	}
	return 0;
}