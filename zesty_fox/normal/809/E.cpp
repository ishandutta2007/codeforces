#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010,MOD=1e9+7;
int n,a[N],pos[N];
ll ans;
vector<pii> e[N];

ll qpow(ll x,ll y=MOD-2){
	ll res=1;
	while(y){
		if(y&1) (res*=x)%=MOD;
		(x*=x)%=MOD;y>>=1;
	}
	return res;
}

int v[N],p[N],pcnt,phi[N],mu[N];
void init(){
	v[1]=phi[1]=mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i]) {v[i]=i,p[++pcnt]=i,phi[i]=i-1,mu[i]=-1;}
		for(int j=1;j<=pcnt;j++){
			if(p[j]>v[i]||p[j]>n/i) break;
			v[p[j]*i]=p[j];
			phi[p[j]*i]=i%p[j]?phi[i]*(p[j]-1):phi[i]*p[j];
			mu[p[j]*i]=i%p[j]?-mu[i]:0;
		}
	}
}

int dep[N],f[N],siz[N],son[N];
ll dis[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1,siz[x]=1,f[x]=fa;
	
	for(auto tmp:e[x]){
        int y=tmp.fi;
		if(y==fa) continue;
        dis[y]=(dis[x]+tmp.se)%MOD;
		dfs(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]) son[x]=y;
	}
}

int dfn[N],ti,low[N],tp[N];
void dfs_top(int x,int nowtp){
	dfn[x]=++ti,tp[x]=nowtp;
	if(son[x]) dfs_top(son[x],nowtp);
	for(auto tmp:e[x]){
        int y=tmp.fi;
		if(y==f[x]||y==son[x]) continue;
		dfs_top(y,y);
	}
	low[x]=ti;
}

int LCA(int x,int y){
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		x=f[tp[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}

vi vt[N],nodes,req;
int rt,cnt,st[N],stp;
void build_vtree(const vi &_nodes){
	nodes=_nodes;
	sort(nodes.begin(),nodes.end(),[&](const int &x,const int &y){return dfn[x]<dfn[y];});
	cnt=nodes.size();
	for(int i=0;i<cnt-1;i++) nodes.pb(LCA(nodes[i],nodes[i+1]));
	sort(nodes.begin(),nodes.end(),[&](const int &x,const int &y){return dfn[x]<dfn[y];});
	nodes.resize(cnt=unique(nodes.begin(),nodes.end())-nodes.begin());
	
	for(auto x:nodes) vt[x].clear();
	
	stp=0;
	for(auto x:nodes){
		while(stp&&low[st[stp]]<dfn[x]) stp--;
		if(stp) vt[st[stp]].pb(x);
		else rt=x;
		st[++stp]=x;
	}
}

ll sum[N];
void dfs1(int x,int fa,int d){
	if(a[x]%d==0) sum[x]=phi[a[x]];
	else sum[x]=0;
	for(auto y:vt[x]){
		if(y==fa) continue;
		dfs1(y,x,d);
		sum[x]+=sum[y];
	}
	sum[x]%=MOD;
}

ll F[N],G[N];
void solve(int d){
	req.clear();
	for(int i=d;i<=n;i+=d) req.pb(pos[i]);
	build_vtree(req);
	
	dfs1(rt,0,d);
	for(auto x:nodes){
		for(auto y:vt[x]){
			ll len=dis[y]-dis[x];
			F[d]=(F[d]+len%MOD*(sum[rt]-sum[y]+MOD)%MOD*sum[y]*2%MOD)%MOD;
		}
	}
}

int main(){
    n=rdi();init();
    for(int i=1;i<=n;i++) a[i]=rdi(),pos[a[i]]=i;
    for(int i=1;i<n;i++){
		int x=rdi(),y=rdi(),z=1;
		e[x].pb(mp(y,z)),e[y].pb(mp(x,z));
	}
	dfs(1,0),dfs_top(1,1);
	//~ fprintf(stderr,"%d\n",ti);
	assert(ti==n);
	for(int i=1;i<=n;i++) solve(i);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i) G[i]=(G[i]+F[j]*mu[j/i])%MOD;
		G[i]=(G[i]%MOD+MOD)%MOD;
	}
	for(int i=1;i<=n;i++) ans+=i*qpow(phi[i])%MOD*G[i]%MOD;
	ans%=MOD;ans=ans*qpow((ll)n*(n-1)%MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}