#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int>>V;
const int N=1e5+5,U=1e7,M=67e4,mo=1e9+7;
int lo[N*2],pr[M],pcnt,mn[U+5];bool bb[U+5];
inline void inip(){for(int i=2;i<=U;++i)if(!bb[i]){pr[++pcnt]=i;for(int j=i;j<=U;j+=i)!bb[j]?bb[j]=1,mn[j]=pcnt:0;}}
inline V factor(int x){V ret;for(;x>1;){int y=mn[x],c=0;for(;x%pr[y]==0;x/=pr[y],++c);ret.push_back({y,c});}return ret;}
struct tree{
	struct edge{int to,next;}e[N*2];
	int h[N],ecnt;
	inline void add1(int x,int y){e[++ecnt]=(edge){y,h[x]};h[x]=ecnt;}
	inline void add2(int x,int y){add1(x,y);add1(y,x);}
};
struct OT:tree{
	int f[20][N*2],id[N],dfnn[N*2],dfn[N],dcnt,eucnt;
	void dfs(int x,int fa){
		dfn[++dcnt]=x;dfnn[id[x]=++eucnt]=x;f[0][eucnt]=id[x];
		for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa)dfs(e[i].to,x),f[0][++eucnt]=id[x];
	}
	void ini(){
		dfs(1,0);
		for(int i=1;(1<<i)<=eucnt;++i)for(int j=1;j+(1<<i)-1<=eucnt;++j)f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
	}
	inline int lca(int x,int y){
		x=id[x];y=id[y];if(x>y)swap(x,y);
		int l=lo[y-x+1];return dfnn[min(f[l][x],f[l][y-(1<<l)+1])];
	}
}t1;
int lm,mi[N*25],w[N],nwp;
struct VT:tree{
	int su[N][25],fa[N];
	void dfs(int x){
		for(int i=h[x];i;i=e[i].next){
			int y=e[i].to;
			memcpy(su[y],su[x],lm+1<<2);++su[y][w[y]];dfs(y);
		}
	}
	int aa[N],tp;
	void addd(int x,int y){fa[y]=x;add1(x,y);aa[++tp]=y;}
	inline void build(int*a,int l){
		static int st[N];int w=1,i,x;
		st[1]=1;st[2]=0;aa[tp=1]=1;
		for(i=0;i<l;++i)if(a[i]!=st[w]){
			x=t1.lca(st[w],a[i]);
			for(;w && t1.id[st[w]]>t1.id[x];--w)if(st[w+1])addd(st[w],st[w+1]);
			if(st[w+1])addd(x,st[w+1]);
			if(st[w]!=x)st[++w]=x;st[++w]=a[i];st[w+1]=0;
		}
		for(i=1;i<w;++i)addd(st[i],st[i+1]);
		memset(su[1],0,lm+1<<2);++su[1][::w[1]];dfs(1);
		x=0;for(i=1;i<=tp;++i)x+=::w[aa[i]];for(i=*mi=1;i<=x;++i)mi[i]=1ll*mi[i-1]*nwp%mo;
	}
	inline void clear(){for(;tp;)h[aa[tp--]]=0;ecnt=0;}
	inline int ask(int x,int y,int w){
		int i,z=t1.lca(x,y),tot=0;
		for(i=0;i<=lm;++i)tot+=(su[x][i]+su[y][i]-su[z][i]-su[fa[z]][i])*min(w,i);
		return mi[tot];
	}
}t2;
int n,u,v,x,a[N],q,i,ans[N];
V v1[M];
vector<int>v3[N];
struct que{int u,v,x,i;};
vector<que>v2[M];
int main(){
	for(i=2;i<N*2;++i)lo[i]=lo[i>>1]+1;inip();
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<n;++i)cin>>u>>v,t1.add2(u,v);t1.ini();
	for(i=1;i<=n;++i)cin>>a[i];
	for(cin>>q,i=1;i<=q;++i){
		cin>>u>>v>>x;
		if(u==v){ans[i]=__gcd(a[u],x);continue;}
		for(auto w:factor(x))v2[w.first].push_back((que){u,v,w.second,i})
			,v3[u].push_back(w.first),v3[v].push_back(w.first);
		ans[i]=1;
	}
	for(i=1;i<=n;++i){
		u=t1.dfn[i];
		for(auto v:factor(a[u]))v1[v.first].push_back({u,v.second});
		for(int x:v3[u])if(v1[x].empty() || v1[x].back().first!=u)v1[x].push_back({u,0});
	}
	for(i=1;i<=pcnt;++i)if(!v1[i].empty()){
		nwp=pr[i];
		for(x=1,lm=0;x<=U/nwp;x*=nwp,++lm);
		static int aa[N];int xb=0;
		for(auto z:v1[i])tie(u,v)=z,aa[xb++]=u,w[u]=v;
		t2.build(aa,xb);for(auto z:v2[i])ans[z.i]=1ll*ans[z.i]*t2.ask(z.u,z.v,z.x)%mo;t2.clear();
		for(auto z:v1[i])tie(u,v)=z,w[u]=0;
	}
	for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}