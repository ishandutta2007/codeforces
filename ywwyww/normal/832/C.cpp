#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int x[100010];
double v[100010];
int t[100010];
int n;
double s;
int check(double p)
{
	if(p<0.1)
		int xxx=1;
	if(p<0.8&&p>0.7)
		int xxx=1;
	double ans1=0,ans2=0;
	int i;
	int x1=0,x2=0;
	int l1=1000000,l2=1000000;
	double ss;
	for(i=1;i<=n;i++)
	{
		ss=(p*(s*s-v[i]*v[i])+v[i]*x[i])/s;
		if(t[i]==1)
		{
			if(x[i]/v[i]>p)
			{
				if(ss>=x[i])
				{
					ans1=max(ans1,ss);
					l1=min(l1,x[i]);
				}
			}
			else
				x1=1;
		}
		else
		{
			if(x[i]/v[i]>p)
			{
				if(ss>=x[i])
				{
					ans2=max(ans2,ss);
					l2=min(l2,x[i]);
				}
			}
			else
				x2=1;
		}
	}
	ans1=min(ans1,double(1000000));
	ans2=min(ans2,double(1000000));
	int s1=floor(ans1);
	int s2=floor(ans2);
	s2=1000000-s2;
	l2=1000000-l2;
	if(x1&&x2)
		return 1;
	if(x1&&s2<=l2)
		return 1;
	if(x2&&l1<=s1)
		return 1;
	if(s2<=l1&&l2>=l1)
		return 1;
	if(s2>=l1&&s2<=s1&&l2>=s2)
		return 1;
	return 0;
}
int main()
{
	scanf("%d%lf",&n,&s);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%lf%d",&x[i],&v[i],&t[i]);
		if(t[i]==2)
			x[i]=1000000-x[i];
	}
	double l=0,r=1000000;
	double mid;
	while(r-l>1e-7)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%.10lf\n",l);
	return 0;
}