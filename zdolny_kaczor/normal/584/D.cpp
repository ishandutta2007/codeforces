# include <cstdio>
bool isprime(int p)
{
	for (int i=2; i*i<=p; ++i)
		if (p%i==0)
			return false;
	return true;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int x=n; ; x-=2)
		if (isprime(x))
		{
			int diff=n-x;
			if (diff==0)
				printf("1\n%d\n", n);
			else if (diff==2)
				printf("2\n%d 2\n", x);
			else
			{
				for (int a=2; a<=diff; ++a)
					if (isprime(a) && isprime(diff-a))
					{
						printf("3\n%d %d %d\n", x, a, diff-a);
						return 0;
					}
			}
			return 0;
		}
}