#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		LL x,cnt=0;
		scanf("%lld",&x);
		for (int i=0;i<30;++i)
			if (x>>i&1)
				++cnt; 
		printf("%lld\n",1LL<<cnt);
	}
	return 0;
}