#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,u,v,i,j,fff,fa[N],val[N];
bool inq[N];
vector<int>e[N],ve;
int sz[N],f[N],rt;
void dfs(int u,int fa){
	sz[u]=1;
	for(int v:e[u])if(v!=fa)dfs(v,u),sz[u]+=sz[v],f[u]=max(f[u],sz[v]);
	f[u]=max(f[u],n-sz[u]);if(f[u]<f[rt])rt=u;
}
int main(){
	scanf("%d",&n);
	if(n==1)return 0;
	if(n==2)return puts("1 2 1"),0;
	for(i=1;i<n;++i)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	f[0]=1<<30;dfs(1,0);
	for(int v:e[rt])if(sz[v]>sz[rt])sz[v]=n-sz[rt];
	for(int v:e[rt])ve.push_back(sz[v]),fa[v]=rt;
	u=0;
	fff=2*n*n/9;
	srand(19260817);
	for(;;){
		u=0;
		random_shuffle(e[rt].begin(),e[rt].end());
		for(i=0;i<e[rt].size();++i)ve[i]=sz[e[rt][i]];
		for(i=0;i<e[rt].size();++i){
			u+=ve[i];
			if((u+1)*(n-1-u+1)>fff)break;
		}
		if(i<e[rt].size())break;
	}
	static int q[N];int t,w;
	inq[rt]=1;
	for(j=t=w=0;j<=i;++j)inq[q[++w]=e[rt][j]]=1;
	for(;t<w;){
		int x=q[++t];
		for(int y:e[x])if(!inq[y])q[++w]=y,fa[y]=x,inq[y]=1;
	}
	for(i=1;i<=w;++i)val[q[i]]=i;
	for(i=1;i<=w;++i)printf("%d %d %d\n",fa[q[i]],q[i],val[q[i]]-val[fa[q[i]]]);
	t=w=0;
	for(;j<e[rt].size();++j)inq[q[++w]=e[rt][j]]=1;
	for(;t<w;){
		int x=q[++t];
		for(int y:e[x])if(!inq[y])q[++w]=y,fa[y]=x,inq[y]=1;
	}
	for(i=1;i<=w;++i)val[q[i]]=i*(u+1);
	for(i=1;i<=w;++i)printf("%d %d %d\n",fa[q[i]],q[i],val[q[i]]-val[fa[q[i]]]);	
	return 0;
}