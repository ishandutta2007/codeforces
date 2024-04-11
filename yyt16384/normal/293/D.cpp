#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int SZ = 2000005;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;

struct Point
{
	int x, y;
};

long long cross(const Point &x, const Point &y)
{
	return (long long)x.x * y.y - (long long)x.y * y.x;
}

int n;
Point a[MAXN];
int left[SZ];
int right[SZ];
int cc[SZ];

void init()
{
	const int SZ2 = 1000002;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].x += SZ2;
		a[i].y += SZ2;
	}

	long long sum = 0;
	for (int i = 0; i < n; ++i)
		sum += cross(a[i], a[(i + 1) % n]);
	if (sum < 0) std::reverse(a + 1, a + n);
}

void work(long long &cnt, double &sum)
{
	memset(left, INF, sizeof(left));
	memset(right, -INF, sizeof(right));
	for (int i = 0; i < n; ++i)
	{
		int x1 = a[i].x;
		int x2 = a[(i + 1) % n].x;
		int y1 = a[i].y;
		int y2 = a[(i + 1) % n].y;
		int minx = std::min(x1, x2);
		int maxx = std::max(x1, x2);
		for (int j = minx; j <= maxx; ++j)
		{
			double y = (double)(j - x1) / (x2 - x1) * (y2 - y1) + y1;
			if (x1 < x2) left[j] = (int)(y + 1 - EPS);
			if (x1 > x2) right[j] = (int)(y + EPS);
		}
	}

	cnt = 0;
	for (int i = 0; i < SZ; ++i)
		if (left[i] <= right[i])
			cnt += cc[i] = right[i] - left[i] + 1;
		else cc[i] = 0;

	double p1 = 0;
	double p2 = 0;
	double p3 = 0;
	sum = 0;
	for (int i = 0; i < SZ; ++i)
	{
		sum += cc[i] * p1;
		p3 += cc[i];
		p2 += 2 * p3 - cc[i];
		p1 += p2;
	}
}

void solve()
{
	long long cnt;
	double sumx, sumy;
	work(cnt, sumy);
	for (int i = 0; i < n; ++i)
		std::swap(a[i].x, a[i].y);
	std::reverse(a + 1, a + n);
	work(cnt, sumx);
	printf("%.12f\n", (sumx + sumy) / 2 / ((double)cnt * (cnt - 1) / 2));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9162.in", "r", stdin);
	freopen("9162.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}