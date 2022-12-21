#include<stdio.h>
#define P 1000000007
using namespace std;
int f[100005],s[100005];
int i,j,k,l,m,n,x,y;
int main()
{
	scanf("%d%d",&n,&m);
	f[0]=1;
	for (i=1;i<=100000;i++)
	{
		f[i]=f[i-1]%P;
		if (i>=m)
		f[i]=(f[i]+f[i-m])%P;
		s[i]=(s[i-1]+f[i])%P;
	}
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",((s[y]-s[x-1])+P)%P);
	}
}