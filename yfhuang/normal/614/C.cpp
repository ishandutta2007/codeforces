//
//  main.cpp
//  C
//
//  Created by  on 16/1/15.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define PI 3.1415926

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};

typedef Point Vector;

Vector operator + (Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}

Vector operator - (Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}

Vector operator * (Vector a,double p){return Vector(a.x*p,a.y*p);}

Vector operator / (Vector a,double p){return Vector(a.x/p,a.y/p);}

const double eps=1e-10;

int dcmp(double x){
    if(fabs(x)<eps) return 0;else return x<0?-1:1;
}

double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}

double Length(Vector a){
    return sqrt(Dot(a,a));
}

double Cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

double DistanceToSegment(Point P,Point A,Point B){
    if(A.x==B.x&&A.y==B.y) return Length(P-A);
    Vector v1=B-A,v2=P-A,v3=P-B;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}

Point t[100005];

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    Point P;
    scanf("%lf%lf",&P.x,&P.y);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&t[i].x,&t[i].y);
    double mi=1e20,ma=0;
    for(int i=1;i<=n;i++)
        ma=max(ma,Length(t[i]-P));
    for(int i=1;i<n;i++)
        mi=min(mi,DistanceToSegment(P, t[i], t[i+1]));
    mi=min(mi,DistanceToSegment(P, t[1], t[n]));
    //printf("%lf %lf\n",mi,ma);
    printf("%.10lf\n",PI*(ma*ma-mi*mi));
    return 0;
}