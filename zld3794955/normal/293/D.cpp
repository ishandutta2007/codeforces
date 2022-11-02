#include<bits/stdc++.h>
using namespace std;
const int N=100010,V=1000000,MV=1001000,Inf=1<<30;
const double eps(1e-8);
int n,x[N]={},y[N]={},ul[MV+MV]={},ur[MV+MV]={},*l=ul+MV,*r=ur+MV;
double ans=0;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	x[n+1]=x[1],y[n+1]=y[1];
}
void work()
{
	double s0=0,s1=0,s2=0;
	for(int i=-V;i<=V;++i)
		l[i]=Inf,r[i]=-Inf;
	int lx=V,rx=-V;
	for(int i=1;i<=n;++i)
	{
		lx=min(lx,x[i]),rx=max(rx,x[i]);
		if(x[i]==x[i+1])
			l[x[i]]=min(y[i],y[i+1]),r[x[i]]=max(y[i],y[i+1]);
		else
		{
			bool flag=false;
			if(x[i]>x[i+1])
				flag=true;
			if(flag) swap(x[i],x[i+1]),swap(y[i],y[i+1]);
			double t1=1.0/(x[i+1]-x[i]), t2=y[i+1]-y[i];
			double t3=(long long)x[i+1]*y[i]-(long long)x[i]*y[i+1];
			for(int j=x[i];j<=x[i+1];++j)
			{
				double c=(t3+j*t2)*t1;
				l[j]=min(l[j],(int)ceil(c));
				r[j]=max(r[j],(int)floor(c));
			}
			if(flag) swap(x[i],x[i+1]),swap(y[i],y[i+1]);
		}
	}
	for(int i=lx;i<=rx;++i)
	{
		long long d=r[i]-l[i]+1;
		s0+=d, s1+=d*i, s2+=d*i*i;
	}
	ans+=(s0*s2-s1*s1)/s0/(s0-1);
}
void swapxy()
{
	for(int i=1;i<=n+1;++i)
		swap(x[i],y[i]);
}
int main()
{
	init();
	work();
	swapxy();
	work();
	printf("%.10f\n",ans);
	return 0;
}