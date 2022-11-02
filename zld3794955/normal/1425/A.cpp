#include<bits/stdc++.h>
using namespace std;
long long pick(long long n)
{
	if(n==0)
		return 0;
	if(n%2)
		return 1;
	else
		return n/2%2 || n<=4 ? n/2 : 1;
}
int main()
{
	int T;
	long long n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&n);
		long long ans=0;
		while(n)
		{
			ans+=pick(n);
			n-=pick(n);
			n-=pick(n);
		}
		printf("%I64d\n",ans);
	}
}