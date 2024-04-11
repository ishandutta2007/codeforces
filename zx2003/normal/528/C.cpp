#include<bits/stdc++.h>
const int N=1e5+5;
int n,m,i,x,y,d[N],h[N],ans[N*3],xb;
struct edge{int to,next;}e[N*6];int ecnt=1;
inline void addedge(int x,int y){
	e[++ecnt]=(edge){y,h[x]};h[x]=ecnt;
	e[++ecnt]=(edge){x,h[y]};h[y]=ecnt;
}
bool vi[N*3];
void dfs(int x){
	for(int&i=h[x];i;){
		int y=e[i].to,t=i;i=e[i].next;if(vi[t>>1])continue;
		vi[t>>1]=1;dfs(y);ans[++xb]=t;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",&x,&y),d[x]^=1,d[y]^=1,addedge(x,y);
	x=0;for(i=1;i<=n;++i)if(d[i])x?addedge(x,i),++m,x=0:x=i;if(m&1)addedge(1,1),++m;
	dfs(1);
	printf("%d\n",m);
	for(i=1;i<=m;++i)printf("%d %d\n",e[ans[i]^(i&1)].to,e[ans[i]^(i&1)^1].to);
	return 0;
}