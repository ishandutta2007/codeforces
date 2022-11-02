#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
int main()
{
	int n;
	cin>>n;
	if(n<=4)
	{
		puts("No solution");
		return 0;
	}
	double l=200,x=0,y=0,d=2*pi/n,sd=d;
	for(int i=1;i<=n-1;++i)
	{
		printf("%.6f %.6f\n",x,y);
		x+=l*cos(sd);
		y+=l*sin(sd);
		sd+=d;
		l+=0.002;
	}
	printf("%.6f 0.000000\n",x+y/tan(d));
	return 0;
}