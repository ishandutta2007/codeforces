# include <cstdio>
# include <set>
using namespace std;
int n, k, a, b, c, d;
bool good(int x)
{
	return x != a && x != b && x != c && x != d;
}
void show()
{
	printf("%d %d", a, c);
	for (int i = 1; i <= n; ++i)
		if (good(i))
			printf(" %d", i);
	printf(" %d %d", d, b);
	printf("\n");
}
int main()
{
	scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);
	if (k < n + 1 || n == 4)
		printf("-1\n");
	else
	{
		show();
		swap(a, c);
		swap(b, d);
		show();
	}
}