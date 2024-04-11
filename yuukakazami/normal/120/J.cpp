#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
using namespace std;

const double EPS = 1e-8;
inline int sign(double a) {
	return a < -EPS ? -1 : a > EPS;
}

struct Point {
	double x, y;
	int i, j;

	Point() {
	}
	Point(double _x, double _y) :
			x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator*(double d) const {
		return Point(x * d, y * d);
	}
	Point operator/(double d) const {
		return Point(x / d, y / d);
	}
	bool operator<(const Point&p) const {
		int c = sign(x - p.x);
		if (c)
			return c == -1;
		return sign(y - p.y) == -1;
	}
	double dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	double det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	double alpha() const {
		return atan2(y, x);
	}
	double distTo(const Point&p) const {
		double dx = x - p.x, dy = y - p.y;
		return hypot(dx, dy);
	}
	double alphaTo(const Point&p) const {
		double dx = x - p.x, dy = y - p.y;
		return atan2(dy, dx);
	}
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	double abs() {
		return hypot(x, y);
	}
	double abs2() {
		return x * x + y * y;
	}
	void write() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

Point isSS(Point p1, Point p2, Point q1, Point q2) {
	double a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

const int MAX_N = int(1e5) * 4;
Point ps[MAX_N];

Point p1, p2;
double ans;

bool cmpY(Point p1, Point p2) {
	return p1.y < p2.y;
}

void solve(int l, int r) {
	if (r - l <= 3) {
		for (int i = l; i < r; ++i) {
			for (int j = i + 1; j < r; ++j) {
				if (ps[i].i != ps[j].i) {
					double d = ps[i].distTo(ps[j]);
					if (d < ans) {
						ans = d;
						p1 = ps[i], p2 = ps[j];
					}
				}
			}
		}
		return;
	}
	int m = (l + r) >> 1;
	solve(l, m);
	solve(m, r);

	double cm = ps[m].x;
	static Point qs[MAX_N];
	int cnt = 0;

	for (int i = l; i < r; ++i) {
		if (fabs(ps[i].x - cm) <= ans)
			qs[cnt++] = ps[i];
	}

	sort(qs, qs + cnt, cmpY);

	int last = 0;

	for (int i = 0; i < cnt; ++i) {
		while (qs[last].y + ans <= qs[i].y && last <= i)
			++last;
		for (int j = last; j < i; ++j) {
			if (qs[i].i != qs[j].i) {
				double d = qs[i].distTo(qs[j]);
				if (d < ans) {
					ans = d;
					p1 = qs[i], p2 = qs[j];
				}
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	int cur = 0;
	for (int i = 0; i < n; ++i) {
		Point p;
		p.read();
		for (int j = 0; j < 4; ++j) {
			Point np = p;
			if (j & 1)
				np.x *= -1;
			if (j & 2)
				np.y *= -1;
			np.i = i, np.j = j;
			ps[cur++] = np;
		}
	}

	n = cur;
	ans = 1e100;
	sort(ps, ps + n);
	solve(0, n);
	cout << p1.i + 1 << " " << p1.j + 1 << " " << p2.i + 1 << " " << (p2.j ^ 3) + 1 << endl;
}