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
#define SIZE 305
#define EPS 1e-10
#define PI 3.1415926535897932384626
#define MX 7

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <double,P> PD;

P pos[SIZE];
ll dp[SIZE][MX];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		pos[i]=P(x,y);
	}
	sort(pos,pos+n);
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		vector <PD> vx;
		for(int j=i;j<n;j++)
		{
			for(int k=i;k<n;k++)
			{
				if(j==k) continue;
				P p=pos[k];
				p.first-=pos[j].first;
				p.second-=pos[j].second;
				double d=atan2(p.first,-p.second);
				if(d<EPS) d+=2.0*PI;
				vx.push_back(PD(d,P(j,k)));
			}
		}
		sort(vx.begin(),vx.end());
		memset(dp,0,sizeof(dp));
		dp[i][0]=1;
		for(int j=0;j<vx.size();j++)
		{
			P p=vx[j].second;
			for(int t=0;t+1<MX;t++)
			{
				dp[p.second][t+1]+=dp[p.first][t];
			}
		}
		ret+=dp[i][5];
	}
	printf("%lld\n",ret);
	return 0;
}