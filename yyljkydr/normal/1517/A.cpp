#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,n;

signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n%2050!=0)
			puts("-1");
		else
		{
			n/=2050;
			int ans=0;
			while(n)
				ans+=n%10,n/=10;
			printf("%lld\n",ans);
		}
	}
}