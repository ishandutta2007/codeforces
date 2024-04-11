# include <cstdio>
# include <set>
# include <vector>
using namespace std;
const int MN = 1e2 + 4;
set <pair <int, int> > towers;
vector <pair <int, int> > swaps;
int a[MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == 1)
	{
		printf("0 0\n\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		towers.insert(make_pair(a[i], i));
	}
	for (int i = 0; i < k; ++i)
	{
		pair <int, int> low = *towers.begin();
		auto it = towers.end();
		it --;
		pair <int, int> high = *it;
		if (low.first == high.first)
			break;
		swaps.push_back(make_pair(high.second, low.second));
		towers.erase(low);
		towers.erase(high);
		low.first ++;
		high.first --;
		towers.insert(low);
		towers.insert(high);
		a[low.second] ++;
		a[high.second] --;
	}
	int m = 1e7, M = 0;
	for (int i = 1; i <= n; ++i)
	{
		m = min(m, a[i]);
		M = max(M, a[i]);
	}
	printf("%d %lu\n", M - m, swaps.size());
	for (auto x : swaps)
		printf("%d %d\n", x.first, x.second);
}