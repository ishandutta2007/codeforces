#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n;

long long sum[2];

int a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		sum[0]=sum[1]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum[i&1]+=a[i];
		int pos;
		if(sum[0]<sum[1])
			pos=0;
		else
			pos=1;
		for(int i=1;i<=n;i++)
			if((i&1)==pos)
				printf("%d ",1);
			else
				printf("%d ",a[i]);
		puts("");
	}
}