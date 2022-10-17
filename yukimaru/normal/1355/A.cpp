/*********************************************************************
    > File Name: 1355_A.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf=0x3f3f3f3f;

void solve(ll n, ll &mina, ll &maxa)
{
	ll tmp=n, x;
	while(tmp)
	{
		x=tmp%10;
		tmp/=10;
		mina=min(mina, x);
		maxa=max(maxa, x);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ll n, k;
		scanf("%lld%lld", &n, &k);
		for(ll i=2; i<=k; i++)
		{
			ll mina=inf, maxa=0;
			solve(n, mina, maxa);
			n+=mina*maxa;
//			printf("%lld: %lld\n", i, n);
			if(mina == 0) break;
		}
		printf("%lld\n", n);
	}
	return 0;
}