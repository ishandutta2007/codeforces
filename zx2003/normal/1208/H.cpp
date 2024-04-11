#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,K,m,i,j,o,u,v,s[N];
vector<int>e[N],a[N];
int top[N],len[N],bot[N],dep[N],deg[N],sz[N],qsz[N],ma[N],dad[N],rt[N],trs[27][27],mp[27][3];
int st[N],dfn[N],xb,id[N];
bool isl[N];
void dfs(int u,int fa){
	sz[u]=1;dad[u]=fa;dfn[++xb]=u;dep[u]=dep[fa]+1;
	for(int v:e[u])if(v!=fa)dfs(v,u),sz[v]>sz[ma[u]]?ma[u]=v:0,++deg[u],sz[u]+=sz[v];
	if(!isl[u])a[u].resize(deg[u]*2+3);qsz[u]=sz[u]-sz[ma[u]];
}
int pp[N],ps[N],f[N];
inline void fix(int x){
	if(!x)return;
	for(;ps[x]-a[x][pp[x]+deg[x]+1]*2>=pp[x]+1;ps[x]-=a[x][pp[x]+++deg[x]+1]*2);
	for(;ps[x]<pp[x];ps[x]+=a[x][--pp[x]+deg[x]+1]*2);
}
inline void add(int x,int w,int v){if(x)w=min((int)a[x].size()-1,max(w+deg[x]+1,0)),a[x][w]+=v,ps[x]+=w-deg[x]-1>=pp[x]?v:-v;}
int calc(int x,int w){
	if(w>=pp[x])return (ps[x]-a[x][pp[x]+deg[x]+1]*2+(w>pp[x]?1:-1)>=pp[x]+1)+1;
		else return ps[x]-1>=pp[x];
}
struct node{int l,r,md,s;}t[N*2];int tcnt;
inline void maintain(int i){t[i].s=trs[t[t[i].l].s][t[t[i].r].s];}
void reget(int i){int u=t[i].l,v=isl[ma[u]]?f[ma[u]]:pp[ma[u]];t[i].s=calc(u,v-1)+calc(u,v)*3+calc(u,v+1)*9;}
void mdy(int i,int l,int r,int k){
	if(l==r)return reget(i);
	if(k<=t[i].md)mdy(t[i].l,l,t[i].md,k);else mdy(t[i].r,t[i].md+1,r,k);maintain(i);
}
int ask(int i,int l,int r,int k){
	if(k<=l)return t[i].s;
	return k<=t[i].md?trs[ask(t[i].l,l,t[i].md,k)][t[t[i].r].s]:ask(t[i].r,t[i].md+1,r,k);
}
void build(int&x,int l,int r){
	x=++tcnt;if(l==r)return fix(t[x].l=st[l]),reget(x);
	t[x].md=l+r>>1;//without global balance & worse complexity
	build(t[x].r,t[x].md+1,r);build(t[x].l,l,t[x].md);maintain(x);
}
inline int ask(int v){return isl[v]?s[v]:K<=pp[v]+mp[ask(rt[top[v]],1,len[top[v]],dep[v]-dep[top[v]]+1)][1]-1;}
inline void mdy(int v){
	do{
		u=top[v];i=f[u];
		add(dad[u],f[u],-1);
		if(!isl[v])mdy(rt[u],1,len[u],dep[v]-dep[u]+1);else f[v]=s[v]?N:-N;
		if(u!=v)mdy(rt[u],1,len[u],dep[v]-dep[u]);
		if(!isl[u])f[u]=pp[u]+mp[t[rt[u]].s][1]-1;
		add(dad[u],f[u],1);fix(dad[u]);
	}while(v=dad[u],v && f[u]!=i);
}
int main(){
	for(i=0;i<27;++i)mp[i][0]=i%3,mp[i][1]=i/3%3,mp[i][2]=i/9;
	for(i=0;i<27;++i)for(j=0;j<27;++j)trs[i][j]=mp[i][mp[j][0]]+mp[i][mp[j][1]]*3+mp[i][mp[j][2]]*9;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>K;for(i=1;i<n;++i)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	for(i=1;i<=n;++i)cin>>s[i],f[i]=s[i]==-1?0:(isl[i]=1,s[i]?N:-N);top[1]=1;dfs(1,0);
	for(i=n;i;--i)if(u=dfn[i],ma[dad[u]]!=u){
		for(xb=0,v=u;top[st[++xb]=u]=v,ma[u];u=ma[u]);
		bot[v]=u;if(xb>1)build(rt[v],1,len[v]=xb-1),f[v]=pp[v]+mp[t[rt[v]].s][1]-1;add(dad[v],f[v],1);
	}
	for(cin>>m;m--;){
		cin>>o>>v;
		if(o==1)cout<<ask(v)<<'\n';
		if(o==2)cin>>s[v],mdy(v);
		if(o==3)K=v;
	}
	return 0;
}