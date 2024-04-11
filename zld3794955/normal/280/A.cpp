#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
double w,h,a;
int main()
{
	cin>>w>>h>>a;
	if(w<h)
		swap(w,h);
	if(a>90) a=180-a;
	a=a/180*pi;
	double d=2*atan2(h,w);
	if(a>d)
		printf("%.12f\n",h*h/sin(a));
	else
		if(fabs(a)<eps)
			printf("%.12f\n",w*h);
		else
		{
			double x1=(w*cos(a)+h*sin(a))*0.5;
			double y1=(w*sin(a)-h*cos(a))*0.5;
			double x2=(w*cos(a)-h*sin(a))*0.5;
			double y2=(w*sin(a)+h*cos(a))*0.5;
			double x3=(-w*cos(a)-h*sin(a))*0.5;
			double y3=(-w*sin(a)+h*cos(a))*0.5;
			double dx1=(h/2-y2)/(y1-y2)*(x1-x2)+x2;
			double dx2=(h/2-y2)/(y3-y2)*(x3-x2)+x2;
			double dy1=(y1-y2)/(x1-x2)*(w/2-x2)+y2;
			double dy2=(y3-y2)/(x3-x2)*(-w/2-x2)+y2;
			printf("%.12f\n",w*h-(w/2-dx1)*(h/2-dy1)-(dx2+w/2)*(h/2-dy2));
		}
	return 0;
}