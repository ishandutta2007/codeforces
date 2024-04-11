#include<cstdio>
#include<algorithm>

using namespace std;

int cnt[400000][2];int a[400000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)cnt[i][0]=cnt[i][1]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=n)cnt[a[i]][1]++;else cnt[min(n,(a[i]-1)/2)][0]++;
		}
		int c=0,ans=0;
		for(int i=n;i>=1;i--)
		{
			c+=cnt[i][0];
			if(cnt[i][1])
			{
				cnt[i][1]--;cnt[(i-1)/2][0]+=cnt[i][1];
			}
			else
			{
				if(!c){ans=-1;break;}
				ans++;c--;
			}
		}
		printf("%d\n",ans);
	}
}