#include <cstdio>
#define ll long long
int t;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		ll a, b, c, s;
		scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
		s/=c;
		printf("%lld\n", (s/a)*(a+b)+(s%a));
	}
	return 0;
}