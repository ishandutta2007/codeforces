#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1005
int T, n, m, a, b;
char s[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		a=b=0;
		scanf("%d", &n);
		for(int i=1, x, cur=0; i<=n; ++i) scanf("%d", &x), cur+=x, a=std::max(a, cur);
		scanf("%d", &m);
		for(int i=1, x, cur=0; i<=m; ++i) scanf("%d", &x), cur+=x, b=std::max(b, cur);
		printf("%d\n", a+b);
	}
	return 0;
}