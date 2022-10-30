/*
 * E. Hide-and-Seek.cpp
 *
 *  Created on: 2011-8-20
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
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
	double dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	double abs2() {
		return x * x + y * y;
	}
	void write() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

const double EPS = 1e-6;
inline int sign(double a) {
	return a < -EPS ? -1 : a > EPS;
}

#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

Point isSS(Point p1, Point p2, Point q1, Point q2) {
	double a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

bool inMid(Point a, Point m, Point b, bool inc = false) {
	return crossOp(a,m,b) == 0 && sign((m - a).dot(m - b)) < (inc ? 1 : 0);
}

bool crsSS(Point p1, Point p2, Point q1, Point q2) { //strict
	return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) < 0 &&
			crossOp(q1,q2,p1) * crossOp(q1,q2,p2) < 0;
}

Point ref(Point p1, Point p2, Point q) {
	Point pj = p1 + (p2 - p1) * (p2 - p1).dot(q - p1) / (p2 - p1).abs2();
	return pj * 2 - q;
}

bool stop(Point p1, Point p2, Point q1, Point q2) {
	return crsSS(p1, p2, q1, q2) || inMid(p1, q1, p2) || inMid(p1, q2, p2);
}

int work() {
	Point st, tar;
	Point w0, w1, m0, m1;
	st.read(), tar.read();
	w0.read(), w1.read(), m0.read(), m1.read();
	//check if can see straight
	if (!stop(st, tar, w0, w1) && !crsSS(st, tar, m0, m1)) {
		if (inMid(st, m0, tar) && inMid(st, m1, tar))
			return 1;
		if (inMid(st, m0, tar) || inMid(st, m1, tar))
			return -10;
		return 1;
	}
	int c0 = crossOp(m0,m1,st), c1 = crossOp(m0,m1,tar);
	if (c0 != c1 || c0 == 0)
		return -1;
	Point r = ref(m0, m1, tar);
	Point is = isSS(st, r, m0, m1);
	if (!inMid(m0, is, m1, true))
		return -2;
	if (!stop(st, is, w0, w1) && !stop(is, tar, w0, w1))
		return 2;
	return -3;
}

int main() {
	cout << (work() > 0 ? "YES" : "NO") << endl;
	return 0;
}