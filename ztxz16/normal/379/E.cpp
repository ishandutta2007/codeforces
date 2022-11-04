#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define eps 1e-9

int FASTBUFFER;

using namespace std;

struct point
{
	double x, y;
	
	point () {}
	
	point (double x, double y) : x(x), y(y) {}
};

double cross(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int crossOp(point a, point b, point c)
{
	double now = cross(a, b, c);
	if (now > 0 - eps && now < eps)
		return 0;
	if (now > 0)
		return 1;
	return -1;
}

point isSS(const point &p1, const point &p2, const point &p3, const point &p4)
{
    double k;
	k=((p4.x-p3.x)*(p1.y-p3.y)-(p4.y-p3.y)*(p1.x-p3.x))/((p4.y-p3.y)*(p2.x-p1.x)-(p4.x-p3.x)*(p2.y-p1.y));
    return point(p1.x+k*(p2.x-p1.x), p1.y+k*(p2.y-p1.y));
}

vector <point> convexCut (const vector <point> &ps, point q1, point q2)
{
	vector <point> qs;
	int n = ps.size();
	for (int i = 0; i < n; i++)
	{
		point p1 = ps[i], p2 = ps[(i + 1) % n];
		int d1 = crossOp(q1, q2, p1), d2 = crossOp(q1, q2, p2);
		if (d1 >= 0)
			qs.push_back(p1);
		if (d1 * d2 < 0)
			qs.push_back(isSS(p1, p2, q1, q2));
	}
	
	return qs;
}

vector <point> tb[505];
int n, k, i, j, l;
double s[505], temp[505], a[505], ans;

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= k; i++)
	{
		s[i] = 1000.0;
		tb[i].push_back(point((double)(i - 1), 0.0));
		tb[i].push_back(point((double)(i), 0.0));
		tb[i].push_back(point((double)(i), 1000.0));
		tb[i].push_back(point((double)(i - 1), 1000.0));
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= k; j++)
			temp[j] = s[j];
		for (j = 0; j <= k; j++)
			scanf("%lf", &a[j]);
		ans = 0;
		for (j = 1; j <= k; j++)
		{
			tb[j] = convexCut(tb[j], point((double)(j - 1), a[j - 1]), point((double)(j), a[j]));
			s[j] = 0;
			for (l = 1; l < tb[j].size() - 1; l++)
				s[j] += cross(tb[j][0], tb[j][l], tb[j][l + 1]);
			s[j] = fabs(s[j]) * 0.5;
			ans += temp[j] - s[j];
		}
		
		printf("%.10f\n", ans);
	}
	
	return 0;
}