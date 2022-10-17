#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,L,a[N];

bool chk(double t)
{
	double l1=0,l2=0;
	double at=t;
	for(int i=1;i<=n+1;i++)
	{
		double tg=min(at,1.0*(a[i]-a[i-1])/i);
		at-=tg;
		l1+=tg*i;
	}
	at=t;
	for(int i=n;i>=0;i--)
	{
		double tg=min(at,1.0*(a[i+1]-a[i])/(n-i+1));
		at-=tg;
		l2+=tg*(n-i+1);
	}
	return l1+l2>=L;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&L);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=L;
		double l=0,r=1e9;
		for(int test=1;test<=100;test++)
		{
			double mid=(l+r)/2;
			if(chk(mid))
				r=mid;
			else
				l=mid;
		}
		printf("%.10lf\n",r);
	}
}