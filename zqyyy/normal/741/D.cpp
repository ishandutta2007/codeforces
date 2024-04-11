#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
inline char getc(){char c;while(!isalpha(c=getchar()));return c;}
const int N=5e5+7,M=1<<23;
struct Edge{int to,nxt,w;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]=(Edge){y,head[x],w},head[x]=s_e;
}
int n,ans[N],fa[N];
int s_dfn,id[N],son[N],dfn[N],sz[N],dep[N],dis[N];
int v[M|1];
void dfs1(int x){
	dfn[x]=++s_dfn,id[s_dfn]=x,sz[x]=1,dep[x]=dep[fa[x]]+1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		dis[y]=dis[x]^e[i].w,dfs1(y),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,bool flg){	
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;if(y==son[x])continue;
		dfs2(y,0),ans[x]=max(ans[x],ans[y]);
	}
	if(son[x])dfs2(son[x],1),ans[x]=max(ans[x],ans[son[x]]);
	if(v[dis[x]])ans[x]=max(ans[x],v[dis[x]]-dep[x]);
	for(int i=1;i<M;i<<=1)if(v[dis[x]^i])ans[x]=max(ans[x],v[dis[x]^i]-dep[x]);
	v[dis[x]]=max(v[dis[x]],dep[x]);
	for(int j=head[x];j;j=e[j].nxt){
		int y=e[j].to;if(y==son[x])continue;
		for(int k=dfn[y];k<dfn[y]+sz[y];k++){
			int z=id[k];
			if(v[dis[z]])ans[x]=max(ans[x],v[dis[z]]+dep[z]-(dep[x]<<1));
			for(int i=1;i<M;i<<=1)if(v[dis[z]^i])ans[x]=max(ans[x],v[dis[z]^i]+dep[z]-(dep[x]<<1));
		}
		for(int k=dfn[y],z;k<dfn[y]+sz[y];k++)z=id[k],v[dis[z]]=max(v[dis[z]],dep[z]);
	}
	if(!flg)for(int k=dfn[x];k<dfn[x]+sz[x];k++)v[dis[id[k]]]=0;
}
int main(){
	n=read();
	for(int i=2;i<=n;i++){
		fa[i]=read();int w=1<<(getc()-'a');
		add_e(fa[i],i,w);
	}
	dfs1(1),dfs2(1,1);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}