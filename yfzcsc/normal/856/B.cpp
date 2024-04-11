#include<bits/stdc++.h>
#define maxn 1000100
using namespace std;
struct edge{int r,nxt;}e[maxn<<1];
int q[maxn],l,r,T,trie[maxn][26],n,f[maxn],g[maxn],fail[maxn],dep[maxn],rt,ptr;
int head[maxn],esz,tg[maxn];
char str[maxn];
void addedge(int u,int v){
//	printf("[%d->%d]\n",u,v);
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
}
void insert(){
	int nw=rt;
	for(int i=1;str[i];i++){
		if(!trie[nw][str[i]-'a'])nw=trie[nw][str[i]-'a']=++ptr,dep[ptr]=i;
		else nw=trie[nw][str[i]-'a'];
	}
}
void build(){
	l=r=0,q[r++]=rt,fail[rt]=1;
	while(l<r){
		int u=q[l++];
		for(int i=0;i<26;++i)if(trie[u][i]){
			int v=trie[u][i];
			if(u==1){
				fail[v]=1;
			} else {
				int x=fail[u];
				while(x!=1&&!trie[x][i])x=fail[x];
				if(trie[x][i])fail[v]=trie[x][i];
				else fail[v]=1;
			}
			q[r++]=v;
		}
	}
}
void dfs(int u){
	f[u]=1,g[u]=0;
	for(int t=head[u];t;t=e[t].nxt)
		dfs(e[t].r),f[u]+=g[e[t].r],g[u]+=max(f[e[t].r],g[e[t].r]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=ptr;++i)
			for(int j=0;j<26;++j)
				trie[i][j]=0;
		for(int i=1;i<=ptr;++i)f[i]=g[i]=tg[i]=0,head[i]=0;esz=0;
		scanf("%d",&n),rt=1,ptr=1;
		for(int i=1;i<=n;++i)
			scanf("%s",str+1),insert();
		build();
		for(int i=2;i<=ptr;++i)
			if(dep[i]-dep[fail[i]]==1)
				addedge(fail[i],i),tg[i]=1;
		int ans=0;
		dfs(1),ans+=g[1];
		for(int i=2;i<=ptr;++i)if(!f[i])dfs(i);
		for(int i=2;i<=ptr;++i)if(!tg[i])ans+=max(f[i],g[i]);
		printf("%d\n",ans);
	}
}