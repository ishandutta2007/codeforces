#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 405
#define EPS 1e-10

using namespace std;
typedef long double ld;

int dist[SIZE][SIZE];
vector <int> vec[SIZE];
vector <int> edge[SIZE];
bool use[SIZE],use2[SIZE];
ld mx2[SIZE];
ld dp[SIZE];
int nd[SIZE],nd2[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) dist[i][j]=n*2;
		dist[i][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		dist[a][b]=dist[b][a]=1;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
			}
		}
	}
	ld ret=0.0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) vec[j].clear();
		for(int j=0;j<n;j++) vec[dist[i][j]].push_back(j);
		ld sum=0.0;
		for(int j=0;j<n;j++)
		{
			if(!vec[j].empty())
			{
				ld mx=1.0/(ld) vec[j].size();
				int sz=0;
				for(int k=0;k<vec[j].size();k++)
				{
					int v=vec[j][k];
					for(int p=0;p<edge[v].size();p++)
					{
						int to=edge[v][p];
						if(!use[to])
						{
							use[to]=true;
							nd[sz++]=to;
						}
						dp[to]+=1.0/(ld) (edge[v].size()*vec[j].size());
					}
				}
				for(int k=0;k<n;k++)
				{
					int sz2=0;
					for(int p=0;p<sz;p++)
					{
						int d=dist[k][nd[p]];
						if(!use2[d])
						{
							use2[d]=true;
							nd2[sz2++]=d;
						}
						mx2[d]=max(mx2[d],dp[nd[p]]);
					}
					ld cnt=0.0;
					for(int p=0;p<sz2;p++)
					{
						int d=nd2[p];
						use2[d]=false;
						cnt+=mx2[d];
						mx2[d]=0.0;
					}
					mx=max(mx,cnt);
				}
				sum+=mx*vec[j].size();/*
				if(i==0)
				{
					printf("%d %d : %f\n",j,vec[j].size(),(double) mx);
					for(int k=0;k<sz;k++) printf("* %d %f\n",nd[k],(double) dp[nd[k]]);
				}*/
				for(int k=0;k<sz;k++)
				{
					dp[nd[k]]=0.0;
					use[nd[k]]=false;
				}
			}
		}
		ret=max(ret,sum/(ld) n);
		//printf("%d %f\n",i,(double) (sum/(ld) n));
	}
	printf("%.10f\n",(double) ret);
	return 0;
}