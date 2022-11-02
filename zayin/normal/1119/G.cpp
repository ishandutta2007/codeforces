#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n,m;
int a[maxn],b[maxn],sum;

int main()	{
//	freopen("c.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
		scanf("%d",a+i),b[i]=(b[i-1]+a[i])%n,sum+=a[i];
	printf("%d\n",(sum-1)/n+1);
	b[m]=n;
	sort(b+1,b+m+1);
	for (int i=m;i;--i)	b[i]-=b[i-1];
	for (int i=1;i<=m;++i)	
		printf("%d%c",b[i]," \n"[i==m]);
	int j=1;
	for (int i=1;i<=n;++i)	{
		while (a[i]>0)	{
			a[i]-=b[j++];
			printf("%d%c",i," \n"[j>m]);
			if (j>m)	j=1;
		}
	}
	if (j>1)
		while (j<=m)	printf("1 "),++j;
	return 0;
}