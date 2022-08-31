#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#define SIZE 2005
#define ALL 4000005

using namespace std;
typedef pair <int,int> P;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char str[SIZE][SIZE];
bool use[SIZE][SIZE];
vector <int> vec[ALL];
int id[SIZE][SIZE];

int ctoi(char c)
{
	if(c=='^') return 2;
	if(c=='v') return 0;
	if(c=='<') return 3;
	return 1;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)  scanf("%s",&str[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(str[i][j]=='#'||use[i][j]) continue;
			int px=i,py=j;
			while(str[px][py]!='#'&&!use[px][py])
			{
				use[px][py]=true;
				int d=ctoi(str[px][py]);
				int nx=px+dx[d],ny=py+dy[d];
				px=nx,py=ny;
			}
			if(px==i&&py==j)
			{
				puts("-1");
				return 0;
			}
		}
	}
	int nd=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(str[i][j]=='#') id[i][j]=-1;
			else id[i][j]=nd++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(str[i][j]=='#') continue;
			int d=ctoi(str[i][j]);
			int nx=i+dx[d],ny=j+dy[d];
			if(id[nx][ny]!=-1) vec[id[nx][ny]].push_back(id[i][j]);
		}
	}
	int m1=0,m2=0;
	int ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(str[i][j]=='#') continue;
			int d=ctoi(str[i][j]);
			int nx=i+dx[d],ny=j+dy[d];
			if(id[nx][ny]==-1)
			{
				queue <P> que;
				que.push(P(id[i][j],1));
				int mx=0;
				while(!que.empty())
				{
					P p=que.front();que.pop();
					int v=p.first;
					mx=p.second;
					for(int k=0;k<vec[v].size();k++)
					{
						int to=vec[v][k];
						que.push(P(to,p.second+1));
					}
				}
				if(m1<=mx)
				{
					m2=m1;
					m1=mx;
				}
				else if(m2<=mx) m2=mx;
				ret=max(ret,2*mx-1);
			}
		}
	}
	ret=max(ret,m1+m2);
	printf("%d\n",ret);
	return 0;
}