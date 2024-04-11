#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define fi first
#define se second
const int N=2e5+7,M=1e6+7,mod=1e9+7;
inline int qpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=1ll*a*a%mod)
	if(b&1)res=1ll*res*a%mod;
    return res;
}
int s_p,pr[M],v[M],phi[M],mu[M];
inline void init(int n){
    phi[1]=mu[1]=1;
    for(int i=2;i<=n;i++){
	if(!v[i])v[i]=1,phi[i]=i-1,mu[i]=-1,pr[++s_p]=i;
	for(int j=1;j<=s_p && i*pr[j]<=n;j++){
	    v[i*pr[j]]=1;
	    if(i%pr[j]==0){phi[i*pr[j]]=phi[i]*pr[j],mu[i*pr[j]]=0;break;}
	    phi[i*pr[j]]=phi[i]*(pr[j]-1),mu[i*pr[j]]=-mu[i];
	}
    }
}
struct Edge{int to,nxt,w;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
    e[++s_e]={y,head[x],w},head[x]=s_e;
}
int n,a[N],p[N];
int s_dfn,dfn[N],sz[N],dis[N],f[N][18];
void dfs(int x,int fa){
    dfn[x]=++s_dfn,f[x][0]=fa,sz[x]=1;
    for(int i=1;i<=17;i++)f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x],y;i;i=e[i].nxt)
	if((y=e[i].to)!=fa)dis[y]=(dis[x]+e[i].w)%mod,dfs(y,x),sz[x]+=sz[y];
}
inline int LCA(int x,int y){
    if(x==y)return x;if(dfn[x]>dfn[y])swap(x,y);
    for(int i=17;~i;i--)if(dfn[f[y][i]]>dfn[x])y=f[y][i];
    return f[y][0];
}
inline int dist(int x,int y){
    return ((dis[x]+dis[y])%mod+mod-(dis[LCA(x,y)]<<1)%mod)%mod;
}
vector<int>d;
vector<pair<int,int> >G[N];
inline void Add_e(int x,int y){
    G[x].push_back({y,dist(x,y)});
}
int D,sum,tp,stk[N],g[N];
bool flg[N];
void dfs1(int x){
    g[x]=flg[x]?phi[a[x]]:0;
    for(auto i:G[x]){
	int y=i.fi;dfs1(y);
	g[x]=(g[x]+g[y])%mod;
    }
}
void dfs2(int x){
    for(auto i:G[x]){
	int y=i.fi,w=i.se;dfs2(y);
	sum=(sum+2ll*(g[d[0]]-g[y]+mod)*g[y]%mod*w)%mod;
    }
}
inline int work(){
    for(int x:d)flg[x]=1;
    sort(d.begin(),d.end(),[](int x,int y){return dfn[x]<dfn[y];});
    for(int i=d.size()-2;~i;i--)d.push_back(LCA(d[i],d[i+1]));
    sort(d.begin(),d.end(),[](int x,int y){return dfn[x]<dfn[y];});
    d.erase(unique(d.begin(),d.end()),d.end()),tp=0;
    for(int x:d){
	while(tp && dfn[stk[tp]]+sz[stk[tp]]<=dfn[x])tp--;
	if(tp)Add_e(stk[tp],x);stk[++tp]=x;
    }
    sum=0,dfs1(d[0]),dfs2(d[0]);
    for(int x:d)flg[x]=0,G[x].clear(),g[x]=0;
    d.clear();
    return sum;
}
int ff[N],gg[N];
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),p[a[i]]=i;
    for(int i=1;i<n;i++){
	int x=read(),y=read(),w=1;
	add_e(x,y,w),add_e(y,x,w);
    }
    dfs(1,0),init(n);int ans=0;
    for(D=1;D<=n;D++){
	for(int j=D;j<=n;j+=D)d.push_back(p[j]);
	ff[D]=work();
    }
    for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j+=i)gg[i]=(0ll+gg[i]+mod+mu[j/i]*ff[j])%mod;
	ans=(ans+1ll*i*qpow(phi[i],mod-2)%mod*gg[i])%mod;
    }
    ans=1ll*ans*qpow(1ll*n*(n-1)%mod,mod-2)%mod;
    printf("%d\n",ans);
    return 0;
}