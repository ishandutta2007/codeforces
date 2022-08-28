#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define SIZE 100005
#define MX 12
#define SQR 3000

using namespace std;
typedef pair <int,int> P;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char str[MX];
int tp[SIZE],px[SIZE],py[SIZE],D[SIZE];
P ans[SIZE],pos[SIZE];
int id[SIZE][MX],dr[SIZE][MX];
int to[SIZE];
bool use[SIZE],last[SIZE];
bool vis[SIZE][MX];
P dist[SIZE][MX];
int n,m,q;

int ctoi(char c)
{
	if(c=='<') return 3;
	if(c=='>') return 1;
	if(c=='v') return 0;
	return 2;
}
bool good(int x,int y)
{
	return 0<=x&&x<n&&0<=y&&y<m;
}
P dfs(int v)
{
	if(use[v]) return ans[v];
	use[v]=true;
	ans[v]=P(-2,-2);
	return ans[v]=dfs(to[v]);
}
P DFS(int x,int y)
{
	if(!good(x,y)) return P(x,y);
	if(vis[x][y]) return dist[x][y];
	if(id[x][y]!=-1) return P(x,y);
	vis[x][y]=true;
	dist[x][y]=P(-2,-2);
	return dist[x][y]=DFS(x+dx[dr[x][y]],y+dy[dr[x][y]]);
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		for(int j=0;j<m;j++)
		{
			dr[i][j]=ctoi(str[j]);
		}
	}
	memset(id,-1,sizeof(id));
	for(int i=0;i<q;i+=SQR)
	{
		int t=min(q,i+SQR);
		int sz=0;
		for(int j=i;j<t;j++)
		{
			scanf("%s %d %d",&str,&px[j],&py[j]);px[j]--;py[j]--;
			if(id[px[j]][py[j]]==-1)
			{
				pos[sz]=P(px[j],py[j]);
				id[px[j]][py[j]]=sz++;
			}
			if(str[0]=='A')
			{
				tp[j]=0;
			}
			else
			{
				tp[j]=1;
				scanf("%s",&str);
				D[j]=ctoi(str[0]);
				int nx=px[j]+dx[D[j]],ny=py[j]+dy[D[j]];
				if(good(nx,ny))
				{
					if(id[nx][ny]==-1)
					{
						pos[sz]=P(nx,ny);
						id[nx][ny]=sz++;
					}
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				vis[j][k]=false;
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				dist[j][k]=DFS(j,k);
			}
		}
		for(int j=0;j<sz;j++) use[j]=last[j]=false;
		for(int j=0;j<sz;j++)
		{
			to[j]=-1;
			int x=pos[j].first,y=pos[j].second;
			int nx=x+dx[dr[x][y]],ny=y+dy[dr[x][y]];
			if(good(nx,ny))
			{
				P p=dist[nx][ny];
				if(good(p.first,p.second))
				{
					to[j]=id[p.first][p.second];
				}
				else
				{
					ans[j]=p;
					use[j]=last[j]=true;
				}
			}
			else
			{
				ans[j]=P(nx,ny);
				use[j]=last[j]=true;
			}
		}
		for(int j=0;j<sz;j++) ans[j]=dfs(j);
		//for(int j=0;j<sz;j++) printf("[%d %d] %d *%d %d\n",pos[j].first,pos[j].second,to[j],ans[j].first,ans[j].second);
		for(int j=i;j<t;j++)
		{
			int v=id[px[j]][py[j]];
			if(tp[j]==0)
			{
				printf("%d %d\n",ans[v].first+1,ans[v].second+1);
			}
			else
			{
				last[v]=false;
				dr[px[j]][py[j]]=D[j];
				int nx=px[j]+dx[D[j]],ny=py[j]+dy[D[j]];
				if(good(nx,ny))
				{
					to[v]=id[nx][ny];
				}
				else
				{
					ans[v]=P(nx,ny);
					last[v]=true;
				}
				for(int j=0;j<sz;j++) if(!last[j]) use[j]=false;
				for(int j=0;j<sz;j++) ans[j]=dfs(j);
			}
		}
		for(int j=0;j<sz;j++) id[pos[j].first][pos[j].second]=-1;
	}
	return 0;
}