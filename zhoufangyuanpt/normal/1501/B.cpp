#include<cstdio>
#include<cstring>
using namespace std;
int a[210000],b[210000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ss=0,t=n+1;
		for(int i=n;i>=1;i--)
		{
			if(i-a[i]+1<t)t=i-a[i]+1;
			if(t<=i)b[i]=1;
			else b[i]=0;
		}
		for(int i=1;i<n;i++)printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
	return 0;
}