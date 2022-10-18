#include <cstdio>
#include <algorithm>
int T, n;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		if(n<=3) puts("-1");
		else if(n==4) puts("2 4 1 3");
		else
		{
			for(int i=1; i<=n; i+=2) printf("%d ", i);
			if(n&1)
			{
				printf("%d %d ", n-3, n-1);
				for(int i=n-5; i>0; i-=2) printf("%d ", i);
			}
			else
			{
				printf("%d %d %d ", n-4, n, n-2);
				for(int i=n-6; i>0; i-=2) printf("%d ", i);
			}
			puts("");
		}
	}
	return 0;
}