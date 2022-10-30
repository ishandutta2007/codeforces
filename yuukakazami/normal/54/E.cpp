/*
 * E. Vacuum leaner.cpp
 *
 *  Created on: 2011-3-9
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const int MAX_N_POINTS = 40000 + 10;

struct Point {
	double x, y;
	Point(){}
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
	Point rot90() const {
		return Point(y, -x);
	}
	void read() {
		scanf("%lf %lf", &x, &y);
	}
	void write() const {
		printf("%lf %lf", x, y);
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

double EPS = 1e-10;
inline int sign(double x) {
	return x < EPS ? -1 : x > EPS;
}

#define crossOp(p1,p2,p3) (sign(cross(p1,p2,p3)))

Point isSS(Point p1, Point p2, Point q1, Point q2) {
	double a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
//	p1.write();cout<<" - ";p2.write();cout<<endl;
//	q1.write();cout<<" - ";q2.write();cout<<endl;
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

Point ps[MAX_N_POINTS * 2];
int nPs;
int main() {
	scanf("%d", &nPs);
	for (int i = 0; i < nPs; ++i) {
		ps[i].read();
	}
	if (crossOp(ps[0],ps[1],ps[2]) < 0) {
		reverse(ps, ps + nPs);
	}
	copy(ps, ps + nPs, ps + nPs);
	double ans = 1e100;
	for (int step = 0; step < 2; ++step) {
		double area = 0;
		int next = 1;
		for (int i = 0; i < nPs; ++i) {
			if (i > 0)
				area -= cross(ps[i-1],ps[i],ps[next]);
			Point dir = ps[i + 1] - ps[i];
			for (; ps[next + 1].dot(dir) > ps[next].dot(dir); ++next)
				area += cross(ps[i],ps[next],ps[next+1]);

//			cout<<i<<" "<<next<<endl;
//			dir.write();cout<<endl;
//			ps[next].write();cout<<endl;
//			(ps[next]+dir.rot90()).write();cout<<endl;
			Point is = isSS(ps[i], ps[i + 1], ps[next], ps[next] + dir.rot90());
			double triArea=fabs(cross(ps[i],is,ps[next])/2);
			double ret=triArea-area/2;
//			cout<<triArea<<" "<<area/2<<endl;
			ans = min(ans,ret);
		}

		for (int i = 0; i < nPs+nPs; ++i) {
			ps[i].x *= -1;
		}
		reverse(ps,ps+nPs+nPs);
	}

	printf("%0.10lf\n",ans);
}