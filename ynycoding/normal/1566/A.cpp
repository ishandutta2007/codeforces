#include <cstdio>
#include <algorithm>
int T, n, s;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &s);
		printf("%d\n", s/((n>>1)+1));
	}
	return 0;
}