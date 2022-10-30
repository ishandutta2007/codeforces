/*
 * p3.cpp
 *
 *  Created on: 2011-2-26
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS=1e-6;

inline int compare(double a,double b){
	return a<b-EPS?-1:a>b+EPS;
}

struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y):
		x(_x),y(_y){}
	Point operator-(Point p)const{
		return Point(x-p.x,y-p.y);
	}
	double det(Point p)const{
		return x*p.y-y*p.x;
	}
	double dist(Point p)const{
		return hypot(x-p.x,y-p.y);
	}
	void read(){
		scanf("%lf%lf",&x,&y);
	}
	bool operator<(const Point&p)const{
		int c=compare(x,p.x);
		if(c)return c==-1;
		return compare(y,p.y)==-1;
	}
};

double cross(Point p1,Point p2,Point p3){
	return (p2-p1).det(p3-p1);
}

int crossOp(Point p1,Point p2,Point p3){
	return compare(cross(p1,p2,p3),0);
}

Point getIntersect(const Point&p1,const Point&p2,const Point&q1,const Point&q2){
	double a1=cross(q1,q2,p1),a2=-cross(q1,q2,p2);
	return Point( (p1.x*a2+p2.x*a1)/(a1+a2) , (p1.y*a2+p2.y*a1)/(a1+a2) );
}

bool isIntersect(const Point&p1,const Point&p2,const Point&q1,const Point&q2){
	return crossOp(p1,p2,q1)*crossOp(p1,p2,q2) < 0 &&
		   crossOp(q1,q2,p1)*crossOp(q1,q2,p2) < 0;
}

struct Triangle{
	Point ps[3];
	void read(){
		for (int i = 0; i < 3; ++i) {
			ps[i].read();
		}
		if(crossOp(ps[0],ps[1],ps[2])<0){
			swap(ps[1],ps[2]);
		}
	}

	bool contain(Point p){
		for (int i = 0; i < 3; ++i) {
			if(crossOp(ps[i],ps[(i+1)%3],p)<=0)
				return false;
		}
		return true;
	}
};

const int MAX_N=100;
Triangle triangles[MAX_N];
int nTriangles;
int main(){
//	freopen("in","r",stdin);
	cin>>nTriangles;
	for (int it = 0; it < nTriangles; ++it) {
		triangles[it].read();
	}

	Point xs[10000];

	double ans=0;
	for (int tIt = 0; tIt < nTriangles; ++tIt) {
		for (int at = 0; at < 3; ++at) {
			Point p1=triangles[tIt].ps[at],
				  p2=triangles[tIt].ps[(at+1)%3];
			if(p1.x>p2.x)swap(p1,p2);
			int cnt=0;
			for (int other = 0; other < nTriangles; ++other)if(other!=tIt) {
				for (int at2 = 0; at2 < 3; ++at2) {
					Point q1=triangles[other].ps[at2];
					Point q2=triangles[other].ps[(at2+1)%3];
					if(isIntersect(p1,p2,q1,q2)){
						Point ins=getIntersect(p1,p2,q1,q2);
						xs[cnt++]=ins;
					}
				}
			}
			xs[cnt++]=p1;xs[cnt++]=p2;
			sort(xs,xs+cnt);
			for (int l = 0; l < cnt-1 ; ++l) {
				Point pl=xs[l],pr=xs[l+1];
				Point pmid=Point((pl.x+pr.x)/2,(pl.y+pr.y)/2);
				bool ok=true;
				for (int other = 0; other < nTriangles; ++other) {
					if(triangles[other].contain(pmid)){
						ok=false;
						break;
					}
				}
				if(ok)
					ans+=pl.dist(pr);
			}
		}
	}
	printf("%0.10lf\n",ans);
}