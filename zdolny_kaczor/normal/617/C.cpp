# include <cstdio>
# include <algorithm>
using namespace std;
typedef pair <int, int> point;
long long dist(point a, point b)
{
	return (a.first - b.first) * 1ll * (a.first - b.first) + (a.second - b.second) * 1ll * (a.second - b.second);
}
point get()
{
	point ret;
	scanf("%d%d", &ret.first, &ret.second);
	return ret;
}
point o1, o2;
const int MN = 2e3 + 44;
pair <long long, long long> in[MN];
int main()
{
	int n;
	scanf("%d", &n);
	o1 = get();
	o2 = get();
	for (int i = 0; i < n; ++i)
	{
		point p = get();
		in[i] = make_pair(dist(p, o1), dist(p, o2));
	}
	sort(in, in + n);
	long long M = 0, res = 1ll << 62;
	for (int i = n - 1; i >= 0; --i)
	{
		res = min(res, M + in[i].first);
		M = max(M, in[i].second);
	}
	res = min(res, M);
	printf("%I64d\n", res);
}