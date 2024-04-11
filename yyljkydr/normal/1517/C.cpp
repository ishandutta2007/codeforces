#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int n,p[N];

int a[N][N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
			a[j+i-1][j]=p[j];
		for(int j=1;j<=n-i+1;j++)
			if(p[j]==i)
			{
				for(int k=j;k<=n-i;k++)
					p[k]=p[k+1];
				break;
			}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=i;j++,putchar(' '))
			printf("%d",a[i][j]);
}