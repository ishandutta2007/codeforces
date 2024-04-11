#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE 4050
#define INF 1500000000

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool use[SIZE][SIZE],ln[SIZE][SIZE];
int lx[SIZE],rx[SIZE],ly[SIZE],ry[SIZE];
vector <int> ax,ay;
vector <P> vx,vy;
char str[5];

int dir()
{
	char c=str[0];
	if(c=='U') return 0;
	if(c=='D') return 2;
	if(c=='R') return 1;
	return 3;
}
int xs(int x)
{
	return lower_bound(vx.begin(),vx.end(),P(x,x))-vx.begin();
}
int ys(int y)
{
	return lower_bound(vy.begin(),vy.end(),P(y,y))-vy.begin();
}
int main()
{
	int n;
	scanf("%d",&n);
	int px=0,py=0;
	ax.push_back(0);
	ay.push_back(0);
	ax.push_back(-INF);
	ay.push_back(-INF);
	ax.push_back(INF);
	ay.push_back(INF);
	for(int i=0;i<n;i++)
	{
		int l;
		scanf("%s %d",&str,&l);
		int g=dir();
		int nx=px+dx[g]*l,ny=py+dy[g]*l;
		lx[i]=min(px,nx);rx[i]=max(px,nx);
		ly[i]=min(py,ny);ry[i]=max(py,ny);
		ax.push_back(nx);
		ay.push_back(ny);
		px=nx;py=ny;
	}
	sort(ax.begin(),ax.end());
	ax.erase(unique(ax.begin(),ax.end()),ax.end());
	for(int i=0;i<ax.size();i++)
	{
		vx.push_back(P(ax[i],ax[i]));
		if(i+1<ax.size()&&ax[i]+1<=ax[i+1]-1) vx.push_back(P(ax[i]+1,ax[i+1]-1));
	}
	sort(ay.begin(),ay.end());
	ay.erase(unique(ay.begin(),ay.end()),ay.end());
	for(int i=0;i<ay.size();i++)
	{
		vy.push_back(P(ay[i],ay[i]));
		if(i+1<ay.size()&&ay[i]+1<=ay[i+1]-1) vy.push_back(P(ay[i]+1,ay[i+1]-1));
	}
	for(int i=0;i<n;i++)
	{
		lx[i]=xs(lx[i]);
		rx[i]=xs(rx[i]);
		ly[i]=ys(ly[i]);
		ry[i]=ys(ry[i]);
		for(int j=lx[i];j<=rx[i];j++)
		{
			for(int k=ly[i];k<=ry[i];k++)
			{
				ln[j][k]=true;
			}
		}
	}
	queue <P> que;
	que.push(P(0,0));
	use[0][0]=true;
	while(!que.empty())
	{
		P p=que.front();que.pop();
		for(int i=0;i<4;i++)
		{
			int nx=p.first+dx[i],ny=p.second+dy[i];
			if(0<=nx&&nx<vx.size()&&0<=ny&&ny<vy.size()&&!use[nx][ny]&&!ln[nx][ny])
			{
				use[nx][ny]=true;
				que.push(P(nx,ny));
			}
		}
	}
	ll ret=0;
	for(int i=0;i<vx.size();i++)
	{
		for(int j=0;j<vy.size();j++)
		{
			if(!use[i][j])
			{
				P p=vx[i],q=vy[j];
				ret+=(ll) (p.second-p.first+1)*(ll) (q.second-q.first+1);
			}
		}
	}
	printf("%llld\n",ret);
	return 0;
}