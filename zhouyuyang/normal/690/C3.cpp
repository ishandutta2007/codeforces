#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],dep[N],f[N],fa[N][18];
int n,x,y,ans,tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int y){
	fa[x][0]=y; dep[x]=dep[y]+1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=y) dfs(e[i].to,x);
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=0;i<=17;i++,tmp/=2)
		if (tmp&1) x=fa[x][i];
	for (int i=17;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		scanf("%d",&f[i]);
		add(i,f[i]); add(f[i],i);
	}
	dfs(1,0);
	for (int i=1;i<=17;i++)
		for (int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	x=1,y=1,ans=0;
	for (int i=2;i<=n;i++){
		int lax=x,lay=y;
		int tmp=dis(i,lax);
		if (tmp>ans) ans=tmp,x=i,y=lax;
		tmp=dis(i,lay);
		if (tmp>ans) ans=tmp,x=i,y=lay;
		printf("%d ",ans);
	}
}