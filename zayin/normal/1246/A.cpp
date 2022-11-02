#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()	{
	LL n,p;
	scanf("%lld%lld",&n,&p);
	for (int i=1;i<10000;++i)	{
		LL m=n-i*p;
		if (m>=i&&__builtin_popcountll(m)<=i)	{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}