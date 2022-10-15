#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int T;
int n;
double mine[maxn],dia[maxn];
int mtop,dtop;
double ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=mtop=dtop=0;
		for(int i=1;i<=2*n;i++)
		{
			double x,y;scanf("%lf%lf",&x,&y);
			if(x<0)x=-x;if(y<0)y=-y;
			if(x==0.0)mine[++mtop]=y;
			else dia[++dtop]=x;
		}
		sort(mine+1,mine+n+1);
		sort(dia+1,dia+n+1);
		for(int i=1;i<=n;i++)ans+=sqrt(mine[i]*mine[i]+dia[i]*dia[i]);
		printf("%.20lf\n",ans);
	}
	return 0;
}