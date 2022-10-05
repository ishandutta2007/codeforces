#include<bits/stdc++.h>
#define ll long long
#define rint register int
using namespace std;

#define mod 998244353
#define gen 3
#define rint register int
#define N 18
#define M ((1<<18)+233)
ll K(ll x,ll y=mod-2){
  ll t=1; x%=mod;
  for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod;
  return t;
}
namespace FFT{
  int W[N][M], dp[M];
  inline int add(int x){
    return x>=mod? x-mod: x;
  }
  inline int dec(int x){
    return x<0? x+mod: x;
  }
  void fft(int *a,int n){
    for (int i=0;i<1<<n;++i)
      if (i<dp[i])
        swap(a[i],a[dp[i]]);
    for (int o=0;o<n;++o){
      int len=1<<o;
      for (int i=0;i<1<<n;i+=len*2){
        int *l=a+i, *r=a+i+len, x, y;
        for (rint j=0;j<len;++j){
          x=*l, y=(ll)*r*W[o][j]%mod;
          *l= add(x+y);
          *r= dec(x-y);
          ++l; ++r;
        }
      }
    }
  }
  void realmain(int *a,int *b,int la,int lb){
    static int las=-1;
    int n=0; for (;la+lb>=(1<<n);) ++n;
    if (las!=n){
      dp[0]=0;
      for (int i=1;i<(1<<n);++i)
        dp[i]= i&1? dp[i^1]|1<<n-1: dp[i>>1]>>1;
      for (int o=0;o<n;++o){
        int len=1<<o; ll w0=K(gen,(mod-1)/len/2), w=1;
        for (rint j=0;j<len;++j){
          W[o][j]=w; w=w*w0%mod;
        }
      }
      las=n;
    }
    for (rint i=la+1;i<(1<<n);++i) a[i]=0;
    for (rint i=lb+1;i<(1<<n);++i) b[i]=0;
    fft(a,n); fft(b,n);
    for (rint i=0;i<1<<n;++i) a[i]=(ll)a[i]*b[i]%mod;
    reverse(a+1,a+(1<<n));
    fft(a,n); ll inv=K(1<<n);
    for (rint i=0;i<1<<n;++i) a[i]=a[i]*inv%mod;
  }
}

int n, A, B, ans[M], a[M], b[M];
ll jc[M], inv[M], pw[M];

inline void U(int &x,int y){
  x+=y; if (x>=mod) x-=mod;
}

void que(int n){
  if (!n) return (void)(ans[0]=1);
  if (n==1) return (void)(ans[1]=1);
  if (n<=100||n&1){
    que(n-1);
    for (rint i=n;i;--i)
      ans[i]=(ans[i]*(n-1ll)+ans[i-1])%mod;
    return;
  }
  int mid=n>>1; que(mid);
  pw[0]=1; for (rint i=1;i<=mid;++i) pw[i]=pw[i-1]*mid%mod;
  for (rint i=0;i<=mid;++i) a[i]=ans[i]*jc[i]%mod;
  for (rint i=0;i<=mid;++i) b[i]=pw[i]*inv[i]%mod;
  reverse(b,b+mid+1);
  FFT::realmain(a,b,mid,mid);
  for (rint i=0;i<=mid;++i) b[i]=a[i+mid]*inv[i]%mod;
  FFT::realmain(ans,b,mid,mid);
}

int main(){
  cin>>n>>A>>B;
  jc[0]=1; for (int i=1;i<=n;++i) jc[i]=jc[i-1]*i%mod;
  inv[n]=K(jc[n]); for (int i=n;i;--i) inv[i-1]=inv[i]*i%mod;
  if (!A--||!B--||A+B>=n) return puts("0"), 0;
  que(n-1);
  ll res=ans[A+B] *jc[A+B]%mod *inv[A]%mod*inv[B]%mod;
  cout<<res<<endl;
}