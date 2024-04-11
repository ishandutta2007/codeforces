#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define SIZE 1505

using namespace std;

struct P
{
	int x,y;
	P(int x=0,int y=0):x(x),y(y){}
};
bool use[SIZE][SIZE];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char str[SIZE][SIZE];
int fx[SIZE][SIZE],fy[SIZE][SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int sx,sy;
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str[i]);
		for(int j=0;j<m;j++)
		{
			char c=str[i][j];
			if(c=='S')
			{
				sx=i;
				sy=j;
			}
		}
	}
	queue <P> que;
	que.push(P(sx,sy));
	use[sx][sy]=true;
	fx[sx][sy]=sx;fy[sx][sy]=sy;
	while(!que.empty())
	{
		P p=que.front();que.pop();
		int x=p.x,y=p.y;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			int px=(nx%n+n)%n,py=(ny%m+m)%m;
			if(str[px][py]=='#') continue;
			if(use[px][py])
			{
				if(fx[px][py]!=nx||fy[px][py]!=ny)
				{
					puts("Yes");
					return 0;
				}
			}
			else
			{
				use[px][py]=true;
				fx[px][py]=nx;fy[px][py]=ny;
				que.push(P(nx,ny));
			}
		}
	}
	puts("No");
	return 0;
}