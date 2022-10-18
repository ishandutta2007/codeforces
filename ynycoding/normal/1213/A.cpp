#include <cstdio>
#include <algorithm>
int n, x, s;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &x), s+=(x&1);
	printf("%d\n", std::min(s, n-s));
	return 0;
}