# include <cstdio>
int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	printf("%d", ((a + b) % n + n - 1) % n + 1);
}