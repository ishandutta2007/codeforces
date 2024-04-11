#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N=1010;
int n,m,t,a[N][N],scc[N][N],siz[N*N],sum;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char s[N][N];
inline void expand(int x,int y,int tot){
	scc[x][y]=tot;siz[tot]++;
	for(int i=0;i<=3;++i){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&(a[xx][yy]==a[x][y])&&(!scc[xx][yy])) expand(xx,yy,tot);
	}
}
queue<int>q;
int dis[N*N],first[N*N],cnt,vis[N*N],col[N*N];
struct node{
	int v,nxt;
}e[N*N*4];
inline void add(int u,int v){e[++cnt].v=v;e[cnt].nxt=first[u];first[u]=cnt;}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&t);
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j) a[i][j]=s[i][j]-'0';
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!scc[i][j]){
				expand(i,j,++sum);col[sum]=a[i][j];
				if(siz[sum]>1) q.push(sum),vis[sum]=1,dis[sum]=0;
			}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=0;k<=3;++k){
				int xx=i+dx[k],yy=j+dy[k];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&scc[xx][yy]!=scc[i][j]) add(scc[i][j],scc[xx][yy]);
			}
		}
	}
	while(!q.empty()){
		int t=q.front();q.pop();
		for(int i=first[t];i;i=e[i].nxt){
			int v=e[i].v;
			if(!vis[v]) vis[v]=1,dis[v]=dis[t]+1,q.push(v);
		}
	}
	while(t--){
		int i,j;
		ll p;
		scanf("%lld%lld%lld",&i,&j,&p);
		int u=scc[i][j];
		ll t=1ll*dis[u];
		if(t>p) printf("%lld\n",1ll*a[i][j]);
		else printf("%lld\n",((p-t)&1)^(1ll*a[i][j]));   
	}
	return 0;
}