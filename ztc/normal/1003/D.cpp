#include<stdio.h>
#include<iostream>
#include<deque>
using namespace std;
long long n,i,j,x,k,cnt,m;
long long a[32],b[32]={1,0};
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=30;i++)b[i]=b[i-1]<<1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(j=0;j<=30;j++)
		{
			if(k==b[j])a[j]+=1;
			if(k==b[j])break;
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		j=0;
		cnt=0;
		while(b[j]<=k)j++;
		j-=1;
		for(;j>=0&&k;j--)
		{
			if(k>=b[j])
			{
				if(k/b[j]>a[j])
				{
					cnt+=a[j];
					k-=a[j]*b[j];
				}
				else
				{
					cnt+=k/b[j];
					k=k%b[j];
				}
			}
		}
		if(k)printf("-1\n");
		else printf("%d\n",cnt);
	}
	return 0;
}