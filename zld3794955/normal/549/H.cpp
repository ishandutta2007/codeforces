#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8),Inf(1e+16);
const double pi(3.14159265358979);
long long a,b,c,d;
inline int sign(int x)
{
	return x%2 ? -1 : 1;
}
int main()
{	
	cin>>a>>b>>c>>d;
	double ans=Inf;
	for(int S=0;S<16;++S)
	{
		int y[4]={S&1,(S>>1)&1,(S>>2)&1,(S>>3)&1};
		long long r=sign(y[0]+y[1])-sign(y[2]+y[3]);
		long long s=sign(y[0])*a+sign(y[1])*d
			 -sign(y[2])*b-sign(y[3])*c;
		long long t=a*d-b*c;
		if(r==0)
		{
			double now=(double)t/(-s);
			if(now>=0)
				ans=min(now,ans);
		}
		else
		{
			double delta=(double)s*s-(double)4*r*t;
			if(delta>=0)
			{
				delta=sqrt(delta);
				double x1=(-s+delta)/2*r,x2=(-s-delta)/2*r;
				if(x1>=0)
					ans=min(ans,x1);
				if(x2>=0)
					ans=min(ans,x2);
			}
		}
	}
	printf("%.10f\n",ans);
	return 0;
}