#include<cstdio>
#include<cstring>
using namespace std;
int a[11000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		long long k;scanf("%lld",&k);
		if(k%2==1)
		{
			puts("-1");
			continue;
		}
		k=k/2;
		long long u=1,i=0;
		while(u<=k)u=u*2+1,i++;
		u=u/2;
		memset(a,0,sizeof(a));
		int j=1;a[j]=1;
		while(k>0)
		{
			a[j+i]=1;
			j=j+i;
			k-=u;
			while(u>k)u=u/2,i--;
		}
		printf("%d\n",j-1);
		for(int r=1;r<=j-2;r++)printf("%d ",a[r]);
		printf("%d\n",a[j-1]);
	}
	return 0;
}