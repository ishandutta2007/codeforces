#include <cstdio>
#define ll long long
int T;
ll a, b, k;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &a, &b, &k);
		printf("%lld\n", a*(k-(k>>1))-b*(k>>1));
	}
	return 0;
}