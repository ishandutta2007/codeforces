#include <cstdio>
#include <algorithm>
#define ll long long
const int N=100005;
int n, a[N];
ll sum[N], ans;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), sum[i]=sum[i-1]+((i&1)?a[i]:-a[i]);
	for(int i=1; i<=n; i+=2)
	{
		ll mn=sum[i]-1;
		for(int j=i+1; j<=n; ++j)
		{
			if(!(j&1))
			{
				ans+=std::max(0ll, std::min(mn, sum[j-1]-1)-std::max(sum[i-1], sum[j])+1);
			}
			mn=std::min(mn, sum[j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}