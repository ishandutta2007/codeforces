#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define SIZE 505

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

vector <int> vec[SIZE];
vector <int> nw[SIZE];
bool use[SIZE];
int dist[SIZE][SIZE];
int id[SIZE],deg[SIZE];
char str[10];

int ask(int v)
{
	printf("%d\n",v+1);
	fflush(stdout);
	scanf("%s",&str);
	if(str[0]=='F') return -1;
	int u;
	scanf("%d",&u);u--;
	return u;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) dist[i][j]=n;
		dist[i][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int c;
		scanf("%d",&c);
		int v;
		scanf("%d",&v);v--;
		for(int j=1;j<c;j++)
		{
			int u;
			scanf("%d",&u);u--;
			vec[v].push_back(u);
			vec[u].push_back(v);
			dist[u][v]=dist[v][u]=1;
			v=u;
		}
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
	for(int T=0;T<n;T++)
	{
		memset(use,true,sizeof(use));
		while(1)
		{
			vector <int> zan;
			for(int i=0;i<n;i++) if(use[i]) zan.push_back(i);
			P p=P(n*n,n*n);
			for(int i=0;i<n;i++)
			{
				if(use[i])
				{
					int mx=0;
					for(int j=0;j<vec[i].size();j++)
					{
						int to=vec[i][j];
						if(use[to])
						{
							int cnt=0;
							for(int k=0;k<zan.size();k++)
							{
								if(dist[zan[k]][i]>dist[zan[k]][to]) cnt++;
							}
							mx=max(mx,cnt);
						}
					}
					p=min(p,P(mx,i));
				}
			}
			int g=ask(p.second);
			if(g==-1) break;
			for(int i=0;i<n;i++) if(dist[g][i]>=dist[p.second][i]) use[i]=false;
		}
	}
	return 0;
}