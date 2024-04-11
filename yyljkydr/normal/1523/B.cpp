#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)	
			scanf("%d",&a[i]);
		printf("%d\n",n*3);
		for(int i=1;i<=n;i+=2)
		{
			printf("2 %d %d\n",i,i+1);
			printf("1 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
			printf("1 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
		}
	}
}