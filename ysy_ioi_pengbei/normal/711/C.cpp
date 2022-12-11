#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
ll cost[101][101][101],mc[101][101];
int k,n,m,c[23333];
ll p[233][233];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) scanf("%d",&p[i][j]);
	}
	memset(cost,127/3,sizeof(cost));
	memset(mc,127/3,sizeof(mc));
	ll inf=cost[0][0][0];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i]&&j!=c[i]) continue;
			ll coc=inf;
			if(c[i]) coc=0;
			else coc=p[i][j];
			for(int l=1;l<=k;l++)
			{
				ll diff=(i==1&&l==1)?0:inf;
				for(int s=1;s<=m;s++)
				{
					if(s==j) continue;
					diff=min(diff,cost[i-1][s][l-1]);
				}
				cost[i][j][l]=min(cost[i][j][l],diff+coc);
				cost[i][j][l]=min(cost[i][j][l],cost[i-1][j][l]+coc);
				//cout<<i<<","<<j<<","<<l<<" "<<cost[i][j][l]<<" "<<coc<<","<<diff<<"\n";
			}
		}
	}
	ll ans=inf;
	for(int i=1;i<=m;i++) ans=min(ans,cost[n][i][k]);
	if(ans==inf) ans=-1;
	cout<<ans<<"\n";
}