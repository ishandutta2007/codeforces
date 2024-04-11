# include <cstdio>
# include <vector>
using namespace std;
const int MN = 2e5 + 44;
long long a[MN];
vector <pair <int, long long> > hull;
bool bad(pair <int, long long> x)
{
	if (hull.size() < 2)
		return false;
	pair <int, long long> y = hull.back();
	pair <int, long long> z = hull[hull.size() - 2];
	return (x.second - y.second) * (z.first - y.first) < (z.second - y.second) * (x.first - y.first);
}
long long eval(pair <int, long long> a, long long x, long long y)
{
// 	printf("return %I64d\n", a.first * x + a.second + y);
	return a.first * x + a.second + y;
}
long long sufsum[MN];
long long sufscores[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%I64d", a + i);
	for (int i = n - 1; i >= 0; --i)
		sufsum[i] = sufsum[i + 1] + a[i];
	for (int i = n - 1; i >= 0; --i)
		sufscores[i] = sufscores[i + 1] + sufsum[i];
	for (int i = 0; i < n; ++i)
	{
		pair <int, long long> add = make_pair(i, sufscores[i]);
// 		printf("add %d %I64d\n", add.first, add.second);
		while (bad(add))
			hull.pop_back();
		hull.push_back(add);
	}
// 	for (auto x : hull)
// 		printf("%d %I64d\n", x.first, x.second);
	long long res = 0;
	long long x = 0, y = 0;
	for (int i = n - 1; i >= 0; --i)
	{
// 		printf("i = %d x = %I64d y = %I64d\n", i, x, y);
		int low = 0, high = hull.size() - 1;
		while (low < high - 3)
		{
			int med = (low + high) / 2;
			if (hull[med].first > i)
				high = med - 1;
			else
			{
				long long val = eval(hull[med], x, y);
// 				printf("include %d %I64d\n", hull[med].first, hull[med].second);
				res = max(res, val);
				if (eval(hull[med], x, y) > eval(hull[med + 1], x, y))
					high = med;
				else
					low = med;
			}
		}
// 		printf("binsearch done\n");
		for (int k = low; k <= high; ++k)
			if (hull[k].first <= i)
			{
// 				printf("include %d %I64d\n", hull[k].first, hull[k].second);
				res = max(res, eval(hull[k], x, y));
			}
		y -= (i + 1) * a[i];
		x += a[i];
	}
	printf("%I64d\n", res);
}