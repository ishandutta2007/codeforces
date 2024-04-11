#include<stdio.h>
#include<cstring>
using namespace std;
int i,j,k,l,s,m,n;
char c[1000005];
int a[1000005],f[1000005];
int ans;
int main()
{
	scanf("%s",&c);
	l=strlen(c);
	for (i=0;i<l;i++)
	a[i+1]=c[i]-'0';
	for (i=1;i<=l;i++)
	{
		if (a[i]==1)
		{
			if (f[i-1]==0&&f[i-2]>=2)
			{
				f[i-1]=f[i-2]+1;
				ans++;
			}
			f[i]=f[i-1]+1;
		}
	else
	f[i]=0;
	}
	for (i=1;i<=l;i++)
	if (f[i+1]==0)
	ans=ans+(f[i]>=1)+(f[i]>=2);
	printf("%d\n",ans);
}