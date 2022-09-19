# include <cstdio>
# include <algorithm>
using namespace std;
int order = 22;
long long nr(int x, int y, int deg)
{
	if (deg == 0)
		return 0;
	else
	{
		int side = 1 << (deg - 1);
		long long cou = 1LL << (2 * deg - 2);
		if (x < side && y < side)
			return nr(y, x, deg - 1);
		else if (x < side && y >= side)
			return cou + nr(x, y - side, deg - 1);
		else if (x >= side && y >= side)
			return cou * 2 + nr(x - side, y - side, deg - 1);
		else
			return cou * 3 + nr(side - y - 1, 2 * side - x - 1, deg - 1);
	}
}
const int MN = 1e6 + 44;
pair <long long, int> a[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = make_pair(nr(x, y, order), i + 1);
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i].second);
	printf("\n");
}