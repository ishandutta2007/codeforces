# include <cstdio>
long double ans = 1;
long double frac;
long long a1, a2;
long double abs(long double a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}
void add(long long a, long long b)
{
	long double val = abs (frac - a / (long double) b);
// 	printf("%I64d / %I64d => val = %lf\n", a, b, (double) val);
	if (ans > val)
	{
		ans = val;
		a1 = a;
		a2 = b;
	}
}
int main()
{
	int x, y, n;
	scanf("%d%d%d", &x, &y, &n);
	frac = x / (long double) y;
	for (int i = 1; i <= n; ++i)
	{
		long long d = (long long) x * i / y;
// 		printf("d = %I64d i = %d\n", d, i);
		add(d, i);
		add(d + 1, i);
	}
// 	printf("ans = %lf\n", (double) ans);
	printf("%I64d/%I64d\n", a1, a2);
}