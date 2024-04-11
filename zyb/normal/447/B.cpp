#include<stdio.h>
#include<cstring>
using namespace std;
char c[1005];
int ans,i,j,k,l,s,m,n,a[30];
int main()
{
	scanf("%s",c);
	scanf("%d",&n);
	l=strlen(c);
	int ma=0;
	for (i=1;i<=26;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>ma)
		ma=a[i];
	}
	for (i=0;i<l;i++)
	ans=ans+(i+1)*a[int(c[i])-96];
	for (i=l+1;i<=l+n;i++)
	ans=ans+i*ma;
	printf("%d",ans);
}