# include <cstdio>
# include <set>
using namespace std;
const int MN = (1 << 22) - 1;
int a[MN + 1];
int ans[MN + 1];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		ans[MN &~ a[i]] = a[i];
	}
	for (int i = MN; i >= 0; --i)
		for (int k = 0; (1 << k) <= MN; ++k)
			ans[i] = max(ans[i], ans[i | (1 << k)]);
	for (int i = 0; i < n; ++i)
		if (ans[a[i]] == 0)
			printf("-1 ");
		else
			printf("%d ", ans[a[i]]);
	printf("\n");
}