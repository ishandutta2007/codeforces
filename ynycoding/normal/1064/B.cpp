#include <cstdio>
int t, n, ans=1;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		ans=1;
		scanf("%d", &n);
		while(n)
		{
			if(n&1) ans<<=1;
			n>>=1;
		}
		printf("%d\n", ans);
	}
	return 0;
}