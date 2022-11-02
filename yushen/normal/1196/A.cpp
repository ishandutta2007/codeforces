#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",(a+b+c)/2);
	}
	return 0;
}