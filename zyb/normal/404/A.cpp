#include<stdio.h>
using namespace std;
int z,i,j,k,l,s,m,n;
char a[305][305];
int q[10005],b[1005];
int main()
{
	scanf("%d",&n);
	char c;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{
		c=getchar();
		while (c<'a'||c>'z')
		c=getchar();
		a[i][j]=c;
		z=int(c);
		if (b[z]==0)
		{
			s++;
			q[s]=z;
		}
		b[z]++;
	}
	if (s>2||s<=1)
	{
		printf("NO");
		return 0;
	}
	if (b[q[1]]!=2*n-1)
	{
		printf("NO");
		return 0;
	}
	for (i=1;i<=n;i++)
	if (a[i][i]!=q[1])
	{
		printf("NO");
		return 0;
	}
	for (i=1;i<=n;i++)
	if (a[i][n-i+1]!=q[1])
	{
		printf("NO");
		return 0;
	}
	printf("YES");
}