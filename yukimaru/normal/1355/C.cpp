/*********************************************************************
    > File Name: 1355_C.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll a, b, c, d;
	while(scanf("%lld%lld%lld%lld", &a, &b, &c, &d) != EOF)
	{
		ll ans=0, tmp1=0, tmp2=0;
		for(ll i=max(a+b, c+1); i<=(b+c); i++)
		{
			tmp1=min(d, i-1)-c+1;
			tmp2=min(i-a, c)-max(i-b, b)+1;
//			printf("!%lld %lld %lld\n", i, tmp1, tmp2);
			if(tmp1>=0 && tmp2>=0) ans+=(tmp1*tmp2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}