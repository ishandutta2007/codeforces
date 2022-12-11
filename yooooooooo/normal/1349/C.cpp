#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
	int x,y;
	node(int nx=0,int ny=0){x=nx;y=ny;}
}h,q[1000005];
int mov[4][2]={1,0,-1,0,0,1,0,-1},dist[1005][1005],vis[1005][1005],n,m,t,x,y,col[1005][1005];
ll p;
int l,r,nx,ny;
vector<node>seq;
char s[1005];
bool ok(int x,int y){return x&&y&&x<=n&&y<=m;}
void dfs(int x,int y)
{
	int nx,ny;
	vis[x][y]=1;
	seq.push_back(node(x,y));
	for(int i=0;i<4;i++){
		nx=x+mov[i][0];
		ny=y+mov[i][1];
		if(!ok(nx,ny))continue;
		if(vis[nx][ny]||col[nx][ny]!=col[x][y])continue;
		dfs(nx,ny);
	}
	
}
int main()
{
	memset(dist,-1,sizeof(dist));
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)col[i][j]=s[j]-'0';
	}
	l=r=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j])continue;
			seq.clear();
			dfs(i,j);
			if(seq.size()<=1)continue;
			for(int k=0;k<seq.size();k++)
			{
				h=seq[k];
				dist[h.x][h.y]=0;
				q[r++]=h;	
			}	
		}
	}
	while(l<r)
	{
		h=q[l++];
		for(int i=0;i<4;i++){
		nx=h.x+mov[i][0];
		ny=h.y+mov[i][1];
		if(!ok(nx,ny))continue;
		if(dist[nx][ny]!=-1)continue;
		dist[nx][ny]=dist[h.x][h.y]+1;
		q[r++]=node(nx,ny);
		}
	}
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d%lld",&x,&y,&p);
		p=p-dist[x][y];
		if(p<=0||dist[x][y]==-1)printf("%d\n",col[x][y]);
		else 
		{
			if(p&(1ll))printf("%d\n",!col[x][y]);
			else printf("%d\n",col[x][y]);
		}
	}
	return 0;
}