#include<bits/stdc++.h>
using namespace std;
const int x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
const int N=1616,M=1616,T=10010,D=3,S=(D+D+1)*(D+D+1);
int n,m,a[N][M]={},sum[N][M]={},s[N][M]={},qx[N*M]={},qy[N*M]={};
int ans[N],k=0,root[T]={},tx[T]={},ty[T]={};
int sx,sy,tot,dis[N][M]={},v[N][M]={};
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
int get_sum(int lx,int ly,int rx,int ry)
{
	if(lx<=0 && ly<=0)
		return s[rx][ry];
	if(lx<=0)
		return s[rx][ry]-s[rx][ly-1];
	if(ly<=0)
		return s[rx][ry]-s[lx-1][ry];
	return s[rx][ry]-s[rx][ly-1]-s[lx-1][ry]+s[lx-1][ly-1];
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n+D;++i)
		for(int j=1;j<=m+D;++j)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			sum[i][j]=get_sum(i-D,j-D,i+D,j+D);
}
void dfs(int x,int y)
{
	if(sum[x][y]!=S || v[x][y]==1)
		return;
	v[x][y]=1;
	sx+=x,sy+=y;
	++tot;
	for(int d=0;d<4;++d)
		dfs(x+x_[d],y+y_[d]);
}
void bfs(int x,int y)
{
	int head=0,tail=0;
	++tail, qx[tail]=x, qy[tail]=y;
	dis[x][y]=1;
	while(head!=tail)
	{
		++head;
		int sx=qx[head],sy=qy[head];
		for(int d=0;d<4;++d)
		{
			int nx=sx+x_[d],ny=sy+y_[d];
			if(a[nx][ny] && !dis[nx][ny])
			{
				dis[nx][ny]=dis[sx][sy]+1;
				++tail, qx[tail]=nx, qy[tail]=ny;
			}
		}
	}
	int t=0;
	for(int i=1;i<=tail;++i)
	{
		int sx=qx[i],sy=qy[i];
		bool flag=true;
		for(int nx=max(sx-D,0);nx<=sx+D;++nx)
			for(int ny=max(sy-D,0);ny<=sy+D;++ny)
				if(dis[sx][sy]<dis[nx][ny] || sum[nx][ny]==S)
					flag=false;
		if(flag)
			++t,tx[t]=sx,ty[t]=sy;
	}
	for(int i=1;i<=t;++i)
		root[i]=i;
	ans[k]=t;
	//for(int i=1;i<=t;++i)
	//	cerr<<tx[i]<<' '<<ty[i]<<endl;
	//cerr<<endl;
	for(int i=1;i<=t;++i)
		for(int j=i+1;j<=t;++j)
			if(max(abs(tx[i]-tx[j]),abs(ty[i]-ty[j]))<=D)
			{
				int u=get_root(i),v=get_root(j);
				if(u!=v)
					root[u]=v,--ans[k];
			}
}
void calc(int x,int y)
{
	++k;
	sx=sy=tot=0;
	dfs(x,y);
	int hx=sx/tot,hy=sy/tot;
	dis[hx][hy]=0;
	bfs(hx,hy);
}
void work()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(sum[i][j]==S && v[i][j]!=1)
				calc(i,j);
	sort(ans+1,ans+k+1);
	printf("%d\n",k);
	for(int i=1;i<=k;++i)
		printf("%d ",ans[i]);
	printf("\n");
}
int main()
{
	//freopen("F.in","r",stdin);
	//freopen("F.out","w",stdout); 
	init();
	work();
}