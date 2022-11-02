#include<bits/stdc++.h>
using namespace std;
const int B=40;
int n,t[B]={};
int main()
{
	scanf("%d",&n);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		++t[__builtin_popcount(x)];
	}
	long long ans=0;
	for(int i=0;i<B;++i)
		ans+=t[i]*1ll*(t[i]-1)/2;
	printf("%I64d\n",ans);
}