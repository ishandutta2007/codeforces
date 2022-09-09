#include<bits/stdc++.h>
const int N=55e4;
int B,n,i,a[N],b[N],ans[N],xb;
struct edge{int to,next;}e[N*2];int ecnt=1,h[N*2];bool vi[N];
inline void addedge(int x,int y){
	e[++ecnt]=(edge){y,h[x]};h[x]=ecnt;
	e[++ecnt]=(edge){x,h[y]};h[y]=ecnt;
}
void dfs(int x){
	for(int&i=h[x];i;i=e[i].next)if(!vi[i>>1]){
		int oi=i;
		vi[i>>1]=1;dfs(e[i].to);
		ans[++xb]=oi;
	}
}
int deg[N*2],g[N*2];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
	for(B=0;B<=20;++B){
		memset(deg,0,4<<B);for(i=0;i<1<<B;++i)g[i]=i;
		for(i=1;i<=n;++i){
			int x=a[i]&((1<<B)-1),y=b[i]&((1<<B)-1);
			++deg[x];++deg[y];g[gfa(x)]=gfa(y);
		}
		int z=0,zz=0;
		for(i=0;i<1<<B;++i){
			if(deg[i] && g[i]==i)++z;
			if(deg[i]&1)zz=1;
		}
		if(zz || z>1)break;
	}
	--B;
	for(i=1;i<=n;++i)addedge(a[i]&((1<<B)-1),b[i]&((1<<B)-1));
	for(i=0;i<1<<B && !h[i];++i);dfs(i);
	std::reverse(ans+1,ans+xb+1);
	printf("%d\n",B);
	for(i=1;i<=xb;++i)printf("%d %d%c",
		ans[i]-1,
		(ans[i]^1)-1,
		i==xb?'\n':' ');
}