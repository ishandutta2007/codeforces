#include <cstdio>

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		int n;
		scanf("%d", &n);
		n -= 2;
		if (n < 0) n = 0;
		printf("%d\n", n);
	}

	return 0;
}