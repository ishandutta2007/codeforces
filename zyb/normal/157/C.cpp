#include<stdio.h>
#include<cstring>
using namespace std;
char c[2005],b[2005];
int i,j,k,l,s,m,n,ll;
inline int min(int o,int p)
{
	if (o<p)
	return o;
	else return p;
}
int f[2005][2005];
int main()
{
	scanf("%s%s",&c,&b);
	memset(f,63,sizeof(f));
	l=strlen(c);
	ll=strlen(b);
	i=0;j=0;
	for (i=0;i<=ll;i++)
	f[0][i]=i;
	for (i=0;i<=l;i++)
	f[i][0]=0;
	for (i=1;i<=l;i++)
	for (j=0;j<=ll;j++)
	{
		if (j==ll&&i==l)
		j=ll;
		if (c[i-1]==b[j-1])
		f[i][j]=min(f[i][j],f[i-1][j-1]);
		else
		f[i][j]=min(f[i][j],f[i-1][j-1]+1);
	}
	int ans=1000000;
	for (i=0;i<=l;i++)
	for (j=0;j<=ll;j++)
	ans=min(ans,f[i][j]+ll-j);
	printf("%d\n",ans);
}