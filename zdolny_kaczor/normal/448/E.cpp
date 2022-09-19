# include <cstdio>
# include <cstdlib>
int len;
long long divs[10000];
int divamo;
void show(long long nr, long long int deg)
{
	if (deg==0 || nr==1)
	{
		printf("%I64d ", nr);
		len++;
		if (len==100000)
		{
			printf("\n");
			exit(0);
		}
	}
	else
	{
		for (int i=0; i<divamo && divs[i]<=nr; ++i)
		{
			if (nr%divs[i]==0)
				show(divs[i], deg-1);
		}
	}
}
int main()
{
	long long a;
	long long b;
	scanf("%I64d%I64d", &a, &b);
	for (long long int i=1; i*i<=a; ++i)
	{
		if (a%i==0)
			divs[divamo++]=i;
	}
	int poi=divamo-1;
	if (divs[divamo-1]*divs[divamo-1]==a)
		poi--;
	for (;poi>=0; --poi, ++divamo)
		divs[divamo]=a/divs[poi];
	show(a, b);
	printf("\n");
}