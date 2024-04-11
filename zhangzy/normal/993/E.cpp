//#pragma GCC optimize("Ofast","inline","-ffast-math")
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define rint register int
#define poly vector<int>
 
const int mod=998244353, gen=3;
const int MXFF=19, MXLL=(1<<MXFF)+5;
 
ll K(ll x,ll y=mod-2){
  ll t=1;
  for (;y;y>>=1, x=x*x%mod)
    if (y&1) t=t*x%mod;
  return t;
}
inline int fix(int x){
  return x>=mod? x-mod: x;
}
poly FIX(poly a){
  for (;a.size()&&!a.back();) a.pop_back(); return a;
}
 
namespace is998{
  void dft(poly &_a,int n){
    _a.resize(1<<n); int *a=&(_a.front());
    static int W[MXLL], *las=W, *hea[MXFF], mx=0, dp[MXLL];
    if (n>mx){
      for (int o=mx;o<n;++o){
        hea[o]=las; ll w=1, w0=K(gen,(mod-1)>>(o+1));
        for (int j=0;j<(1<<o);++j) *las++=w, w=w*w0%mod;
      }
      mx=n;
    }
    for (int i=1;i<(1<<n);++i){
      dp[i]= i&1? dp[i^1]|1<<(n-1): dp[i>>1]>>1;
      if (i<dp[i]) swap(a[i],a[dp[i]]);
    }
    for (int o=0;o<n;++o){
      int len=1<<o;
      for (int i=0;i<(1<<n);i+=len*2){
        int *l=a+i, *r=a+i+len, *w=hea[o];
        for (rint j=0;j<len;++j){
          int x=*l, y=(ll)(*r)*(*w++)%mod;
          *l= fix(x+y);
          *r= fix(x+mod-y);
          ++l; ++r;
        }
      }
    }
  }
  void idft(poly &a,int n){
    a.resize(1<<n); reverse(a.begin()+1,a.end());
    dft(a,n); ll inv=K(1<<n);
    for (rint i=0;i<(1<<n);++i) a[i]=(ll)a[i]*inv%mod;
  }
  poly gao(poly a,poly b,int type=1,int aim=-1){
    int n=0; if (aim==-1) aim=(a.size()-1)*type+(b.size()-1)+1;
    for (;aim>(1<<n);) ++n; dft(a,n); dft(b,n);
    if (type==1){
      for (int i=0;i<(1<<n);++i) a[i]=(ll)a[i]*b[i]%mod;
    }else if (type==2){
      for (int i=0;i<(1<<n);++i) a[i]=(ll)a[i]*a[i]%mod*b[i]%mod;
    }else for (int i=0;i<(1<<n);++i) a[i]=K(a[i],type)*b[i]%mod;
    idft(a,n); a.resize(aim); return FIX(a);
  }
}
 
namespace not998{
  typedef double db;
  const db pi=acos(-1), pi2=pi*2;
   
  struct cp{ db x, y; };
   
  inline cp operator + (const cp &a,const cp &b){
    return (cp){a.x+b.x,a.y+b.y};
  }
  inline cp operator - (const cp &a,const cp &b){
    return (cp){a.x-b.x,a.y-b.y};
  }
  inline cp operator * (const cp &a,const cp &b){
    return (cp){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
  }
  inline cp operator * (const cp &a,const db &b){
    return (cp){a.x*b,a.y*b};
  }
  inline cp operator / (const cp &a,const db &b){
    return a*(1/b);
  }
 
  void dft(cp *a,int n){
    static cp W[MXLL], *las=W, *hea[MXFF];
    static int mx=0, dp[MXLL];
    if (mx<n){
      for (int o=mx;o<n;++o){
        hea[o]=las;
        for (int i=0;i<(1<<o);++i)
          *las++=(cp){cos(pi2*i/(1<<o+1)),sin(pi2*i/(1<<o+1))};
      }
      mx=n;
    }
    for (int i=1;i<(1<<n);++i){
      dp[i]= i&1? dp[i^1]|1<<(n-1): dp[i>>1]>>1;
      if (i<dp[i]) swap(a[i],a[dp[i]]);
    }
    for (int o=0;o<n;++o){
      int len=1<<o;
      for (int i=0;i<(1<<n);i+=len*2){
        cp *l=a+i, *r=a+i+len, *w=hea[o];
        for (rint j=0;j<len;++j){
          cp x=*l, y=(*r)*(*w++);
          *l=x+y; *r=x-y;
          ++l; ++r;
        }
      }
    }
  }
  void idft(cp *a,int n){
    reverse(a+1,a+(1<<n)); dft(a,n);
    for (int i=0;i<(1<<n);++i) a[i]=a[i]/(1<<n);
  }
  const cp I=(cp){0,1};
  cp gaydft(cp *a,int ty,int i,int n){
    cp u=a[i], v=a[((1<<n)-i)%(1<<n)]; v.y*=-1;
    return ty==0? (u+v)/2: (u-v)/2*I*-1;
  }
  cp A[MXLL], B[MXLL], C[MXLL], nil;
  poly gao(poly a,poly b,int type=1,int aim=-1){
    if (type>1) return gao(a,gao(a,b,1,aim),type-1,aim);
    int n=0; if (aim==-1) aim=(a.size()-1)*type+(b.size()-1)+1;
    for (;aim>(1<<n);) ++n;
    int bas=sqrt(mod);
    for (int i=0;i<(1<<n);++i)
      A[i]= i<a.size()? (cp){a[i]%bas,a[i]/bas}: nil;
    dft(A,n);
    for (int i=0;i<(1<<n);++i)
      B[i]= i<b.size()? (cp){b[i]%bas,b[i]/bas}: nil;
    dft(B,n);
    a.resize(0); a.resize(aim);
    for (int u=0;u<=1;++u){;
      for (int i=0;i<(1<<n);++i)
        C[i]= gaydft(A,u,i,n)*gaydft(B,0,i,n);
      for (int i=0;i<(1<<n);++i)
        C[i]= C[i]+ gaydft(A,u,i,n)*gaydft(B,1,i,n)*I;
      idft(C,n);
      ll now=u? bas: 1;
      for (int i=0;i<aim;++i)
        a[i]=(a[i]+(ll)(C[i].x+0.5)%mod*now)%mod;
      now=now*bas%mod;
      for (int i=0;i<aim;++i)
        a[i]=(a[i]+(ll)(C[i].y+0.5)%mod*now)%mod;
    }
    return a;
  }
}
 
poly operator + (poly a,poly b){
  a.resize(max(a.size(),b.size()));
  for (unsigned i=0;i<b.size();++i) a[i]=fix(a[i]+b[i]);
  return FIX(a);
}
poly operator - (poly a,poly b){
  a.resize(max(a.size(),b.size()));
  for (unsigned i=0;i<b.size();++i) a[i]=fix(a[i]+mod-b[i]);
  return a;
}
int chk(){
  static int res=-1;
  if (res==-1){
    int p=mod-1; res= p%(1<<MXFF)==0;
    for (int i=2;i*i<=p&&res;++i)
      if (p%i==0&&(K(gen,i)==1||K(gen,p/i)==1)) res=0;
  }
  return res;
}
poly magicmul(poly a,poly b,int type=1,int aim=-1){
  return chk()? is998::gao(a,b,type,aim): not998::gao(a,b,type,aim);
}
poly operator * (poly a,poly b){
  return chk()? is998::gao(a,b,1,-1): not998::gao(a,b,1,-1);
}
poly operator * (poly a,int k){
  for (unsigned i=0;i<a.size();++i) a[i]=(ll)a[i]*k%mod;
  return a;
}
 
poly pinv(poly A,int n){ // [0,n)
  A.resize(n); poly B;
  if (n==1){
    B.push_back(K(*A.begin()));
    return B;
  }
  B=pinv(A,n+1>>1); A=magicmul(B,A,2,n*1.5+5);
  B.resize(n); for (int i=n+1>>1;i<n;++i) B[i]=fix(mod-A[i]);
  return B;
}
poly operator / (poly a,poly b){
  poly c; int n=a.size()-1, m=b.size()-1;
  if (n<m) return c;
  reverse(a.begin(),a.end()); a.resize(n-m+1);
  reverse(b.begin(),b.end()); b.resize(n-m+1);
  c=a*pinv(b,n-m+1); c.resize(n-m+1);
  reverse(c.begin(),c.end()); return c;
}
poly operator % (poly a,poly b){
  if (a.size()<b.size()) return a;
  return FIX(a-a/b*b);
}
 
poly dao(poly a){
  int sz=a.size();
  for (int i=1;i<sz;++i) a[i-1]=(ll)i*a[i]%mod;
  a.pop_back(); return a;
}
poly idao(poly a){
  static int pinv[MXLL+5]; int sz=a.size();
  pinv[0]=pinv[1]=1;
  for (int i=2;i<=sz;++i) pinv[i]=(ll)(mod-mod/i)*pinv[mod%i]%mod;
  a.push_back(0);
  for (int i=sz;i>=1;--i) a[i]=(ll)a[i-1]*pinv[i]%mod;
  a[0]=0; return a;
}
poly pln(poly a,int n){ // [0,n)
  a=dao(a)*pinv(a,n); a.resize(n-1); return idao(a);
}
poly pexp(poly a,int n){ // [0,n)
  a.resize(n); poly b, one; one.push_back(1);
  if (n==1) return one;
  b=pexp(a,n+1>>1); a=magicmul(a-pln(b,n)+one,b,1,n+5);
  b.resize(n); for (int i=n+1>>1;i<n;++i) b[i]=a[i];
  return b;
}
 
poly operator << (poly a,int b){
  reverse(a.begin(),a.end());
  a.resize(a.size()+b);
  reverse(a.begin(),a.end());
  return a;
}
poly slowpow(poly a,ll y,int n){
  poly res; res.push_back(1);
  for (;y;y>>=1, a=a*a, a.resize(n))
    if (y&1) res=res*a, res.resize(n);
  return FIX(res);
}
poly fastpow(poly a,ll y,int n){
  if (a.size()>n) a.resize(n);
  a=FIX(a); if (!a.size()) return a;
  int st=0, bas=0;
  for (;!a[st];) ++st;
  if (st*min(y,(ll)n)>=n){ a.resize(0); return a; }
  if (st){
    for (int i=0;i+st<a.size();++i) a[i]=a[i+st];
    a.resize(a.size()-st);
  }
  bas=a.front(); ll pinv=K(bas);
  for (auto &o:a) o=o*pinv%mod;
  a=FIX(pexp(pln(a,n)*(y%mod),n));
  if (st){
    a=a<<(st*y);
    a.resize(n); a=FIX(a);
  }
  bas=K(bas,y%(mod-1));
  for (auto &o:a) o=(ll)o*bas%mod;
  return FIX(a);
}
 
poly BM(poly S){
  poly Ci, Cj; Ci.push_back(1);
  int i=0, j=-1, di, dj=1;
  for (;i<(int)S.size();++i){
    di=0; auto it=S.begin()+i;
    for (auto o:Ci) di=(di+(ll)o*(*it--))%mod;
    if (di/*&&Ci.size()>Cj.size()*/){
      poly tmp=Ci*dj-(Cj*di<<(i-j));
      Cj=Ci, dj=di, j=i;
      Ci=tmp;
    }
  }
  return Ci;
}
 
poly modpow(poly x,ll y,poly p){
  poly res; res.push_back(1);
  for (;y;y>>=1, x=x*x%p)
    if (y&1) res=res*x%p;
  return res;
}
int BMque(poly S,ll m,poly p){
  reverse(p.begin(),p.end());
  poly bas; bas.push_back(0); bas.push_back(1);
  poly res=modpow(bas,m,p);
  int ans=0;
  for (int i=0;i<(int)res.size();++i)
    ans=(ans+(ll)res[i]*S[i])%mod;
  return ans;
}
int BMque(poly S,ll m){
  return BMque(S,m,BM(S));
}
 
namespace multicalc{
  vector<poly>vec; poly res;
  int id(int l,int r){ return l+r|l!=r; }
  void pre(int l,int r,poly &w){
    int x=id(l,r);
    if (l==r){
      vec[x].resize(0);
      vec[x].push_back(fix(mod-w[l]));
      vec[x].push_back(1);
      return;
    }
    int mid=l+r>>1;
    pre(l,mid,w); pre(mid+1,r,w);
    vec[x]=vec[id(l,mid)]*vec[id(mid+1,r)];
  }
  void doit(poly a,int l,int r,poly &w){
    int x=id(l,r);
    if (a.size()>=vec[x].size()) a=a%vec[x];
    if (r-l<=50){
      for (int i=l;i<=r;++i){
        ll bas=1, sum=0;
        for (auto o:a){
          sum=(sum+o*bas)%mod;
          bas=bas*w[i]%mod;
        }
        res[i]=sum;
      }
      return;
    }
    int mid=l+r>>1;
    doit(a,l,mid,w); doit(a,mid+1,r,w);
  }
  poly gao(poly a,poly w,int fl=0){
    int sz=w.size();
    vec.resize(sz*2+5); res.resize(sz);
    pre(0,sz-1,w);
    if (fl) a=dao(vec[id(0,sz-1)]);
    doit(a,0,sz-1,w); return res;
  }
}
 
namespace multiinte{
  int id(int l,int r){ return l+r|l!=r; }
  poly doit(int l,int r,poly &x,poly &y){
    if (l==r){
      poly a; a.push_back(y[l]);
      return a;
    }
    int mid=l+r>>1;
    return doit(l,mid,x,y)*multicalc::vec[id(mid+1,r)]
      +doit(mid+1,r,x,y)*multicalc::vec[id(l,mid)];
  }
  poly gao(poly x,poly y){
    int sz=x.size();
    poly a, b=multicalc::gao(a,x,1);
    for (int i=0;i<sz;++i) y[i]=y[i]*K(b[i])%mod;
    return doit(0,sz-1,x,y);
  }
}
 
poly ra(int n){ // [0,n)
  poly a; a.resize(n);
  for (int i=0;i<n;++i) a[i]=rand()%mod;
  return a;
}


int n, x;
poly a, b;
ll ans[1001000];

void fuck(poly a,poly b){
    cerr<<n<<' '<<a.size()<<' '<<b.size()<<endl;
    poly a1, a2, b1, b2;
    a1.resize(n+1);
    a2.resize(n+1);
    b1.resize(n+1);
    b2.resize(n+1);
    ll B=1000;
    for (int i=0;i<=n;++i){
        a1[i]=a[i]%B;
        a2[i]=a[i]/B;
        b1[i]=b[i]%B;
        b2[i]=b[i]/B;
    }
    poly c1=a1*b1; poly c2=a1*b2+a2*b1; poly c3=a2*b2;
    cerr<<c1.size()<<' '<<c2.size()<<' '<<c3.size()<<endl;
    c1.resize(2*n+1); c2.resize(2*n+1); c3.resize(2*n+1);
    for (int i=n;i<=n+n;++i)
        ans[i-n]=c1[i]+c2[i]*B+c3[i]*B*B;
}

int main(){
    cin>>n>>x;
    int now=0; a.resize(n+1); a[now]=1;
    for (int i=1;i<=n;++i){
        int t; scanf("%d",&t);
        now+=t<x;
        ++a[now];
    }
    b.resize(n+1);
    for (int i=0;i<=n;++i) b[i]=a[n-i];
    fuck(a,b);
    ans[0]=(ans[0]-n)/2;
    for (int i=0;i<=n;++i) printf("%lld ",ans[i]);
    puts("");
}