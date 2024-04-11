#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-8;
inline int sign(double a) {
	return a < -EPS ? -1 : a > EPS;
}

struct Point {
	double x, y;
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

int n, h, f;
const int MAX_N = 500 + 10;
int l[MAX_N], r[MAX_N];
vector<Point> ps[MAX_N];

vector<Point> convexCut(const vector<Point>&ps, Point q1, Point q2) {
	vector<Point> qs;
	int n = ps.size();
	for (int i = 0; i < n; ++i) {
		Point p1 = ps[i], p2 = ps[(i + 1) % n];
		int d1 = crossOp(q1,q2,p1), d2 = crossOp(q1,q2,p2);
		if (d1 >= 0)
			qs.push_back(p1);
		if (d1 * d2 < 0)
			qs.push_back(isSS(p1, p2, q1, q2));
	}
	return qs;
}

double calcArea(const vector<Point>&ps) {
	int n = ps.size();
	double ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += ps[i].det(ps[(i + 1) % n]);
	}
	return ret / 2;
}

vector<Point> convexHull(vector<Point> ps) {
	int n = ps.size();
	if (n <= 1)
		return ps;
	sort(ps.begin(), ps.end());
	vector<Point> qs;
	for (int i = 0; i < n; qs.push_back(ps[i++])) {
		while (qs.size() > 1 && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
			qs.pop_back();
	}
	for (int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--])) {
		while (qs.size() > t && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
			qs.pop_back();
	}
	qs.pop_back();
	return qs;
}

vector<Point> build(double l, double r, double l2, double r2) {
	vector<Point> ps;
	ps.push_back(Point(l, h));
	ps.push_back(Point(r, h));
	ps.push_back(Point(r2, 0));
	ps.push_back(Point(l2, 0));
	return convexHull(ps);
}

double is(vector<Point> ps, vector<Point> qs) {
	for (int i = 0; i < ps.size(); ++i) {
		qs = convexCut(qs, ps[i], ps[(i + 1) % ps.size()]);
	}
	return calcArea(qs);
}

int main() {
	cin >> n >> h >> f;
	vector<vector<Point> > low, up;
	for (int i = 0; i < n; ++i) {
		double l, r;
		cin >> l >> r;
		double l2 = l / (f - h) * f, r2 = r / (f - h) * f;
		low.push_back(build(l, r, l2, r2));
		double l3 = l / (f - h) * (f + h), r3 = r / (f - h) * (f + h);
		up.push_back(build(l3, r3, l2, r2));
	}
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += calcArea(low[i]);
		ans += calcArea(up[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans -= is(low[i], up[j]);
		}
	}
	ans *= 2;
	printf("%0.10lf\n", ans);
	return 0;
}