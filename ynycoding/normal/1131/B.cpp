#include <cstdio>
#include <algorithm>
#define ll long long
ll n, x, y, px, py;
ll ans=1;
int main()
{
	scanf("%lld", &n);
	while(n--)
	{
		scanf("%lld%lld", &x, &y);
		if(std::min(x, y)>=std::max(px, py)) ans+=std::min(x, y)-std::max(px, py)+(px!=py);
		px=x, py=y;
	}
	printf("%lld", ans);
	return 0;
}