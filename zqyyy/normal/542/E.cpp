#include <bits/stdc++.h>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1005;
int n,m,ans,sum,cnt,dis[N],b[N],pa[N];
bool flg,vis[N];
int find(int x){return x==pa[x]?x:pa[x]=find(pa[x]);}
inline void unin(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;pa[x]=y;
}
vector<int>G[N],c[N];
void dfs(int x,int fa,int col){
	b[x]=col;
	for(auto y:G[x]){
		if(y==fa)continue;
		if(!b[y]){
			dfs(y,x,3-col);
			if(flg)return;
		}else if(b[y]==col){
			flg=1;
			return;
		}
	}
}
queue<int>q;
inline void bfs(int st){
	q.push(st);dis[st]=0,vis[st]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto y:G[x])
			if(!vis[y]){
				dis[y]=dis[x]+1,vis[y]=1;
				sum=max(sum,dis[y]);
				q.push(y);
			}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=m;i++){
		int x=read(),y=read();unin(x,y);
		G[x].push_back(y),G[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(find(i)==i){
			cnt++;
			for(int j=1;j<=n;j++)
				if(find(j)==i)c[cnt].push_back(j);
		}
	for(int i=1;i<=cnt;i++){
		flg=0;dfs(c[i][0],0,1);
		if(flg)puts("-1"),exit(0);
	}
	for(int i=1;i<=cnt;i++){
		sum=0;
		for(auto x:c[i]){
			for(auto y:c[i])vis[y]=0;
			bfs(x);
		}
		ans+=sum;
	}
	return cout<<ans,0;
}