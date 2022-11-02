#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;
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
	double det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	double dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	double alpha() const {
		return atan2(y, x);
	}
	Point rot90() const {
		return Point(-y, x);
	}
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	void write() const {
		printf("(%lf,%lf)", x, y);
	}
	double abs() {
		return hypot(x, y);
	}
	double abs2() {
		return x * x + y * y;
	}
	Point unit() {
		return *this / abs();
	}
	double distTo(const Point&p) const {
		return hypot(x - p.x, y - p.y);
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

const double EPS = 1e-10; //you should change it according to problem, nevertheless, it mustn't be a constant value some times.
inline int sign(double a) {
	return a < -EPS ? -1 : a > EPS;
}

#define crossOp(p1,p2,p3) (sign(cross(p1,p2,p3)))

Point isSS(Point p1, Point p2, Point q1, Point q2) {
	double a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

typedef pair<double, double> dpair;

vector<Point> make(Point a, Point b) {
	vector<Point> ret;
	ret.push_back(a);
	ret.push_back(b);
	return ret;
}

vector<Point> tanCP(Point c, double r, Point p) {
	double x2 = (p - c).abs2();
	double d2 = x2 - r * r;
	vector<Point> ret;
	if (d2 < -EPS)
		return ret;
	if (r <= EPS) {
		ret.push_back(c);
		ret.push_back(c);
		return ret;
	}
	d2 = max(d2, 0.);
	Point q1 = c + (p - c) * (r * r / x2);
	Point q2 = (p - c).rot90() * (-r * sqrt(d2) / x2);
	ret.push_back(q1 - q2);
	ret.push_back(q1 + q2);
	return ret;
}

vector<vector<Point> > tanCC(Point c1, double r1, Point c2, double r2) {
	vector<vector<Point> > ret;
	if (fabs(r1 - r2) <= EPS) {
		Point dir = (c2 - c1).unit().rot90() * r1;
		ret.push_back(make(c1 + dir, c2 + dir));
		ret.push_back(make(c1 - dir, c2 - dir));
	} else {
		Point p = (c2 * r1 - c1 * r2) / (r1 - r2);
		vector<Point> ps = tanCP(c1, r1, p);
		vector<Point> qs = tanCP(c2, r2, p);
		for (int i = 0; i < ps.size() && i < qs.size(); ++i) {
			ret.push_back(make(ps[i], qs[i]));
		}
	}
	return ret;
}

vector<Point> isCC(Point c1, double r1, Point c2, double r2) {
	double d = c1.distTo(c2);
	if (d > r1 + r2 + EPS || d <= fabs(r1 - r2) - EPS)
		return vector<Point>();
	double w = (r1 * r1 + d * d - r2 * r2) / (2 * d);
	double h = sqrt(max(r1 * r1 - w * w, 0.0));

	Point at = c1 + (c2 - c1) * (w / d);
	Point dir = (c2 - c1).rot90() * (h / d);
	vector<Point> ps;
	ps.push_back(at - dir);
	ps.push_back(at + dir);
	return ps;
}

bool inCP(Point p, double r, Point q) {
	return p.distTo(q) <= r + EPS;
}

bool checkCommon(vector<Point> ps, vector<double> rs) {
	vector<Point> chk = ps;
	for (int i = 0; i < ps.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			vector<Point> is = isCC(ps[i], rs[i], ps[j], rs[j]);
			chk.insert(chk.end(), is.begin(), is.end());
		}
	}

	for (int i = 0; i < chk.size(); ++i) {
		bool ok = true;
		for (int j = 0; j < ps.size(); ++j) {
			if (!inCP(ps[j], rs[j], chk[i]))
				ok = false;
		}
		if (ok)
			return true;
	}
	return false;
}

int main() {
	double a, b; //alan:cinema->shop->house bob:cinea->house
	cin >> a >> b;
	Point cinema, house, shop;
	cinema.read(), house.read(), shop.read();
	double maxA = cinema.distTo(shop) + shop.distTo(house) + a;
	double maxB = cinema.distTo(house) + b;
	if (maxB > cinema.distTo(shop) + shop.distTo(house) - EPS) {
		//bob can go to shop, so they can be together! :)
		printf("%0.10lf\n", min(maxA, maxB));
		return 0;
	}
	//binary search the answer
	double l = 0, r = min(maxA, maxB) + 0.1;
	while (l + 1e-10 < r) {
		double m = (l + r) / 2;
		double remA = maxA - shop.distTo(house) - m;
		double remB = maxB - m;
		//check whether this three circle has common point
		vector<Point> ps;
		ps.push_back(cinema), ps.push_back(shop), ps.push_back(house);
		vector<double> rs;
		rs.push_back(m), rs.push_back(remA), rs.push_back(remB);
		if (checkCommon(ps, rs))
			l = m;
		else
			r = m;
	}

	printf("%0.10lf\n", l);
	return 0;
}