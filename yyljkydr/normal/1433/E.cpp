#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans*=i;
	ans*=2;
	ans/=n*n;
	printf("%lld\n",ans);
}