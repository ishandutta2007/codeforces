# include <cstdio>
int gcd(int a, int b)
{
	if (a==0)
		return b;
	if (b==0)
		return a;
	return gcd(b, a%b);
}
int max(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}
int main()
{
	int n;
	int g=0, m=0;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int a;
		scanf("%d", &a);
		g=gcd(g, a);
		m=max(m, a);
	}
	if ((m/g+n)%2)
		printf("Alice\n");
	else
		printf("Bob\n");
}