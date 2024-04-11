#include<stdio.h>
#include<cstring>
#define P 1000000007
using namespace std;
int f[1000005][3][10];
int i,j,k,l,s,m,n,ans;
char c[1000005];
inline void work()
{
	for (int j=0;j<=1;j++)
	for (int k=0;k<=1;k++)
	{
		if (k!=j)
		continue;
		f[i][0][0]=(f[i][0][0]+f[i-1][j][k])%P;
	}
}
inline void work1()
{
	for (int j=0;j<=1;j++)
	for (int k=0;k<=3;k++)
	{
		if (k!=j&&k!=3)
		continue;
		f[i][(k==3)][1]=(f[i][(k==3)][1]+f[i-1][j][k])%P;
	}
}
inline void work2()
{
	for (int j=0;j<=1;j++)
	for (int k=0;k<=3;k++)
	{
		if (k!=j&&k!=3)
		continue;
		f[i][(k==3)][2]=(f[i][(k==3)][2]+f[i-1][j][k])%P;
	}
}
inline void work3()
{
	for (int j=0;j<=1;j++)
	for (int k=0;k<=3;k++)
	{
		if (k!=(j+1)&&k!=3)
		continue;
		f[i][(k==3)][3]=(f[i][(k==3)][3]+f[i-1][j][k])%P;
	}
}
int main()
{
	scanf("%s",c);
	l=strlen(c);
	if (c[0]=='*'||c[0]=='?')
	f[0][0][3]=1;
	if (c[0]=='1'||c[0]=='?')
	f[0][0][1]=1;
	if (c[0]=='0'||c[0]=='?')
	f[0][0][0]=1;
	for (i=1;i<l;i++)
	{
		if (c[i]=='*'||c[i]=='?')
		work3();
		if (c[i]=='0'||c[i]=='?')
		work();
		if (c[i]=='1'||c[i]=='?')
		work1();
		if (c[i]=='2'||c[i]=='?')
		work2();
	}
	if (c[l-1]=='*'||c[l-1]=='?')
	{
		for (i=0;i<=1;i++)
		ans=(ans+f[l-1][i][3])%P;
	}
	if (c[l-1]=='0'||c[l-1]=='?')
	{
		ans=(ans+f[l-1][0][0])%P;
	}
	if (c[l-1]=='1'||c[l-1]=='?')
	{
		ans=(ans+f[l-1][1][1])%P;
	}
	printf("%d\n",ans);
}