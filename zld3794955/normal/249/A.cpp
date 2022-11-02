#include<bits/stdc++.h>
using namespace std;
const double eps(1e-10);
const double pi(3.14159265358979);
double y1,y2,yw,xb,yb,R;
int main()
{	
	cin>>y1>>y2>>yw>>xb>>yb>>R;
	yw-=R;
	y1=yw+yw-y1, y2=yw+yw-y2;
	swap(y1,y2);
	double l=y1,r=y2;
	//cout<<"y1="<<y1<<" y2="<<y2<<endl;
	while(true)
	{
		double mid=(l+r)*0.5;
		double k=xb/(mid-yb),d=R*sqrt(1+k*k)/k;
		//cout<<"l="<<l<<" r="<<r<<" mid="<<mid<<endl;
		//cout<<"k="<<k<<" d="<<d<<endl;
		if(mid-d<y1+eps && mid+R>y2-eps)
		{
			puts("-1");
			return 0;
		}
		if(mid-d>y1-eps && mid+R<y2+eps)
		{
			l=r=mid;
			break;
		}
		if(mid-d<y1)
			l=mid;
		else
			r=mid;
	}
	//double k=xb/(l-yb),d=R*sqrt(1+k*k)/k;
	//cout<<"l="<<l-d<<" r="<<l+d<<endl;
	printf("%.12f\n",(l-yw)/(l-yb)*xb);
	return 0;
}