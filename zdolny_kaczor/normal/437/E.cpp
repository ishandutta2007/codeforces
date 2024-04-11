# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 222;
const int MOD = 1e9 + 7;
typedef pair <int, int> point;
long long operator * (point a, point b)
{
	return a.first * (long long) b.second - a.second * (long long) b.first;
}
long long operator % (point a, point b)
{
	return a.first * (long long) b.first + a.second * (long long) b.second;
}
point operator - (point a, point b)
{
	return make_pair(a.first - b.first, a.second - b.second);
}
bool collinear(point a, point b, point c)
{
	return (a - b) * (b - c) == 0;
}
int sign(long long a)
{
	if (a > 0)
		return 1;
	else if (a == 0)
		return 0;
	else
		return -1;
}
bool splits(point a, point b, point c, point d)
{
	return sign((a - b) * (a - c)) * sign((a - b) * (a - d)) != 1;
}
bool between(point a, point b, point c)
{
	return (b - a) % (b - c) <= 0;
}
bool onsegment(point a, point b, point c)
{
	return collinear(a, b, c) && between(a, b, c);
}
bool intersects(point a, point b, point c, point d)
{
	if (collinear(a, b, d) && collinear(a, b, c))
		return between(a, c, b) || between(a, d, b) || between(c, a, d) || between(c, b, d);
	else
		return splits(a, b, c, d) && splits(c, d, a, b);
}
bool isonray(point a, point b, point c)
{
// 	printf("is on ray ? (%d, %d), (%d, %d), (%d, %d)", a.first, a.second, b.first, b.second, c.first, c.second);
	bool ret = (a - b) * (a - c) == 0 && (a - b) % (a - c) >= 0;
// 	if (ret)
// 		printf("yes\n");
// 	else
// 		printf("no\n");
	return ret;
}
bool good[MN][MN];
point polygon[MN];
int dp[MN][MN];
bool isinangle(point a, point b, point c, point x)
{
	b = a - b;
	c = a - c;
	x = a - x;
	if (b * c >= 0)
		return b * x >= 0 && x * c >= 0;
	else
		return b * x >= 0 || x * c >= 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &polygon[i].first, &polygon[i].second);
	long long area = 0;
	for (int i = 1; i < n - 1; ++i)
		area += (polygon[0] - polygon[i]) * (polygon[0] - polygon[i + 1]);
	if (area > 0)
		reverse(polygon, polygon + n);
	for (int i = 0; i < n; ++i)
		good[i][i + 1] = true;
	for (int i = 0; i < n; ++i)
		for (int k = i + 2; k < n; ++k)
		{
			bool OK = true;
			if (isonray(polygon[i], polygon[(i + 1) % n], polygon[k]) ||
			isonray(polygon[i], polygon[(i + n - 1) % n], polygon[k]) ||
			isonray(polygon[k], polygon[(k + 1) % n], polygon[i]) ||
			isonray(polygon[k], polygon[(k + n - 1) % n], polygon[i]))
			{
// 				printf("%d - %d is on ray\n", i, k);
				OK = false;
			}
			if (!isinangle(polygon[i], polygon[(i + n - 1) % n], polygon[(i + 1) % n], polygon[k]))
				OK = false;
			if (!isinangle(polygon[k], polygon[(k + n - 1) % n], polygon[(k + 1) % n], polygon[i]))
				OK = false;
			for (int l = 0; l < n; ++l)
				if (l != i && l != k && (l + 1) % n != i && (l + 1) % n != k)
					if (intersects(polygon[i], polygon[k], polygon[l], polygon[(l + 1) % n]))
					{
						OK = false;
						break;
					}
			good[i][k] = good[k][i] = OK;
		}
	for (int i = 0; i < n - 1; ++i)
		dp[i][i + 1] = 1;
	for (int dist = 2; dist < n; ++dist)
		for (int i = 0; i + dist < n; ++i)
			for (int l = i + 1; l < i + dist; ++l)
				if (good[i][l] && good[l][i + dist])
					dp[i][i + dist] = (dp[i][i + dist] + (long long) dp[i][l] * dp[l][i + dist]) % MOD;
	printf("%d\n", dp[0][n - 1]);
}