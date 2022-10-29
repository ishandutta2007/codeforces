#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[1010000],a[1100];
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	int minx=0x3f3f3f3f,v=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		minx=min(minx,a[i]);
		v=max(v,a[i]);
	}
	v=v-minx;
	for(int i=1;i<=n;i++)a[i]-=minx;
	memset(f,63,sizeof(f));f[0]=0;
	for(int i=1;i<=k*v;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]<=i)f[i]=min(f[i],f[i-a[j]]+1);
		}
	}
	for(int i=0;i<=k*v;i++)
	{
		if(f[i]<=k)printf("%d ",i+k*minx);
	}
	printf("\n");
	return 0;
}