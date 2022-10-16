#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[300000];int sum[300000];
int pos[300000];

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0;scanf("%d%s",&n,s+1);
		int cnt0=0,cnt1=0;for(int i=1;i<=n;i++)if(s[i]=='0')cnt0++;else cnt1++;
		if(cnt0<cnt1)
		{
			for(int i=1;i<=n;i++)if(s[i]=='0')s[i]='1';else s[i]='0';
			reverse(s+1,s+n+1);swap(cnt0,cnt1);
		}
		
		for(int i=0;i<=n;i++)pos[i]=0;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1];if(s[i]=='0')sum[i]++;else sum[i]--;
			if(sum[i]>=0)pos[sum[i]]=i;
		}
		int p=0;while(p+1<=n&&s[p+1]=='0')p++;
		int ans=0;
		while(p<sum[n])p=(p+pos[p])/2,ans++;
		if(p!=(n+sum[n])/2)ans++;
		printf("%d\n",ans);
	}
}