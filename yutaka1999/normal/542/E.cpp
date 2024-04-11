#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 1005

using namespace std;

vector <int> vec[SIZE];
bool use[SIZE];
int dist[SIZE];
int nd[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			int sz=0;
			queue <int> que;
			que.push(i);
			while(!que.empty())
			{
				int v=que.front();que.pop();
				nd[sz++]=v;
				for(int j=0;j<vec[v].size();j++)
				{
					int to=vec[v][j];
					if(!use[to])
					{
						que.push(to);
						use[to]=true;
					}
				}
			}
			int mx=0;
			for(int j=0;j<sz;j++)
			{
				memset(dist,-1,sizeof(dist));
				que.push(nd[j]);
				dist[nd[j]]=0;
				while(!que.empty())
				{
					int v=que.front();que.pop();
					mx=max(mx,dist[v]);
					for(int k=0;k<vec[v].size();k++)
					{
						int to=vec[v][k];
						if(dist[to]==-1)
						{
							dist[to]=dist[v]+1;
							que.push(to);
						}
						else if(dist[to]%2==dist[v]%2)
						{
							puts("-1");
							return 0;
						}
					}
				}
			}
			sum+=mx;
		}
	}
	printf("%d\n",sum);
	return 0;
}