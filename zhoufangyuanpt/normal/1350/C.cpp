#include<cstdio>
#include<cstring>
using namespace std;
int a[110000];
int cnt[210000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	long long ss=1;
	for(int i=2;i<=450;i++)
	{
		int g=100,gg=100;
		for(int j=1;j<=n;j++)
		{
			int r=0;
			while(a[j]%i==0)a[j]/=i,r++;
			if(r<g)gg=g,g=r;
			else if(r<gg)gg=r;
		}
		for(int j=1;j<=gg;j++)ss=ss*i;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]++;
	}
	for(int i=1;i<=200000;i++)
	{
		if(cnt[i]>=n-1)ss=ss*i;
	}
	printf("%lld\n",ss);
	return 0;
}