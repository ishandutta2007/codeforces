#include <cstdio>
#include <algorithm>
int T, n, k;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		if(n==4&&k==n-1) { puts("-1"); continue; }
		if(k==n-1)
		{
			for(int i=2; i<n/2; ++i) if(i!=3) printf("%d %d\n", i, (n-1)^i);
			printf("%d %d\n", n-1, n-2);
			printf("%d %d\n", 0, 3^(n-1));
			printf("%d %d\n", 3, 1);
			continue;
		}
		for(int i=1; i<n/2; ++i) if(i!=k&&i!=((n-1)^k)) printf("%d %d\n", i, (n-1)^i);
		printf("%d %d\n", n-1, k);
		if(k) printf("%d %d\n", 0, (n-1)^k);
	}
	return 0;
}