#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k;

int a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		int now=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]*2<k)
				printf("0 ");
			else if(a[i]*2>k)
				printf("1 ");
			else
				printf("%d\n",now),now^=1;
		}
		puts("");
	}
}