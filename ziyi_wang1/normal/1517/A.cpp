#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		if(n%2050!=0)printf("-1\n");
		else
		{
			n/=2050;
			int ans=0;
			for(;n;n/=10)ans+=n%10;
			printf("%d\n",ans);
		}
	}
	return 0;
}