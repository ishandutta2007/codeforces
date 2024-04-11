#include <algorithm>
#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=1005;
const int MAXT=1565;
const int MUL=1000000;
const double EPS=1e-11;
struct prob
{
	int s1,s2,t1,t2,pf;
	friend bool operator <(const prob &x,const prob &y)
	{
		return (long long)x.pf*x.t2*(MUL-y.pf)<(long long)y.pf*y.t2*(MUL-x.pf);
	}
};
struct data
{
	long long sc;
	double t;
	data() {}
	data(long long sc,double t):sc(sc),t(t) {}
	friend bool operator <(const data &x,const data &y)
	{
		return x.sc<y.sc||(x.sc==y.sc&&x.t>y.t+EPS);
	}
};
int n,t;
prob a[MAXN];
data f[MAXT];
void init()
{
	scanf("%d%d",&n,&t);
	for (int i=0;i<n;++i)
	{
		double pf;
		scanf("%d%d%d%d%lf",&a[i].s1,&a[i].s2,&a[i].t1,&a[i].t2,&pf);
		a[i].pf=(int)(pf*MUL+0.5);
	}
	std::sort(a,a+n);
}
void solve()
{
	data tmp;
	for (int i=0;i<n;++i)
		for (int j=t-1;j>=0;--j)
		{
			tmp=f[j];
			if (j+a[i].t1<=t)
			{
				tmp=data(tmp.sc+(long long)MUL*a[i].s1,tmp.t+a[i].t1);
				if (f[j+a[i].t1]<tmp)
					f[j+a[i].t1]=tmp;
			}
			if (j+a[i].t1+a[i].t2<=t)
			{
				tmp=data(tmp.sc+(long long)(MUL-a[i].pf)*a[i].s2,(double)a[i].pf/MUL*tmp.t+(double)(MUL-a[i].pf)/MUL*(j+a[i].t1+a[i].t2));
				if (f[j+a[i].t1+a[i].t2]<tmp)
					f[j+a[i].t1+a[i].t2]=tmp;
			}
		}
	int u=0;
	for (int i=1;i<=t;++i)
		if (f[u]<f[i])
			u=i;
	printf("%.10f %.10f\n",(double)f[u].sc/MUL,f[u].t);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("8804.in","r",stdin);
	freopen("8804.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}