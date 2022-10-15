#include <cstdio>
#include <set>
#include <vector>
const int PW=20,N=2e5+10;
int T,n,m,q,cnt,f[N],dep[N],pdep[N],dbl[PW][N];
std::vector<int> son[N];
struct range{
	int l,r,v;
	range(){};
	range(int l,int r,int v):l(l),r(r),v(v){};
	inline bool operator<(const range &nxt)const{return l<nxt.l;}
};std::set<range> set[N];
inline int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
void dfs(int u){
	for(int i:son[u]){
		if(dep[i])continue;
		dep[i]=dep[u]+1,dfs(i);
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v])u^=v^=u^=v;
	for(int i=PW-1;~i;--i)if(dep[u]+(1<<i)<=dep[v])v=dbl[i][v];
	if(u==v)return u;
	for(int i=PW-1;~i;--i)if(dbl[i][u]!=dbl[i][v])u=dbl[i][u],v=dbl[i][v];
	return dbl[0][u];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&m,&q),cnt=n;
		for(int i=1;i<=(n<<1);++i)f[i]=i,dep[i]=pdep[i]=dbl[0][i]=0,set[i].clear(),set[i].insert(range(i,i,i)),son[i].clear();
		for(int u,v,fu,fv,c=1;c<=m;++c){
			scanf("%d %d",&u,&v),fu=find(u),fv=find(v);
			if(set[fu].size()>set[fv].size())fu^=fv^=fu^=fv;
			if(fu==fv)continue;f[fu]=fv;
			for(range i:set[fu]){
				set[fv].insert(i);
				auto it=set[fv].upper_bound(i);
				if(it!=set[fv].end()&&it->l==i.r+1){
					dbl[0][i.v]=dbl[0][it->v]=++cnt;
					range nxt=range(i.l,it->r,cnt);pdep[cnt]=c;
					set[fv].erase(i),set[fv].erase(it),set[fv].insert(nxt),i=nxt;
				}
				it=set[fv].lower_bound(i);
				if(it!=set[fv].begin()&&(--it)->r==i.l-1){
					dbl[0][i.v]=dbl[0][it->v]=++cnt;
					range nxt=range(it->l,i.r,cnt);pdep[cnt]=c;
					set[fv].erase(i),set[fv].erase(it),set[fv].insert(nxt);
				}
			}
		}
		for(int i=1;i<cnt;++i)son[dbl[0][i]].push_back(i);dep[cnt]=1,dfs(cnt);
		for(int i=1;i<PW;++i)for(int j=1;j<=cnt;++j)dbl[i][j]=dbl[i-1][dbl[i-1][j]];
		for(int l,r,i=1;i<=q;++i)scanf("%d %d",&l,&r),printf("%d ",pdep[lca(l,r)]);
		putchar('\n');
	}
	return 0;
}