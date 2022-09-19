# include <cstdio>
int main()
{
	int h, m;
	int a;
	scanf("%d:%d%d", &h, &m, &a);
	int res = (h * 60 + m + a) % (24 * 60);
	printf("%02d:%02d\n", res / 60, res % 60);
}