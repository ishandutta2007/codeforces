#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[262144],b[262144],c[110];
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	int an=n/2,bn=(n+1)/2;
	for(int i=0;i<1<<an;i++)
	{
		int ss=0;
		for(int j=1;j<=an;j++)
		{
			ss=(ss+c[j]*((i&1<<(j-1))>0))%m;
		}
		a[i]=ss;
	}
	for(int i=0;i<1<<bn;i++)
	{
		int ss=0;
		for(int j=1;j<=bn;j++)
		{
			ss=(ss+c[j+an]*((i&1<<(j-1))>0))%m;
		}
		b[i]=ss;
	}
	sort(a,a+(1<<an));
	sort(b,b+(1<<bn));
	int j=(1<<bn)-1,ss=0;
	for(int i=0;i<1<<an;i++)
	{
		while(a[i]+b[j]>=m)j--;
		if(ss<a[i]+b[j])ss=a[i]+b[j];
	}
	printf("%d\n",ss);
	return 0;
}