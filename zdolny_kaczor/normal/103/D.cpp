# include <cstdio>
# include <vector>
using namespace std;
const int MN = 3e5 + 44;
vector <pair<int, int> > queries[MN];
int w[MN];
long long ans[MN];
long long temp[MN];
int main()
{
	int n, p;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", w + i);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		queries[b].push_back(make_pair(i, a));
	}
	for (int i = 1; i < MN; ++i)
		if (queries[i].size() > i)
		{
			for (int k = n; k >= 0; --k)
				temp[k] = w[k] + ((k + i > n) ? 0 : temp[k + i]);
			for (auto x : queries[i])
				ans[x.first] = temp[x.second];
		}
		else
		{
			for (auto x : queries[i])
			{
				long long res = 0;
				for (int k = x.second; k <= n; k += i)
					res += w[k];
				ans[x.first] = res;
			}
		}
	for (int i = 0; i < q; ++i)
		printf("%I64d\n", ans[i]);
}