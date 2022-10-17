#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define N 200100
#define db double
using namespace std;

ll n,m,xy,dy;
db ans;
struct Node
{
	ll num,t;
	bool operator < (const Node &u) const
	{
		return abs(t-m)<abs(u.t-m);
	}
}wa[N];

int main()
{
	ll i,j,p,q;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&wa[i].num);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		wa[i].t=p;
		if(p>m) dy+=(p-m)*wa[i].num;
		else xy+=(m-p)*wa[i].num;
	}
	sort(wa+1,wa+n+1);
	if(dy>xy)
	{
		for(i=1;i<=n;i++)
		{
			if(wa[i].t<=m) ans+=wa[i].num;
			else
			{
				if(wa[i].num*(wa[i].t-m)<=xy) xy-=wa[i].num*(wa[i].t-m),ans+=wa[i].num;
				else ans+=(db)xy/(wa[i].t-m),xy=0;
			}
		}
		printf("%.10lf",ans);
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(wa[i].t>=m) ans+=wa[i].num;
			else
			{
				if(wa[i].num*(m-wa[i].t)<=dy) dy-=wa[i].num*(m-wa[i].t),ans+=wa[i].num;
				else ans+=(db)dy/(m-wa[i].t),dy=0;
			}
		}
		printf("%.10lf",ans);
	}
}