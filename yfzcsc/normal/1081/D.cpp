#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
vector<int>G[maxn<<1];
struct data{
	int u,v,w;
	void rd(){
		scanf("%d%d%d",&u,&v,&w);
	}
	int operator<(const data& d)const{
		return w<d.w;
	}
}d[maxn<<1];
int f[maxn],val[maxn<<1],n,m,k,xi[maxn],rt[maxn],ptr,tg[maxn];
int ex[maxn<<1],anses[maxn];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void dfs(int u){
	if(u<=n&&tg[u])ex[u]=1;
	for(auto v:G[u])dfs(v),ex[u]|=ex[v];
}
void dfs2(int u,int ans){
	int cnt=0;
	if(u<=n&&tg[u]){
		anses[tg[u]]=ans;
		return ;
	}
	for(auto v:G[u])cnt+=ex[v];
	for(auto v:G[u]){
		int rans=ans;
		if(cnt>=2)rans=max(ans,val[u]);
		else if(!ex[v]&&cnt>=1)rans=max(ans,val[u]);
		dfs2(v,rans);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)scanf("%d",&xi[i]),tg[xi[i]]=i;
	for(int i=1;i<=m;++i)d[i].rd();
	sort(d+1,d+m+1);
	for(int i=1;i<=n;++i)f[i]=i,rt[i]=i;
	ptr=n;
	for(int i=1;i<=m;++i){
		if(find(d[i].u)!=find(d[i].v)){
			++ptr;
			val[ptr]=d[i].w;
			G[ptr].push_back(rt[find(d[i].u)]);
			G[ptr].push_back(rt[find(d[i].v)]);
			f[find(d[i].u)]=find(d[i].v);
			rt[find(d[i].u)]=ptr;
		}
	}
	dfs(ptr);
	dfs2(ptr,0);
	for(int i=1;i<=k;++i)printf("%d ",anses[i]);
}