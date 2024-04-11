#include<stdio.h>
#include<iostream>
using namespace std;
int a,b,n,maxn=1000000007,i;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(maxn<min(a,b))
		{
			printf("NO");
			return 0;
		}
		if(maxn<max(a,b))maxn=min(a,b);
		else maxn=max(a,b);
	}
	printf("YES");
}