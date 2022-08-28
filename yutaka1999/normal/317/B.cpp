#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#include <ctime>
#define MAX 500
#define MD 250
#define SIZE 300000

using namespace std;

struct P
{
	int f,s;
	P(int f=0,int s=0):f(f),s(s){}
};
int nd[MAX][MAX];
bool up[MAX][MAX];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int main()
{
	int n,t;
	scanf("%d %d",&n,&t);
	nd[MD][MD]=n;
	queue <P> que;
	memset(up,false,sizeof(up));
	if(n>=4)
	{
		que.push(P(MD,MD));
		up[MD][MD]=true;
	}
	while(!que.empty())
	{
		P p=que.front();que.pop();
		int x=p.f,y=p.s;
		up[x][y]=false;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			nd[nx][ny]+=nd[x][y]/4;
			if(nd[nx][ny]>=4&&!up[nx][ny])
			{
				up[nx][ny]=true;
				que.push(P(nx,ny));
			}
		}
		nd[x][y]%=4;
	}
	for(int i=0;i<t;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);x+=MD;y+=MD;
		if(0<=x&&x<MAX&&0<=y&&y<MAX) printf("%d\n",nd[x][y]);
		else puts("0");
	}
	return 0;
}