//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
namespace exgcd{
  ll gao(ll a,ll b,ll &x,ll &y){
    if (b==0){
      x=1; y=0; return a;
    }
    ll k=gao(b,a%b,x,y);
    ll t=x; x=y; y=t-a/b*y;
    return k;
  }
  ll inv(ll a,ll mod){
    ll x, y; ll d=gao(a,mod,x,y);
    return d==1? (x%mod+mod)%mod: -1;
  }
  ll minx(ll a,ll b,ll c){
    ll x, y; ll g=gao(a,b,x,y);
    if (c%g) assert(0);
    a/=g; b/=g; c/=g;
    x*=c; y*=c;
    x%=b; while (x<=0) x+=b;
    return x;
  }
  bool fuck(ll a,ll b,ll c,ll lx,ll ly,ll &x,ll &y){
    ll g=gao(a,b,x,y);
    if (c%g) assert(0);
    a/=g; b/=g; c/=g;
    x*=c; y*=c;
    x=x%b-b-b+lx/b*b;
    while (x+b<=lx) x+=b; if (x<0) return 0;
    y=(c-a*x)/b;
    if (y>=0&&y<=ly) return 1;
    if (y>ly) return 0;
    ll d=(abs(y)+a-1)/a;
    y+=d*a; x-=d*b;
    return x>=0&&x<=lx&&y>=0&&y<=ly;
  }
}

ll n, d, k, x, y, ans=-1;

void doit(ll t){
  if (t<0) return;
  if (t==0){
    if (k>=d&&k<=2*d){
      ans=max(ans,(k-d==d? d: k-d+1)+n-d);
    }
    return;
  }
  ll aim=k-t*n-d;
  if (exgcd::fuck(t,t+1,aim,n-d,d,x,y)){
    //cout<<t<<' '<<x<<' '<<y<<endl;
    ans=max(ans,x+y);
  }
}

void doit2(ll t){
  if (t<=0) return;
  ll aim=k-t*n-d;
  //cout<<t<<' '<<aim<<endl;
  if (exgcd::fuck(t,t+1,aim,n-d,d,x,y)){
    //cout<<' '<<t<<' '<<x<<' '<<y<<endl;
    if (!y) x-=t+1, y+=t;
    if (x>=0&&x<=n-d&&y>=0&&y<=d){
      //cout<<' '<<t<<' '<<x<<' '<<y<<endl;
      ans=max(ans,x+y);
    }
  }
}

int main(){
  cin>>n>>x>>y>>k;
  d= y>=x? y-x+1: y+n-x+1;
  //cout<<d<<endl;
  doit(0);
  for (ll i=n, nex;i<=n*2;i=nex+1){
    ll t=k/i; nex= t==0? 1e18: k/t;
    doit(t-1); doit(t); doit(t+1);
  }
  ++k;
  for (ll i=n, nex;i<=n*2;i=nex+1){
    ll t=k/i; nex= t==0? 1e18: k/t;
    doit2(t-1); doit2(t); doit2(t+1);
  }
  cout<<ans<<endl;
}