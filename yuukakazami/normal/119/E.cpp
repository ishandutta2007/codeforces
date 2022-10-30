#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <cmath>
#include <vector>
using namespace std;

const double EPS = 1e-8;

int sign(double x) {
	return x < -EPS ? -1 : x > EPS;
}

namespace Geo3D {
	struct Point {
		double x, y, z;
		void read() {
			scanf("%lf%lf%lf", &x, &y, &z);
		}
		Point() {
		}
		Point(double _x, double _y, double _z) :
				x(_x), y(_y), z(_z) {
		}
		Point operator+(Point p) {
			return Point(x + p.x, y + p.y, z + p.z);
		}
		Point operator-(Point p) {
			return Point(x - p.x, y - p.y, z - p.z);
		}
		Point operator*(double f) {
			return Point(x * f, y * f, z * f);
		}
		Point operator/(double f) {
			return Point(x / f, y / f, z / f);
		}
		double dot(Point p) {
			return x * p.x + y * p.y + z * p.z;
		}
		Point det(Point p) {
			return Point(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
		}
		double abs() {
			return sqrt(x * x + y * y + z * z);
		}
		Point norm() {
			return *this / abs();
		}
		void write() {
			cout << x << " " << y << " " << z << endl;
		}
	};

	Point proj(Point p, Point o, Point q) {
		double d = (q - p).dot(o);
		return q - o * d;
	}
} // namespace Geo3D

namespace Geo2D {
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
			printf("%lf %lf", x, y);
		}
		double abs() {
			return hypot(x, y);
		}
		Point unit() {
			return *this / abs();
		}
		double distTo(const Point&p) const {
			return hypot(x - p.x, y - p.y);
		}
		bool operator<(const Point&p) const {
			int cx = sign(x - p.x);
			if (cx)
				return cx == -1;
			return sign(y - p.y) == -1;
		}
	};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) (sign(cross(p1,p2,p3)))

	Point isSS(Point p1, Point p2, Point q1, Point q2) {
		double a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
		return (p1 * a2 + p2 * a1) / (a1 + a2);
	}

	Point circleCenter(Point p1, Point p2, Point p3) {
		Point m1 = (p1 + p2) / 2, d1 = m1 + (p2 - p1).rot90();
		Point m2 = (p1 + p3) / 2, d2 = m2 + (p3 - p1).rot90();
		return isSS(m1, d1, m2, d2);
	}

	double minCircle(vector<Point> ps) {
		Point c(0, 0);
		double r = 0;
		random_shuffle(ps.begin(), ps.end());
		for (int i = 0; i < ps.size(); ++i) {
			if (ps[i].distTo(c) > r + EPS) {
				c = ps[i], r = 0;
				for (int j = 0; j < i; ++j) {
					if (ps[j].distTo(c) > r + EPS) {
						c = (ps[i] + ps[j]) / 2, r = ps[i].distTo(c);
						for (int k = 0; k < j; ++k) {
							if (ps[k].distTo(c) > r + EPS) {
								c = circleCenter(ps[i], ps[j], ps[k]), r = ps[i].distTo(c);
							}
						}
					}
				}
			}
		}
		return r;
	}
} // namespace Geo2D

double randDouble(double max) {
	return 1.0 * rand() / RAND_MAX * max;
}

using namespace Geo3D;
typedef Geo2D::Point Point2D;

int main() {
	int n, m;
	cin >> n >> m;
	vector<Point> ps(n);
	for (int i = 0; i < n; ++i) {
		ps[i].read();
	}
	for (int it = 0; it < m; ++it) {
		Point o;
		o.read();
		o = o.norm();
		Point p1(0, 0, 0);
		Point dx = proj(p1, o, Point(randDouble(100), randDouble(100), randDouble(100))).norm();
		Point dy = dx.det(o).norm();

		vector<Point2D> qs;
		for (int i = 0; i < n; ++i) {
			qs.push_back(Point2D(ps[i].dot(dx), ps[i].dot(dy)));
		}

		printf("%0.10lf\n", Geo2D::minCircle(qs));
	}
	return 0;
}