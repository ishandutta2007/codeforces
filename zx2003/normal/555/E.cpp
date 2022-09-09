#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,q,u,v,w,i,j;
vector<int>e[N];
int dfn[N],low[N],xb,st[N],bel[N],rt[N],fa[N],faa[N],dep[N],f[20][N],bcnt;
int s[N][2];
int aaa[N];
void dfs(int x,int fa){
	aaa[x]=::i;
	::fa[x]=fa;
	dfn[x]=low[x]=++xb;st[++w]=x;
	bool ct=0;
	for(int y:e[x]){
		if(y!=fa || ct){if(!dfn[y]){
			dfs(y,x);
			low[x]=min(low[x],low[y]);
		}else low[x]=min(low[x],dfn[y]);}
		ct+=y==fa;
	}
	if(dfn[x]==low[x]){
		++bcnt;rt[bcnt]=x;
		do{bel[st[w]]=bcnt;}while(st[w--]!=x);
	}
}
inline int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	int dt=dep[v]-dep[u],i;
	for(i=0;i<20;++i)if(dt>>i&1)v=f[i][v];
	if(u==v)return u;
	for(i=19;i>=0;--i)if(f[i][u]!=f[i][v])u=f[i][u],v=f[i][v];
	return f[0][u];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=m;++i)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	for(i=1;i<=n;++i)if(!dfn[i])dfs(i,0);
	for(i=1;i<=bcnt;++i)faa[i]=bel[fa[rt[i]]];for(i=bcnt;i;--i)dep[i]=dep[faa[i]]+1;
	memcpy(f[0]+1,faa+1,n<<2);for(i=1;i<20;++i)for(j=1;j<=n;++j)f[i][j]=f[i-1][f[i-1][j]];
	for(;q--;){
		scanf("%d%d",&u,&v);
		if(aaa[u]!=aaa[v]){puts("No");return 0;}
		u=bel[u];v=bel[v];
		w=lca(u,v);
		++s[u][0];--s[w][0];++s[v][1];--s[w][1];
	}
	for(i=1;i<=bcnt;++i)for(j=0;j<2;++j)s[faa[i]][j]+=s[i][j];
	for(i=1;i<=bcnt;++i)if(s[i][0] && s[i][1])break;
	puts(i<bcnt?"No":"Yes");
	return 0;
}