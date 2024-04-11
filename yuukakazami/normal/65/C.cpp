/*
 * c.cpp
 *
 *  Created on: 2011-3-6
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const double EPS=1e-6;

int compare(double a,double b){
	return a<b-EPS?-1:a>b+EPS;
}

struct Point{
	double x,y,z;
	Point(){}
	Point(double _x,double _y,double _z):
		x(_x),y(_y),z(_z){}
	void read(){
		scanf("%lf%lf%lf",&x,&y,&z);
	}
	Point operator-(const Point&p){
		return Point(x-p.x,y-p.y,z-p.z);
	}
	Point operator+(const Point&p){
		return Point(x+p.x,y+p.y,z+p.z);
	}
	Point operator*(double d){
		return Point(x*d,y*d,z*d);
	}
	double abs(){
		return sqrt(x*x+y*y+z*z);
	}
};

vector<Point> polyline;
Point me;
double myV,opV;
int n;

Point where(double curTime){
	for (int at = 0; at < n; ++at) {
		double dist=(polyline[at]-polyline[at+1]).abs();
		if(dist/opV >= curTime){
			Point dir=polyline[at+1]-polyline[at];
			return polyline[at]+dir*(curTime/(dist/opV));
		}
		curTime-=dist/opV;
	}
	return polyline.back();
}

bool check(double curTime){
	Point whereBall=where(curTime);
	double farest=curTime*myV;
	return farest >= (me-whereBall).abs();
}

int main(){
	cin>>n;
	for (int i = 0; i <= n; ++i) {
		Point p;p.read();
		polyline.push_back(p);
	}
	cin>>myV>>opV;
	me.read();

	double totalDist=0;
	for (int i = 0; i < n; ++i) {
		totalDist += (polyline[i]-polyline[i+1]).abs();
	}

	if(compare((me-polyline[n]).abs()/myV,totalDist/opV)>0){
		puts("NO");
		return 0;
	}
	puts("YES");
	double left=0,right=1e9;
	for (int step = 0; step < 100; ++step) {
		double mid=(left+right)/2;
		if(check(mid))
			right=mid;
		else
			left=mid;
	}
	printf("%0.10lf\n",left);
	Point at= where(left);
	printf("%0.10lf %0.10lf %0.10lf\n",at.x,at.y,at.z);
}