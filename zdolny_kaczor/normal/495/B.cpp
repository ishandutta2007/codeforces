# include <cstdio>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a==b)
		printf("infinity\n");
	else
	{
		int res = 0;
		for (int i=1; i*i<=a-b; ++i)
		{
			if ((a-b)%i==0)
			{
				if (i>b)
					res++;
				if ((a-b)/i > b && (a-b)!=i*i)
					res++;
			}
		}
		printf("%d\n", res);
	}
}