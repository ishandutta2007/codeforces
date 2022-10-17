#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,k;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		long long ans=0;
		for(int a=3;a<=sqrt(n*2);a++)
		{
			if(a&1)
				ans++;
		}
		printf("%lld\n",ans);
	}
}