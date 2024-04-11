#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		LL l,r;
		scanf("%lld%lld",&l,&r);
		
		LL len=(r-l+1),ans=-len/2;
		if (l&1)
			ans=-ans;
		if (len&1)
			ans+=(r%2?-1:1)*r;
		
		printf("%lld\n",ans);
	}
	return 0;
}