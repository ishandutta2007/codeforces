#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#define SIZE 105
#define MX 1005
#define EPS 1e-10
#define DINF 1e10

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

P pos[SIZE];
double dp[MX][SIZE];

void solve()
{
	int n;
	scanf("%d",&n);
	double C,T;
	scanf("%lf %lf",&C,&T);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		pos[i]=P(a,b);
	}
	sort(pos,pos+n,greater <P>());
	for(int i=0;i<MX;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=-1.0;
		}
	}
	dp[0][0]=0.0;
	for(int i=0;i<n;i++)
	{
		P p=pos[i];
		for(int j=MX-1;j>=0;j--)
		{
			double t=p.first;
			for(int k=0;k<=i;k++)
			{
				t/=0.9;
				if(dp[j][k]<-EPS) continue;
				if(dp[j+p.second][k+1]<-EPS) dp[j+p.second][k+1]=dp[j][k]+t;
				else dp[j+p.second][k+1]=min(dp[j+p.second][k+1],dp[j][k]+t);
			}
		}
		//printf("%f %f\n",dp[6][1],dp[9][2]);
	}
	for(int i=MX-1;i>=0;i--)
	{
		bool up=false;
		for(int j=0;j<=n;j++)
		{
			if(dp[i][j]>-EPS)
			{
				double zan=T-10.0*(double) j;
				if(zan>-EPS)
				{
					double a=1.0/C-zan;
					double b=(dp[i][j]-zan)/C;
					if(b<EPS||zan*zan+a*zan+b<EPS) up=true;
					else if(a<EPS&&b-a*a/4.0<EPS) up=true;/*
					if(up)
					{
						printf("%d %d %lf\n",i,j,dp[i][j]);
						printf("%lf %lf\n",a,b);
						break;
					}*/
				}
			}
		}
		if(up)
		{
			printf("%d\n",i);
			break;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}