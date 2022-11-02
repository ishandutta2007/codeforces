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

bool inMid(Point a, Point m, Point b, bool inc = false) {
	return crossOp(a, m, b) == 0 && sign((m - a).dot(m - b)) < (inc ? 1 : 0);
}

bool crsSS(Point p1, Point p2, Point q1, Point q2) { //strict
	return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) < 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) < 0;
}

bool crsII(double l, double r, double L, double R) {
	if (l > r)
		swap(l, r);
	if (L > R)
		swap(L, R);
	return r + EPS > L && R + EPS > l;
}

bool crsTSS(Point p1, Point p2, Point q1, Point q2) {
	return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) <= 0 && crossOp(q1, q2, p1) * crossOp(q1, q2, p2) <= 0 && crsII(p1.x, p2.x, q1.x, q2.x) && crsII(p1.y, p2.y, q1.y, q2.y);
}

Point proj(Point p1, Point p2, Point q) {
	return p1 + (p2 - p1) * (p2 - p1).dot(q - p1) / (p2 - p1).abs2();
}

vector<Point> convexCut(const vector<Point>&ps, Point q1, Point q2) {
	vector<Point> qs;
	int n = ps.size();
	for (int i = 0; i < n; ++i) {
		Point p1 = ps[i], p2 = ps[(i + 1) % n];
		int d1 = crossOp(q1, q2, p1), d2 = crossOp(q1, q2, p2);
		if (d1 >= 0)
			qs.push_back(p1);
		if (d1 * d2 < 0)
			qs.push_back(isSS(p1, p2, q1, q2));
	}
	return qs;
}

bool isInt(double x) {
	return fabs(x - int(x)) <= EPS;
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
		while (qs.size() > 1 && crossOp(qs[qs.size() - 2], qs.back(), ps[i]) <= 0)
			qs.pop_back();
	}
	for (int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--])) {
		while (qs.size() > t && crossOp(qs[qs.size() - 2], qs.back(), ps[i]) <= 0)
			qs.pop_back();
	}
	qs.pop_back();
	return qs;
}

const double BIG = 1e6 + 1;
typedef long long int64;

int main() {
	int n;
	cin >> n;
	vector<Point> ps(n);
	for (int i = 0; i < n; ++i) {
		ps[i].read();
	}
	vector<Point> qs(4);
	qs[0] = Point(0, 0), qs[1] = Point(BIG, 0), qs[2] = Point(BIG, BIG), qs[3] = Point(0, BIG);
	for (int i = 0; i < n; ++i) {
		qs = convexCut(qs, ps[(i + 1) % n], ps[i]);
	}
	if (qs.size() <= 0) {
		puts("0");
		return 0;
	}
	Point p1 = ps[0], p2 = ps[1];
	for (int i = 0; i < qs.size(); ++i) {
		Point q1 = qs[i], q2 = qs[(i + 1) % qs.size()];
		if (inMid(p1, q1, p2, true) && inMid(p1, q2, p2, true)) {
			//calculate how many integer point on q1-q2
			double L = q1.x, R = q2.x;
			if (L > R)
				swap(L, R);
			int ans = 0;
			for (int x = int(L); x <= R; ++x)
				if (x >= L) {
					if (p1.x == p2.x)
						++ans;
					else {
						int64 y = int64(p2.x - x) * p1.y + int64(x - p1.x) * p2.y;
						if (y % int64(p2.x - p1.x) == 0)
							++ans;
					}
				}
			cout << ans << endl;
			return 0;
		} else if (inMid(p1, q1, p2, true)) {
			if (isInt(q1.x) && isInt(q2.x)) {
				cout << 1 << endl;
				return 0;
			}
		}
	}
	puts("0");
	return 0;
}