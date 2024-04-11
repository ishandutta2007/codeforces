#include<bits/stdc++.h>
#define eps 1E-9
using namespace std;


double x1y,y1x,x2y,y2x;

double dis(double x1,double y1,double x2,double y2)
{
    double x=x1-x2,y=y1-y2;
    return sqrt(x*x+y*y);
}

double solve(double x1,double y1,double x2,double y2,double a,double b,double c)
{
    if (abs(a)<eps||abs(b)<eps)        return 1E18;
    x1y=(-c-a*x1)/b;
    y1x=(-c-b*y1)/a;

    x2y=(-c-a*x2)/b;
    y2x=(-c-b*y2)/a;

    double d1=abs(y1-x1y)+dis(x1,x1y,x2,x2y)+abs(y2-x2y);
    double d2=abs(y1-x1y)+dis(x1,x1y,y2x,y2)+abs(x2-y2x);
    double d3=abs(x1-y1x)+dis(y1x,y1,x2,x2y)+abs(y2-x2y);
    double d4=abs(x1-y1x)+dis(y1x,y1,y2x,y2)+abs(x2-y2x);

    return min(min(d1,d2),min(d3,d4));
}

int main()
{
    double a,b,c;
    double x1,y1,x2,y2;
    cin>>a>>b>>c;
    cin>>x1>>y1>>x2>>y2;

    // printf("%.9lf %.9lf\n",abs(x1-x2)+abs(y1-y2),solve(x1,y1,x2,y2,a,b,c));
    printf("%.9lf\n",min(abs(x1-x2)+abs(y1-y2),solve(x1,y1,x2,y2,a,b,c)));
    
    return 0;
}