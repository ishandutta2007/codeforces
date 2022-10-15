#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define y1 __y1__
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
const int N=4e5+7,INF=1e9;
struct Edge{
	int to,nxt,w;	
}e[N<<6];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]={y,head[x],w},head[x]=s_e;	
}
int dis[N];
bool vis[N];
int n,m,tot,v[507][507][2];
inline int id(int x,int y){
	x++,y++;
	assert(1<=(x-1)*(n+1)+y && (x-1)*(n+1)+y<=tot);
	return (x-1)*(n+1)+y;	
}
inline void dijkstra(int s){
	for(int i=1;i<=tot;i++)vis[i]=0,dis[i]=INF;
	priority_queue<pair<int,int> >q;
	dis[s]=0,q.push({0,s});
	while(!q.empty()){
		int x=q.top().se;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to,D=dis[x]+e[i].w;
			if(dis[y]>D)dis[y]=D,q.push({-D,y});
		}
	}
}
inline void clear(){
	for(int i=1;i<=tot;i++)head[i]=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)v[i][j][0]=v[i][j][1]=0;
	s_e=0;
}
const int dx[2]={0,1},dy[2]={1,0};
inline void work(){
	m=read(),n=read(),tot=(n+1)*(n+1);
	for(int i=1;i<=m;i++){
		int x1=read(),y1=read(),x2=read(),y2=read();
		if(x1>x2 || y1>y2)swap(x1,x2),swap(y1,y2);
		if(x1<x2)v[x1][y1-1][0]++;
		else v[x1-1][y1][1]++;
		x1=n-x1+1,y1=n-y1+1,x2=n-x2+1,y2=n-y2+1;
		if(x1>x2 || y1>y2)swap(x1,x2),swap(y1,y2);
		if(x1<x2)v[x1][y1-1][0]++;
		else v[x1-1][y1][1]++;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<2;k++){
				int x=i+dx[k],y=j+dy[k];
				if(x>n || y>n)continue;
				add_e(id(i,j),id(x,y),v[i][j][k]);
				add_e(id(x,y),id(i,j),v[i][j][k]);
			}
	dijkstra(id(0,0));
	printf("%d\n",m-dis[id(n/2,n/2)]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work(),clear();
    return 0;
}