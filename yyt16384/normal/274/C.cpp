#include <cmath>
#include <cstdio>
#include <set>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 105;
const double EPS = 1e-8;

namespace geometry
{

struct Point
{
	double x, y;

	Point() {}
	Point(double x_, double y_) : x(x_), y(y_) {}
};

inline Point operator+(const Point &x, const Point &y)
{
	return Point(x.x + y.x, x.y + y.y);
}

inline Point operator-(const Point &x, const Point &y)
{
	return Point(x.x - y.x, x.y - y.y);
}

inline Point operator*(const Point &x, double y)
{
	return Point(x.x * y, x.y * y);
}

inline Point operator*(double x, const Point &y)
{
	return y * x;
}

inline Point operator/(const Point &x, double y)
{
	return x * (1 / y);
}

inline bool operator<(const Point &x, const Point &y)
{
	return x.x + EPS < y.x || (x.x < y.x + EPS && x.y + EPS < y.y);
}

inline double cross(const Point &x, const Point &y)
{
	return x.x * y.y - x.y * y.x;
}

inline double cross(const Point &x, const Point &y, const Point &z)
{
	return cross(y - x, z - x);
}

inline double dot(const Point &x, const Point &y)
{
	return x.x * y.x + x.y * y.y;
}

inline double dot(const Point &x, const Point &y, const Point &z)
{
	return dot(y - x, z - x);
}

inline Point rotate_ccw(const Point &x)
{
	return Point(-x.y, x.x);
}

inline double len2(const Point &x)
{
	return dot(x, x);
}

inline double dist2(const Point &x, const Point &y)
{
	return len2(y - x);
}

}

int n;
geometry::Point a[MAXN];
std::set<geometry::Point> ps;

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf%lf", &a[i].x, &a[i].y);
		ps.insert(a[i]);
	}
}

void solve()
{
	double ans = -1e100;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			for (int k = j + 1; k < n; ++k)
			{
				double d1 = geometry::dot(a[i], a[j], a[k]);
				double d2 = geometry::dot(a[j], a[k], a[i]);
				double d3 = geometry::dot(a[k], a[i], a[j]);
				if (d1 < -EPS || d2 < -EPS || d3 < -EPS)
					continue;
				if (d1 < EPS || d2 < EPS || d3 < EPS)
				{
					geometry::Point v;
					if (d1 < EPS)
						v = a[j] + a[k] - a[i];
					else if (d2 < EPS)
						v = a[k] + a[i] - a[j];
					else if (d3 < EPS)
						v = a[i] + a[j] - a[k];
					if (ps.find(v) == ps.end())
						continue;
				}
				geometry::Point x1 = (a[i] + a[j]) / 2;
				geometry::Point x2 = x1 + geometry::rotate_ccw(a[j] - a[i]);
				geometry::Point y1 = (a[i] + a[k]) / 2;
				geometry::Point y2 = y1 + geometry::rotate_ccw(a[k] - a[i]);
				double u = cross(x1, y1, y2);
				double v = cross(x2, y1, y2);
				geometry::Point o = x1 + (x2 - x1) / (u - v) * u;
				double t = geometry::dist2(o, a[i]);
				bool flag = true;
				for (int p = 0; p < n; ++p)
				{
					double tmp = geometry::dist2(o, a[p]);
					if (tmp + EPS < t)
					{
						flag = false;
						break;
					}
				}
				if (flag && t > ans)
					ans = t;
			}
	if (ans < 0)
		printf("-1\n");
	else
		printf("%f\n", sqrt(ans));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("274C.in", "r", stdin);
	freopen("274C.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}