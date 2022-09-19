# include <cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	int fac = 1;
	switch (n)
	{
		case 1: case 2: case 3:
			printf("NO\n");
		break;
		case 4:
			printf("YES\n");
			for (int i = 2; i <= 4; ++i)
			{
				printf("%d * %d = %d\n", fac, i, fac * i);
				fac *= i;
			}
		break;
		case 5:
			printf("YES\n");
			printf("5 * 4 = 20\n20 + 3 = 23\n23 + 2 = 25\n25 - 1 = 24\n");
		break;
		default:
			printf("YES\n");
			printf("3 - 2 = 1\n1 - 1 = 0\n");
			for (int i = 5; i <= n; ++i)
				if (i != 6)
					printf("0 * %d = 0\n", i);
			printf("4 * 6 = 24\n");
			printf("24 + 0 = 24\n");
		break;
	}
}