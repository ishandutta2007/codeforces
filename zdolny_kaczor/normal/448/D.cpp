# include <cstdio>
# define min(a, b) ((a)>(b)?(b):(a))
int main()
{
	int n, m;
	long long k;
	scanf("%d%d%I64d", &n, &m, &k);
	long long min=0, max=(long long) n*m;
	while (min<max)
	{
		long long med=(min+max)/2;
		
		long long amo=0;
		for (int i=1; i<=n; ++i)
			amo+=min(m, med/i); //ile mniejszych rwnych med
		if (amo<k)
			min=med+1;
		else
			max=med;
	}
	printf("%I64d\n", min);
}