# include <cstdio>
# include <set>
int main()
{
	long long a, b;
	scanf("%I64d%I64d", &a, &b);
	long long res=0;
	while (a && b)
	{
		if (a<b)
			std::swap(a, b);
		res+=a/b;
		a=a%b;
	}
	printf("%I64d\n", res);
}