#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int a[510][N],b[N],m,n,k;

int main()
{
	int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=1;i<=500;i++)//q
	{
		for(j=n;j>=1;j--)//p
		{
			if(i+j+b[j]>n)
			{
				a[i][j]=1;
			}
			else
			{
				a[i][j]=a[i][i+j+b[j]]+1;
			}
		}
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q);
		if(q<=500)
		{
			printf("%d\n",a[q][p]);
		}
		else
		{
			k=0;
			while(p<=n)
			{
				k++;
				p=p+q+b[p];
			}
			printf("%d\n",k);
		}
	}
}