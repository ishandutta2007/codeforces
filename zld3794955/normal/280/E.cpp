#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8),Inf(1e10);
const double pi(3.14159265358979);
const int N=6060;
struct point
{
	double x,y;
}p[N+N]={};
int n,q,k=0,a,b,x[N]={};
double ans[N]={};
void init()
{
	cin>>n>>q>>a>>b;
	for(int i=1;i<=n;++i)
		cin>>x[i];
}
void work()
{
	p[++k]={1.0,2.0*(-x[1])};
	p[++k]={Inf,2.0*(Inf-x[1])};
	ans[1]=x[1];
	double zero=x[1];
	for(int i=2,d=1;i<=n;++i)
	{
		for(int j=k;j>d;--j)
			p[j+2]=p[j];
		k+=2;
		p[d+1]={zero,0};
		p[d+2]={zero,0};
		for(int j=1;j<=d+1;++j)
			p[j].x+=a;
		for(int j=d+2;j<=k;++j)
			p[j].x+=b;
		for(int j=1;j<=k;++j)
			p[j].y+=2*(p[j].x-x[i]);
		if(p[1].y>0)
			zero=p[1].x,d=0;
		else
		{
			for(d=1;p[d].y*p[d+1].y>0;++d) ;
			zero=(-p[d].y)/(p[d+1].y-p[d].y)*(p[d+1].x-p[d].x)+p[d].x;
		}
		ans[i]=zero;
		/*
		for(int j=1;j<=k;++j)
			printf("%.6f %.6f\n",p[j].x,p[j].y);
		printf("ans=%.6f\n",ans[i]);
		cout<<"----------------------------------"<<endl;
		*/
	}
	ans[n]=min<double>(ans[n],q);
	for(int i=n-1;i>=1;--i)
	{
		ans[i]=max(ans[i+1]-b,ans[i]);
		ans[i]=min(ans[i+1]-a,ans[i]);
	}
	double sum=0;
	for(int i=1;i<=n;++i)
		sum+=(x[i]-ans[i])*(x[i]-ans[i]);
	for(int i=1;i<=n;++i)
		printf("%.6f ",ans[i]);
	printf("\n%.6f\n",sum);
}
int main()
{	
	init();
	work();
	return 0;
}