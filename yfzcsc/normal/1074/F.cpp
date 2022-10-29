#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e5+10;
set<pii>st;
vector<int>G[maxn];
struct data{
	int ans,mx;
	data(){}
	data(int mx,int ans):ans(ans),mx(mx){}
	data operator+(const data& d)const{
		if(mx==d.mx)return data(mx,ans+d.ans);
		return mx>d.mx?(*this):d;
	} 
}s[maxn<<2];
int atg[maxn<<2],n,Q,dfn[maxn],rig[maxn],tim,fa[20][maxn],dep[maxn];
void _pd(int o,int x){atg[o]+=x,s[o].mx+=x;}
void pd(int o){atg[o]?_pd(o<<1,atg[o]),_pd(o<<1|1,atg[o]),atg[o]=0:0;}
void upd(int o){s[o]=s[o<<1]+s[o<<1|1];}
void build(int o,int l,int r){
	if(l==r){
		s[o].ans=1;
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	upd(o);
}
void mdy(int o,int l,int r,int ql,int qr,int x){
	if(ql>qr)return ;
	if(ql<=l&&r<=qr)return _pd(o,x);
	int mid=l+r>>1;
	pd(o);
	if(ql<=mid)mdy(o<<1,l,mid,ql,qr,x);
	if(qr>mid)mdy(o<<1|1,mid+1,r,ql,qr,x);
	upd(o);
}
void dfs(int u,int f){
	fa[0][u]=f,dep[u]=dep[f]+1,dfn[u]=++tim;
	for(auto v:G[u])if(v!=f)
		dfs(v,u);
	rig[u]=tim;
}
int walk(int u,int d){
	for(int i=0;d>>i;i++)if(d>>i&1)u=fa[i][u];
	return u;
}
int main(){
	scanf("%d%d",&n,&Q);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	build(1,1,n);
	for(int i=1;i<20;++i)
		for(int j=1;j<=n;++j)
			fa[i][j]=fa[i-1][fa[i-1][j]];
	for(int i=1,u,v;i<=Q;++i){
		scanf("%d%d",&u,&v);
		if(pii(dep[u],u)<pii(dep[v],v))swap(u,v);
		int dir=st.count(pii(u,v))?-1:1;
		if(dir<0)st.erase(pii(u,v));
		else st.insert(pii(u,v));
//		printf("[%d]",dir);
		if(walk(u,dep[u]-dep[v])==v){
			int x=walk(u,dep[u]-dep[v]-1);
			mdy(1,1,n,1,dfn[x]-1,dir);
			mdy(1,1,n,rig[x]+1,n,dir);
			mdy(1,1,n,dfn[u],rig[u],dir);
		} else {
			mdy(1,1,n,dfn[u],rig[u],dir);
			mdy(1,1,n,dfn[v],rig[v],dir);
		}
//		printf("{%d,%d}",s[1].mx,s[1].ans);
		printf("%d\n",s[1].mx==st.size()?s[1].ans:0);
	}
}