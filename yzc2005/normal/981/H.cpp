#include<bits/stdc++.h>
#define EB emplace_back
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod&&(x-=mod);}
inline int Add(int x,int y){return add(x,y),x;}
inline void sub(int &x,int y){(x-=y)<0&&(x+=mod);}
inline int Sub(int x,int y){return sub(x,y),x;}
inline void mul(int &x,int y){x=1ull*x*y%mod;}
inline int Mul(int x,int y){return 1ull*x*y%mod;}
inline int power(int a,int b,int c=1){for(;b;b>>=1,mul(a,a))if(b&1)mul(c,a);return c;}
const int L=1<<18,N=L+5;
using poly=std::vector<int>;
using ull=unsigned long long;
using uint=unsigned int;
const ull Omg=power(3,(mod-1)/L);
ull Omgs[N];
int rev[N];
void set_up(){
  Omgs[L>>1]=1;
  for(int i=(L>>1)+1;i<L;++i)Omgs[i]=Omgs[i-1]*Omg%mod;
  for(int i=(L>>1)-1;i;--i)Omgs[i]=Omgs[i<<1];
}
int extend(int len){
  int n=1;while(n<len)n<<=1;
  for(int i=0;i<n;++i)rev[i]=(rev[i>>1]>>1)|(i&1?n>>1:0);
  return n;
} 
void dft(ull *a,int n){
  for(int i=0;i<n;++i)if(i<rev[i])std::swap(a[i],a[rev[i]]);
  for(int len=1;len<n;len<<=1){
    if(len==262144)for(int i=0;i<n;++i)a[i]%=mod;
    for(int i=0;i<n;i+=len<<1){
      ull *w=Omgs+len,*p=a+i,*q=p+len;
      for(int j=0;j<len;++j,++w,++p,++q){
        ull tmp=*w**q%mod;
        *q=*p+mod-tmp,*p+=tmp;
      }
    }
  }
  for(int i=0;i<n;++i)a[i]%=mod;
}
poly operator*(const poly &a,const poly &b){
  uint len=a.size()+b.size()-1;poly c(len);
  int n=extend(len);static ull f[N],g[N];
  for(uint i=0;i<n;++i)f[i]=i<a.size()?a[i]:0,g[i]=i<b.size()?b[i]:0;
  dft(f,n),dft(g,n);for(int i=0;i<n;++i)f[i]=f[i]*g[i]%mod;
  std::reverse(f+1,f+n),dft(f,n);int coef=power(n,mod-2);
  for(int i=0;i<len;++i)c[i]=f[i]*coef%mod;return c;
}
int n,k,sz[N],ans,rt,all,val[N],fac[N],ifac[N],pa[N];
std::vector<std::pair<int,int>>g[N];
bool vis[N];
std::pair<int,int>tmp[N];
poly seg[N<<2];
void build(int p,int l,int r){
  if(l==r){seg[p]=poly{1,tmp[l].first};return;}
  int mid=l+r>>1;build(p<<1,l,mid),build(p<<1|1,mid+1,r);
  seg[p]=seg[p<<1]*seg[p<<1|1];
}
void solve(int p,int l,int r,poly cur){
  if(l==r){val[tmp[l].second]=cur[1];return;}
  int mid=l+r>>1;poly ls=cur*seg[p<<1|1],rs=cur*seg[p<<1];
  ls.resize(r-l+2),rs.resize(r-l+2);
  solve(p<<1,l,mid,{ls.end()-(mid-l+2),ls.end()});
  solve(p<<1|1,mid+1,r,{rs.end()-(r-mid+1),rs.end()});
}
void getrt(int u,int fa){
  sz[u]=1;int mx=0;
  for(auto p:g[u]){
    int v=p.first;
    if(v!=fa&&!vis[v])getrt(v,u),sz[u]+=sz[v],mx=std::max(mx,sz[v]);
  }
  if(std::max(mx,all-sz[u])<=all/2)rt=u;
}
void solve(int u){
  vis[u]=true;int sum=0,cur;
  std::function<void(int,int)>dfs=[&](int u,int fa){
    sz[u]=1;
    for(auto p:g[u]){
      int v=p.first;
      if(v!=fa&&!vis[v])add(cur,val[p.second^1]),dfs(v,u),sz[u]+=sz[v];
    }
  };
  for(auto p:g[u]){
    int v=p.first;
    if(!vis[v])cur=val[p.second^1],dfs(v,u),add(ans,Mul(cur,Add(sum,val[p.second]))),add(sum,cur);
  }
  for(auto p:g[u]){
    int v=p.first;
    if(!vis[v])all=sz[v],getrt(v,u),solve(rt);
  }
}
int to[N];
int main(){
  set_up(),scanf("%d%d",&n,&k);
  if(n==1)return puts("0"),0;
  if(k==1)return printf("%d\n",1ll*n*(n-1)/2%mod),0;
  for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),g[u].EB(v,i*2),g[v].EB(u,i*2+1),to[i*2]=v,to[i*2+1]=u;
  auto init=[&](int n){
    for(int i=fac[0]=1;i<=n;++i)fac[i]=Mul(fac[i-1],i);
    ifac[n]=power(fac[n],mod-2);for(int i=n-1;~i;--i)ifac[i]=Mul(ifac[i+1],i+1); 
  };init(std::max(n,k));
  std::function<void(int)>dfs=[&](int u){
    sz[u]=1;
    for(auto p:g[u]){
      int v=p.first;
      if(v!=pa[u])pa[v]=u,dfs(v),sz[u]+=sz[v];
    }
  };dfs(1);
  auto get=[&](int x,int id){
    int y=to[id^1];
    if(pa[x]==y)return sz[x];
    return n-sz[y];
  };
  for(int u=1;u<=n;++u){
    int tot=0;for(auto p:g[u])tmp[++tot]={get(p.first,p.second),p.second};
    poly E(tot+1);for(int i=0;i<=tot;++i)E[tot-i]=(k>=i)?ifac[k-i]:0;
    build(1,1,tot),solve(1,1,tot,E);
  }
  all=n,getrt(1,0),solve(rt);
  printf("%d\n",Mul(ans,Mul(fac[k],fac[k])));
  return 0;
}