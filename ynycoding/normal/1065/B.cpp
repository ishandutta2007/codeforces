#include <cstdio>
#define ll long long
ll n, m;
ll i;
int main()
{
	scanf("%lld %lld", &n, &m);
	printf("%lld ", (n-m*2)>0?(n-m*2):0);
	for(i=0; i<n; ++i) if(i*(i-1)/2>=m) break;
	printf("%lld", n-i);
	return 0;
}