#include <cstdio>

int n, d, m;
int main()
{
	scanf("%d%d%d", &n, &d, &m);
	for(int i=1, a, b; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		if(a+b<=2*n-d&&a+b>=d&&a-b<=d&&a-b>=-d) puts("YES");
		else puts("NO");
	}
	return 0;
}