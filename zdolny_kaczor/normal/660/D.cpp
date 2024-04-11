# include <cstdio>
# include <map>
using namespace std;
map <pair <int, int>, int> cou;
const int MN = 2e3 + 4;
pair <int, int> points[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &points[i].first, &points[i].second);
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k)
			cou[make_pair(points[i].first + points[k].first, points[i].second + points[k].second)]++;
	long long res = 0;
	for (auto x : cou)
	{
		res += x.second * (x.second - 1LL) / 2;
	}
	printf("%I64d\n", res);
}