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
	Point rot90() {
		return Point(-y, x);
	}
	void write() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

Point isSS(Point p1, Point p2, Point q1, Point q2) {
	double a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
	if (fabs(a1 + a2) <= EPS)
		throw 0;
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

bool inMid(Point a, Point m, Point b, bool inc = false) {
	return crossOp(a,m,b) == 0 && sign((m - a).dot(m - b)) < (inc ? 1 : 0);
}

bool crsSS(Point p1, Point p2, Point q1, Point q2) { //strict
	return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) < 0 && crossOp(q1,q2,p1) * crossOp(q1,q2,p2) < 0;
}

bool crsII(double l, double r, double L, double R) {
	if (l > r)
		swap(l, r);
	if (L > R)
		swap(L, R);
	return r + EPS > L && R + EPS > l;
}

bool crsTSS(Point p1, Point p2, Point q1, Point q2) {
	return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) <= 0 && crossOp(q1,q2,p1) * crossOp(q1,q2,p2) <= 0 && crsII(p1.x, p2.x, q1.x, q2.x) && crsII(p1.y, p2.y, q1.y, q2.y);
}

Point proj(Point p1, Point p2, Point q) {
	return p1 + (p2 - p1) * (p2 - p1).dot(q - p1) / (p2 - p1).abs2();
}

Point getCenter(Point p1, Point p2, Point p3) {
	Point q1 = (p1 + p2) / 2, q2 = q1 + (p2 - p1).rot90();
	Point m1 = (p1 + p3) / 2, m2 = m1 + (p3 - p1).rot90();
	return isSS(q1, q2, m1, m2);
}

int main() {
	int nT;
	cin >> nT;
	while (nT--) {
		Point a, b, c;
		a.read(), b.read(), c.read();
		Point ps[3] = { a, b, c };
		int perm[3] = { 0, 1, 2 };
		bool have = false;
		do {
			a = ps[perm[0]], b = ps[perm[1]], c = ps[perm[2]];
			Point t = b * 2 - a;
			try {
				Point p1 = getCenter(b, c, t);
				Point p2 = b * 2 - p1;
				Point p3 = a * 2 - p2;
				Point p4 = c * 2 - p1;
				Point qs[8] = { p1, p2, p3, p4, p1, p2, p3, p4 };
				bool has[3] = { };
				bool chk = true;
				for (int i = 0; i < 4; ++i) {
					has[crossOp(qs[i],qs[i+1],qs[i+2]) + 1] = true;
				}
				if (has[1] || (has[0] && has[2]))
					chk = false;
				for (int i = 0; i < 4; ++i) {
					if (crsSS(qs[i], qs[i + 1], qs[i + 2], qs[i + 3]))
						chk = false;
				}
				if (sign(p1.distTo(p2) - p1.distTo(p4)) != 0)
					chk = false;
				if (sign(p1.distTo(p2) - p2.distTo(p3)) != 0)
					chk = false;
				if (chk) {
					printf("YES\n");
					for (int i = 0; i < 4; ++i) {
						printf("%0.10lf %0.10lf ", qs[i].x, qs[i].y);
					}
					puts("");
					have = true;
					break;
				}
			} catch (int e) {
			}
		} while (next_permutation(perm, perm + 3));
		if (!have) {
			puts("NO");
			puts("");
		}
	}
	return 0;
}