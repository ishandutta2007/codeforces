# include <cstdio>
# include <set>
using namespace std;
typedef pair <long double, long double> ran;
ran mul(ran a, ran b)
{
	long double x = a.first * b.first, y = a.first * b.second, z = a.second * b.first, t = a.second * b.second;
	return make_pair(min(min(x, y), min(z, t)), max(max(x, y), max(z, t)));
}
bool inter(ran a, ran b)
{
	return a.first <= b.second && a.second >= b.first;
}
ran around (long double cen, long double r)
{
	return make_pair(cen - r, cen + r);
}
int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	long double min = 0, max = 1e9 + 44;
	while (max - min > 1e-10)
	{
		long double med = (min + max) / 2;
		if (inter(mul(around(a, med), around(d, med)), mul(around(b, med), around(c, med))))
			max = med;
		else
			min = med;
	}
	printf("%.11lf\n", (double) min);
}