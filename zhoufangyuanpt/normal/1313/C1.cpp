#include<cstdio>
#include<cstring>
using namespace std;
int a[1100],c[1100],g[1100];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	long long cc=0;
	for(int i=1;i<=n;i++)
	{
		int m=a[i];g[i]=a[i];long long ss=a[i];
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]<m)m=a[j];
			g[j]=m;ss+=m;
		}
		m=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]<m)m=a[j];
			g[j]=m;ss+=m;
		}
		if(ss>cc)
		{
			cc=ss;
			for(int i=1;i<=n;i++)c[i]=g[i];
		}
	}
	for(int i=1;i<n;i++)printf("%d ",c[i]);
	printf("%d\n",c[n]);
	return 0;
}