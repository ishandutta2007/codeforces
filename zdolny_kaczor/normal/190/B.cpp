# include <cstdio>
# include <cmath>
# include <set>
using namespace std;
int main()
{
	int x1, y1, r1, x2, y2, r2;
	scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
	long double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	long double res;
	if (dist < abs(r1 - r2))
		res = abs(dist - abs(r1 - r2));
	else if (dist < r1 + r2)
		res = 0;
	else
		res = dist - r1 - r2;
	printf("%lf\n", (double) res / 2);
}