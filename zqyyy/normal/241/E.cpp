#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1007,M=5007;
struct edge{int x,y;}b[M];
struct Edge{
	int to,nxt,w;
}e[M<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]=(Edge){y,head[x],w},head[x]=s_e;
}
int n,m,dis[N],cnt[N];
vector<int>G[N],rG[N];
bool vis[N],v1[N],v2[N];
void dfs1(int x){
	v1[x]=1;
	for(auto y:G[x])if(!v1[y])dfs1(y);
}
void dfs2(int x){
	v2[x]=1;
	for(auto y:rG[x])if(!v2[y])dfs2(y);
}
inline void spfa(){
	queue<int>q;q.push(1),vis[1]=1;
	for(int i=2;i<=n;i++)dis[i]=1e9;
	while(!q.empty()){
		int x=q.front();q.pop(),vis[x]=0;
		if(++cnt[x]>n)puts("No"),exit(0);
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(dis[y]>dis[x]+e[i].w){
				dis[y]=dis[x]+e[i].w;
				if(!vis[y])vis[y]=1,q.push(y);
			}
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();b[i].x=x,b[i].y=y;
		G[x].push_back(y),rG[y].push_back(x);
	}
	dfs1(1),dfs2(n);
	for(int i=1;i<=m;i++){
		int x=b[i].x,y=b[i].y;
		if(v1[x] && v2[x] && v1[y] && v2[y])add_e(x,y,2),add_e(y,x,-1);
	}
	spfa();puts("Yes");
	for(int i=1;i<=m;i++){
		int x=b[i].x,y=b[i].y;
		if(v1[x] && v2[x] && v1[y] && v2[y])printf("%d\n",dis[y]-dis[x]);
		else puts("1");
	}
	return 0;
}