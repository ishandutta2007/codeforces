# include <cstdio>
long long tr(long long a)
{
	return a*(a+1)/2;
}
bool isfun(long long x)
{
	int low=1, hig=x;
	while (low<=hig)
	{
		int med=(low+hig)/2;
		long long cmp=tr(med);
		if (cmp==x)
			return true;
		if (cmp<x)
			low=med+1;
		else
			hig=med-1;
	}
	return false;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; tr(i)<=n; ++i)
		if (isfun(n-tr(i)))
		{
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
}