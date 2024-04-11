#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Point {
	double x, y, z;
	Point() {
	}
	void read() {
		cin >> x >> y >> z;
	}
	Point(double x, double y, double z) :
			x(x), y(y), z(z) {
	}
	Point operator+(const Point&o) const {
		return Point(x + o.x, y + o.y, z + o.z);
	}
	Point operator-(const Point&o) const {
		return Point(x - o.x, y - o.y, z - o.z);
	}
	Point operator*(double o) const {
		return Point(x * o, y * o, z * o);
	}
	Point operator/(double f) {
		return Point(x / f, y / f, z / f);
	}
	double abs() {
		return sqrt(abs2());
	}
	double abs2() {
		return x * x + y * y + z * z;
	}
	double distTo(const Point&o) const {
		return (*this - o).abs();
	}
	double dot(Point p) {
		return x * p.x + y * p.y + z * p.z;
	}
	Point det(Point p) {
		return Point(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
	}
	void write() {
		cout << x << " " << y << " " << z << endl;
	}
};
Point A, v;
double R;
int n;
const int MAX_N = 100 + 10;
const double EPS = 1e-12;

double evalCircle(Point o, double r) {
	double L = 0, R = 1e9;
	while (L + 1e-10 < R) {
		double M1 = (L * 2 + R) / 3, M2 = (L + R * 2) / 3;
		if ((A + v * M1).distTo(o) < (A + v * M2).distTo(o))
			R = M2;
		else
			L = M1;
	}
	double c = (L + R) / 2;
	if ((A + v * c).distTo(o) > r + EPS)
		throw 1;
	L = 0, R = c;
	while (L + 1e-10 < R) {
		double M = (L + R) / 2;
		if ((A + v * M).distTo(o) <= r + EPS)
			R = M;
		else
			L = M;
	}
	return R;
}

Point proj(Point p1, Point p2, Point q) { //projection
	return p1 + (p2 - p1) * (p2 - p1).dot(q - p1) / (p2 - p1).abs2();
}

double distSP(Point q, Point p1, Point p2) {
	Point pj = proj(p1, p2, q);
	if ((pj - p1).dot(pj - p2) <= EPS)
		return pj.distTo(q);
	else
		return min(q.distTo(p1), q.distTo(p2));
}

double evalSegment(Point p1, Point p2) {
	//still can use ternary search?
	double L = 0, R = 1e9;
	while (L + 1e-10 < R) {
		double M1 = (L * 2 + R) / 3, M2 = (L + R * 2) / 3;
		if (distSP((A + v * M1), p1, p2) < distSP((A + v * M2), p1, p2))
			R = M2;
		else
			L = M1;
	}
	double c = (L + R) / 2;
	if (distSP((A + v * c), p1, p2) > ::R + EPS)
		throw 1;
	L = 0, R = c;
	while (L + 1e-10 < R) {
		double M = (L + R) / 2;
		if (distSP((A + v * M), p1, p2) <= ::R + EPS)
			R = M;
		else
			L = M;
	}
	return R;
}

double ans;

struct Mine {
	Point o;
	double r;
	vector<Point> spikes;
	void read() {
		o.read();
		cin >> r;
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			Point p;
			p.read();
			spikes.push_back(p);
		}
	}
	void eval() {
		try {
			ans = min(ans, evalCircle(o, r + R));
		} catch (int e) {
		}
		for (vector<Point>::iterator e = spikes.begin(); e != spikes.end(); ++e) {
			try {
				ans = min(ans, evalSegment(o, o + *e));
			} catch (int e) {
			}
		}
	}
};
Mine mines[MAX_N];

int main() {
	A.read(), v.read();
	cin >> R;
	int n;
	cin >> n;
	ans = 1e9;
	for (int i = 0; i < n; ++i) {
		mines[i].read();
		mines[i].eval();
	}
	if (ans > 1e8) {
		puts("-1");
	} else {
		printf("%0.10lf\n", ans);
	}
	return 0;
}