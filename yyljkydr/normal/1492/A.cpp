#include<bits/stdc++.h>
using namespace std;

int T;

typedef long long ll;

ll p,a,b,c;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		long long ans=1e18;
		ans=min(ans,a-p%a);
		ans=min(ans,b-p%b);
		ans=min(ans,c-p%c);
		if(p%a==0||p%b==0||p%c==0)
			ans=0;
		printf("%lld\n",ans);
	}
}