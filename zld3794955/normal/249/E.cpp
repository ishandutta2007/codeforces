#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const long long mod=10000000000ll,re3=(mod+mod+1)/3;
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
inline long long multi(long long a,long long b)
{
	return (a*b-(long long)((a*1.0*b)/mod)*mod);
}
inline long long sumsqr(long long x)
{
	if(x%2)
		return multi(multi(x,(x+1)/2),multi(x+x+1,re3));
	else
		return multi(multi(x/2,x+1),multi(x+x+1,re3));
}
inline long long sum(int x,int y)
{
	if(!x || !y)
		return 0ll;
	long long s=0;
	if(x<=y)
	{
		if(x%2==0)
			s+=multi(multi(x/2,x),multi(x,x)+1);
		else
			s+=multi(multi(x,x),multi((x+1)/2,x+1)+mod-x);
		s+=multi(sumsqr(y-1)+mod-sumsqr(x-1),x);
		if(x%2==0)
			s+=multi(multi(y-x,x/2),1+x);
		else
			s+=multi(multi(y-x,(1+x)/2),x);
	}
	else
	{
		if(y%2==0)
			s+=multi(multi(y/2,y),multi(y,y)+1);
		else
			s+=multi(multi(y,y),multi((y+1)/2,y+1)+mod-y);
		s+=multi(sumsqr(x)+mod-sumsqr(y),y);
		if(y%2==0)
			s+=multi(multi(x-y,y/2),1+mod-y);
		else
			s+=multi(multi(x-y,mod+(1-y)/2),y); 
	}
	return s%mod;
}
double sumd(double x,double y)
{
	if(!x || !y)
		return 0.0;
	double s=0;
	if(x<=y)
	{
		s+=(x*x)*(x*x+1)*0.5;
		s+=((y-1)*y*(2*y-1)/6 - (x-1)*x*(2*x-1)/6)*x;
		s+=(y-x)*0.5*(1+x)*x;
	}
	else
	{
		s+=(y*y)*(y*y+1)*0.5;
		s+=(x*(x+1)*(2*x+1)/6 - y*(y+1)*(2*y+1)/6)*y;
		s+=(x-y)*0.5*y*(1-y);
	}
	return s;
}
int main()
{
	//x1=999999839 y1=999999719 x2=999999839 y2=999999734
	//999999839 999999719 999999839 999999734
	int T=getint(),x1,y1,x2,y2;
	while(T--)
	{
		x1=getint(),y1=getint(),x2=getint(),y2=getint();
		long long ans1=sum(x2,y2)+sum(x1-1,y1-1);
		long long ans2=sum(x2,y1-1)+sum(x1-1,y2);
		long long ans=(ans1+mod+mod-ans2)%mod;
		//if(ans==2000419128ll)
		//	cout<<"x1="<<x1<<" y1="<<y1<<" x2="<<x2<<" y2="<<y2<<endl;
		double tmp=sumd(x2,y2)+sumd(x1-1,y1-1)-sumd(x2,y1-1)-sumd(x1-1,y2);
		if(x1>=50000 || y1>=50000 || tmp>=mod-eps)
			printf("...%010I64d\n",ans);
		else
			printf("%I64d\n",ans);
	}
	return 0;
}