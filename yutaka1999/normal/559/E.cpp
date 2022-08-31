#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 305
#define INF 1000000000

using namespace std;
typedef pair <int,int> P;

int A[SIZE],L[SIZE];
P pp[SIZE];
int dp1[2][SIZE][SIZE];
int dp2[2][SIZE][SIZE];
vector <int> vx;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&A[i],&L[i]);
		vx.push_back(A[i]);
		vx.push_back(A[i]+L[i]);
		vx.push_back(A[i]-L[i]);
		pp[i]=P(A[i],L[i]);
	}
	vx.push_back(-INF);
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(pp,pp+n);
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	int pos=0;
	for(int i=0;i<n;i++)
	{
		int a=pp[i].first,l=pp[i].second;
		int s=lower_bound(vx.begin(),vx.end(),a-l)-vx.begin();
		int t=lower_bound(vx.begin(),vx.end(),a)-vx.begin();
		int u=lower_bound(vx.begin(),vx.end(),a+l)-vx.begin();
		pos^=1;
		memset(dp1[pos],-1,sizeof(dp1[pos]));
		memset(dp2[pos],-1,sizeof(dp2[pos]));
		for(int j=0;j<vx.size();j++)
		{
			for(int k=j;k<vx.size();k++)
			{
				if(dp1[pos^1][j][k]==-1) continue;
				dp2[pos][j][k]=max(dp2[pos][j][k],dp2[pos^1][j][k]);
				dp1[pos][j][k]=max(dp1[pos][j][k],dp1[pos^1][j][k]);
				int to=dp1[pos^1][j][k];
				if(k<=t&&t<=dp1[pos^1][j][k])
				{
					if(j<s)
					{
						dp2[pos][j][s]=max(dp2[pos][j][s],dp2[pos^1][j][k]+vx[k]-vx[s]);
						dp1[pos][j][s]=max(dp1[pos][j][s],to);
					}
					else
					{
						dp2[pos][j][j]=max(dp2[pos][j][j],dp2[pos^1][j][k]+vx[k]-vx[j]);
						dp1[pos][j][j]=max(dp1[pos][j][j],to);
					}
					if(to<u)
					{
						dp2[pos][j][k]=max(dp2[pos][j][k],dp2[pos^1][j][k]+vx[u]-vx[to]);
						dp1[pos][j][k]=max(dp1[pos][j][k],u);
					}
				}
				else
				{
					if(k<s)
					{
						if(s<=to)
						{
							dp2[pos][j][k]=max(dp2[pos][j][k],dp2[pos^1][j][k]+vx[t]-vx[to]);
							dp1[pos][j][k]=max(dp1[pos][j][k],t);
						}
						else
						{
							dp2[pos][to][s]=max(dp2[pos][to][s],dp2[pos^1][j][k]+vx[t]-vx[s]);
							dp1[pos][to][s]=max(dp1[pos][j][k],t);
						}
					}
					dp2[pos][to][t]=max(dp2[pos][to][t],dp2[pos^1][j][k]+vx[u]-vx[t]);
					dp1[pos][to][t]=max(dp1[pos][to][t],u);
				}
			}
		}
		dp2[pos][0][s]=max(dp2[pos][0][s],vx[t]-vx[s]);
		dp1[pos][0][s]=max(dp1[pos][0][s],t);
		dp2[pos][0][t]=max(dp2[pos][0][t],vx[u]-vx[t]);
		dp1[pos][0][t]=max(dp1[pos][0][t],u);
	}
	int mx=0;
	for(int j=0;j<vx.size();j++)
	{
		for(int k=j;k<vx.size();k++)
		{
			mx=max(mx,dp2[pos][j][k]);
		}
	}
	printf("%d\n",mx);
	return 0;
}