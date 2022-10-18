#include <cstdio>
#define ll long long
int t, n, x;
ll sum;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		sum=0, x=0;
		for(int i=1, a; i<=n; ++i) scanf("%d", &a), sum+=a, x^=a;
		sum+=x;
		printf("3\n%d %lld %lld\n", x, sum&1, sum-(sum&1));
	}
	return 0;
}