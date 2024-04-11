#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int x;
		scanf("%d%d",&n,&x);
		long long mn=0,mx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mn+=a[i],mx+=(a[i]+x-1)/x;
		}
		mn=(mn+x-1)/x;
		printf("%lld %lld\n",mn,mx);
	}
}