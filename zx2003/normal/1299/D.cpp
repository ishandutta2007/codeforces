#include<bits/stdc++.h>
using namespace std;
typedef unsigned ui;
const int S=399,N=1e5+5,mo=1e9+7;
inline void add(int&a,const int&b){a+=b-mo;a+=a>>31&mo;}
map<ui,int>mp;
struct LB{
int a[5];
bool ins(int x){
	for(int i=0;i<5;++i)if(x>>i&1){if(!a[i]){a[i]=x;return 1;}x^=a[i];}
	return 0;
}
ui gett(){
	ui ass=0;
	for(int i=0;i<32;++i){
		int v=0;
		for(int j=0;j<5;++j)if(i>>j&1)v^=a[j];
		ass|=1u<<v;
	}
	return ass;
}
}a[S],zz;ui aa[S];int acnt;
int n,m,i,j,trs[S][S],f[2][S],ans,nw,e1[N],e2[N],e3[N],g[N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
vector<pair<int,int>>e[N];
vector<int>ee[N];
int dep[N],dfn[N],dcnt;
bool fll;
vector<int>vv[N];
void dfs(int x,int fa){
	dfn[x]=++dcnt;
	for(auto u:e[x]){
		int y,w;tie(y,w)=u;if(y==fa)continue;
		if(!dfn[y])dep[y]=dep[x]^w,dfs(y,x);else if(dfn[y]<dfn[x])
			fll&=zz.ins(dep[y]^dep[x]^w);
	}
}
inline void doo(){
	memset(zz.a,0,20);fll=1;
	dcnt=0;for(int x:vv[i])dfn[x]=0;dfs(1,0);
	if(!fll)return;
	int z=mp[zz.gett()];
	for(j=1;j<=acnt;++j)if(trs[j][z])add(f[!nw][trs[j][z]],f[nw][j]);
}
void del(int a,int b){
	int i;
	for(i=0;e[a][i].first!=b;++i);e[a].erase(e[a].begin()+i);
	for(i=0;e[b][i].first!=a;++i);e[b].erase(e[b].begin()+i);
}
void add(int a,int b,int w){
	e[a].push_back({b,w});
	e[b].push_back({a,w});
}
int main(){
	acnt=1;aa[1]=a[1].gett();mp[aa[1]]=1;
	for(i=1;i<32;++i){
		int oc=acnt;
		for(j=1;j<=oc;++j)if(!(aa[j]>>i&1)){
			a[++acnt]=a[j],a[acnt].ins(i),aa[acnt]=a[acnt].gett();
			if(mp.count(aa[acnt]))--acnt;else mp[aa[acnt]]=acnt;
		}
	}
	for(i=1;i<=acnt;++i)for(j=1;j<=acnt;++j){
		LB tmp=a[i];bool fl=1;
		for(int k=0;k<5;++k)if(a[j].a[k] && !tmp.ins(a[j].a[k]))fl=0;
		if(fl)trs[i][j]=mp[tmp.gett()];
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)g[i]=i;
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&e1[i],&e2[i],&e3[i]);
		if(e1[i]!=1 && e2[i]!=1)g[gfa(e1[i])]=gfa(e2[i]);
	}
	for(i=1;i<=m;++i)ee[max(gfa(e1[i]),gfa(e2[i]))].push_back(i);
	for(i=2;i<=n;++i)vv[gfa(i)].push_back(i);
	f[0][1]=1;
	for(i=2;i<=n;++i)if(g[i]==i){
		e[1].clear();
		for(int x:ee[i])add(e1[x],e2[x],e3[x]);
		memcpy(f[!nw],f[nw],sizeof f[nw]);
		doo();
		if(e[1].size()==2){
			auto e11=e[1][0],e22=e[1][1];
			del(1,e22.first);
			doo();
			del(1,e11.first);add(1,e22.first,e22.second);
			doo();
		}
		nw^=1;
	}
	for(i=1;i<=acnt;++i)add(ans,f[nw][i]);
	printf("%d\n",ans);
	return 0;
}