# include <cstdio>
int main()
{
	long long int n;
	scanf("%I64d", &n);
	for (long long p=2; p*p<=n; ++p)
		while (n%(p*p)==0)
			n/=p;
	printf("%I64d\n", n);
}