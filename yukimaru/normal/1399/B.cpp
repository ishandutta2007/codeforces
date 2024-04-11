/*********************************************************************
    > File Name: 1399_B.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		ll a[55]={0}, b[55]={0};
		ll mina=INT_MAX, minb=INT_MAX;
		for(int i=1; i<=n; i++)
		{
			scanf("%lld", &a[i]);
			mina=min(mina, a[i]);
		}
		for(int i=1; i<=n; i++)
		{
			scanf("%lld", &b[i]);
			minb=min(minb, b[i]);
		}
		ll ans=0;
		for(int i=1; i<=n; i++)
			ans+=(a[i]-mina)+(b[i]-minb)-min(a[i]-mina, b[i]-minb);
		printf("%lld\n", ans);
	}
	return 0;
}