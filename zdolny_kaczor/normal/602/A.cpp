# include <cstdio>
long long getnum()
{
	int len, base;
	long long res=0;
	scanf("%d%d", &len, &base);
	for (int i=0; i<len; ++i)
	{
		int x;
		scanf("%d", &x);
		res=res*base+x;
	}
	return res;
}
int main()
{
	long long a, b;
	a=getnum();
	b=getnum();
	if (a<b)
		printf("<\n");
	else if (a==b)
		printf("=\n");
	else
		printf(">\n");
}