#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 2005

using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char mp[SIZE][SIZE];
bool use[SIZE*SIZE];
vector <int> to[SIZE*SIZE];
int deg[SIZE*SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&mp[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='.')
			{
				for(int k=0;k<4;k++)
				{
					int x=i+dx[k],y=j+dy[k];
					if(0<=x&&x<n&&0<=y&&y<m&&mp[x][y]=='.')
					{
						to[i*m+j].push_back(x*m+y);
					}
				}
			}
		}
	}
	for(int i=0;i<n*m;i++) deg[i]=to[i].size();
	for(int i=0;i<n*m;i++)
	{
		if(mp[i/m][i%m]=='.')
		{
			vector <int> nd;
			queue <int> que;
			que.push(i);
			use[i]=true;
			int cnt=0;
			while(!que.empty())
			{
				int v=que.front();que.pop();
				if(((v%m)+(v/m))%2==0) cnt++;
				else cnt--;
				nd.push_back(v);
				for(int j=0;j<to[v].size();j++)
				{
					int u=to[v][j];
					if(!use[u])
					{
						use[u]=true;
						que.push(u);
					}
				}
			}
			if(cnt!=0)
			{
				puts("Not unique");
				return 0;
			}
			for(int j=0;j<nd.size();j++)
			{
				int v=nd[j];
				if(deg[v]==1)
				{
					que.push(v);
				}
			}
			while(!que.empty())
			{
				int v=que.front();que.pop();
				if(mp[v/m][v%m]!='.') continue;
				cnt+=2;
				for(int j=0;j<to[v].size();j++)
				{
					int u=to[v][j];
					if(mp[u/m][u%m]=='.')
					{
						if(u<v)
						{
							if(u/m==v/m)
							{
								mp[u/m][u%m]='<';
								mp[v/m][v%m]='>';
							}
							else
							{
								mp[u/m][u%m]='^';
								mp[v/m][v%m]='v';
							}
						}
						else
						{
							if(u/m==v/m)
							{
								mp[u/m][u%m]='>';
								mp[v/m][v%m]='<';
							}
							else
							{
								mp[u/m][u%m]='v';
								mp[v/m][v%m]='^';
							}
						}
						for(int k=0;k<to[u].size();k++)
						{
							int p=to[u][k];
							if(mp[p/m][p%m]=='.')
							{
								deg[p]--;
								if(deg[p]==1) que.push(p);
							}
						}
					}
				}
			}
			if(cnt!=nd.size())
			{
				puts("Not unique");
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++) printf("%s\n",&mp[i]);
	return 0;
}