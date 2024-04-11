#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=1e6;
struct edge{
	int to,next,f;
}e[M];
int head[N],tot,S,T;
bool mp[100][100];
int vis[100][100],cnt;
long long dis[100][100];
int q[N],qx[N],qy[N];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int n,m,d[N],cur[N];
int id(int x,int y){
	return (x-1)*m+y;
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	for (int i=S;i<=T;i++) d[i]=-1;
	int h=0,t=1; q[1]=S; d[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (d[e[i].to]==-1&&e[i].f){
				d[e[i].to]=d[x]+1;
				q[++t]=e[i].to;
				if (e[i].to==T) return 1;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int rest=flow,k;
	for (int i=cur[x];i&&rest;cur[x]=i=e[i].next)
		if (d[e[i].to]==d[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			rest-=k; e[i].f-=k; e[i^1].f+=k;
		}
	if (rest) d[x]=-1;
	return flow-rest;
}
#define y1 wzpakking
int f1,f2;
int x1[555],y1[555],v1[555];
int x2[555],y2[555],v2[555];
int main(){
	scanf("%d%d%d%d",&n,&m,&f1,&f2);
	for (int i=1;i<=n;i++){
		char s[100];
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			mp[i][j]=(s[j]=='.');
	}
	if (f1+1==f2)
		scanf("%d%d%d",&x1[f2],&y1[f2],&v1[f2]);
	else if (f2+1==f1)
		scanf("%d%d%d",&x2[f1],&y2[f1],&v2[f1]);
	else
		return puts("-1"),0;
	for (int i=1;i<=f1;i++)
		scanf("%d%d%d",&x1[i],&y1[i],&v1[i]);
	for (int i=1;i<=f2;i++)
		scanf("%d%d%d",&x2[i],&y2[i],&v2[i]);
	int Q=max(f1,f2); S=0; T=((n*m+Q)<<1)+1;
	long long l=0,r=1ll<<60;
	while (l<r){
		long long mid=(l+r)/2;
		for (int i=S;i<=T;i++) head[i]=0;
		tot=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (mp[i][j])
					add(id(i,j),id(i,j)+n*m,1);
		for (int k=1;k<=Q;k++){
			add(S,n*m*2+k,1);
			int x=x1[k],y=y1[k];
			vis[x][y]=++cnt; dis[x][y]=0;
			int h=0,t=1; qx[1]=x; qy[1]=y;
			while (h!=t){
				x=qx[++h],y=qy[h];
				add(n*m*2+k,id(x,y),1);
				if (dis[x][y]+v1[k]>mid) continue;
				for (int di=0;di<4;di++){
					int nx=x+dx[di];
					int ny=y+dy[di];
					if (nx&&ny&&nx<=n&&ny<=m&&
						mp[nx][ny]&&vis[nx][ny]!=cnt){
							vis[nx][ny]=cnt;
							dis[nx][ny]=dis[x][y]+v1[k];
							qx[++t]=nx,qy[t]=ny;
						}
				}
			}
		}
		for (int k=1;k<=Q;k++){
			add(n*m*2+Q+k,T,1);
			int x=x2[k],y=y2[k];
			vis[x][y]=++cnt; dis[x][y]=0;
			int h=0,t=1; qx[1]=x; qy[1]=y;
			while (h!=t){
				x=qx[++h],y=qy[h];
				add(id(x,y)+n*m,2*n*m+Q+k,1);
				if (dis[x][y]+v2[k]>mid) continue;
				for (int di=0;di<4;di++){
					int nx=x+dx[di];
					int ny=y+dy[di];
					if (nx&&ny&&nx<=n&&ny<=m&&
						mp[nx][ny]&&vis[nx][ny]!=cnt){
							vis[nx][ny]=cnt;
							dis[nx][ny]=dis[x][y]+v2[k];
							qx[++t]=nx,qy[t]=ny;
						}
				}
			}
		}
		int k=Q;
		for (;bfs();){
			for (int i=S;i<=T;i++)
				cur[i]=head[i];
			k-=dfs(S,1e9);
		}
		if (k) l=mid+1;
		else r=mid;
	}
	if (l>=(1ll<<60)) puts("-1");
	else printf("%lld\n",l);
}