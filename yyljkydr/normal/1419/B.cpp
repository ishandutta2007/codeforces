#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

long long n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		long long x=1;
		int ans=0;
		while(n>=x*(x+1)/2)
		{
			n-=x*(x+1)/2;
			x=x<<1|1;
			ans++;
		}
		printf("%d\n",ans);
	}
}