# include <cstdio>
int main()
{
	int d, l, v, w;
	scanf("%d%d%d%d", &d, &l, &v, &w);
	printf("%lf\n", (l - d)/((double)v + w));
}