# include <cstdio>
# include <set>
using namespace std;
const int MN = 5e3 + 44;
int cou[MN];
int a[MN];
pair <int, int> best;
int ans[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i)
	{
		best = make_pair(0, 0);
		for (int k = 0; k < MN; ++k)
			cou[k] = 0;
		for (int k = i; k < n; ++k)
		{
			cou[a[k]]++;
			best = max(best, make_pair(cou[a[k]], -a[k]));
			ans[-best.second]++;
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}