#include<bits/stdc++.h>
using namespace std;
int n,a[20][20],b[20][20],c[20][20];
char tp;bool flag=0;
void fan1()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	c[i][j]=a[n-i+1][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	a[i][j]=c[i][j];
}
void fan2()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	c[i][j]=a[i][n-j+1];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	a[i][j]=c[i][j];
}
void rev()
{
	for(int j=1;j<=n;j++)
	for(int i=n;i>=1;i--)
	{
		c[j][n-i+1]=a[i][j];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	a[i][j]=c[i][j];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf(" %c",&tp),a[i][j]=(tp=='X')?0:1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf(" %c",&tp),b[i][j]=(tp=='X')?0:1;
	for(int x=1;x<=3;x++)
	{
		for(int k=1;k<=4;k++)
		{
			flag=1;
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]!=b[i][j]){flag=0;break;}
			}
			if(flag==1){printf("Yes");return 0;}
			rev();
		}
		if(x==1)fan1();
		else if(x==2)fan1(),fan2();
	}
	printf("No");
}