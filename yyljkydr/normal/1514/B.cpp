#include<bits/stdc++.h>
using namespace std;

const int P=1e9+7;

int T,n,k;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		long long ans=1;
		for(int i=1;i<=k;i++)
			ans=ans*n%P;
		printf("%lld\n",ans);
	}
}