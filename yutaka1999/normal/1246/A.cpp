#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n,p;
	scanf("%lld %lld",&n,&p);
	for(int i=1;;i++)
	{
		n-=p;
		if(n<i) break;
		int cnt=0;
		ll now=n;
		while(now>0)
		{
			if(now%2==1) cnt++;
			now/=2;
		}
		if(cnt<=i)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}