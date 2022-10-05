#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void U(int &x,int y){ x+=y; if (x>=mod) x-=mod; }

//#define ml 20
int ml;
#define N (1<<20)+10
#define iv2 (mod+1ll)/2
struct D{
  int v[N];
}f,c;
inline void doit(int &x,int &y,int ty){
  static int xx,yy;
  switch (ty){  // 1& 2| 3^ 
  case 1: xx=x, yy=y, U(xx,yy); break;
  case 2: xx=x, yy=y, U(yy,xx); break;
  case 3: xx=yy=x, U(xx,y), U(yy,mod-y); break;
  case -1: xx=x, yy=y, U(xx,mod-yy); break;
  case -2: xx=x, yy=y, U(yy,mod-xx); break;
  case -3: xx=iv2*(x+y)%mod, yy=iv2*(x+mod-y)%mod; break;
  }
  x=xx; y=yy;
}
D tf(D &a,int ty){
  for (int len=1;len<1<<ml;len<<=1)
    for (int i=0;i<1<<ml;++i)
      if (~i&len)
        doit(a.v[i],a.v[i|len],ty);
  return a;
}
D operator * (D a,D b){
  for (int i=0;i<1<<ml;++i)
    a.v[i]=(ll)a.v[i]*b.v[i]%mod;
  return a;
}
void operator *= (D &a,D &b){
  for (int i=0;i<1<<ml;++i)
    a.v[i]=(ll)a.v[i]*b.v[i]%mod;
}
#define fwt(x) tf(a,x);tf(b,x);a*=b;tf(a,-x)
D operator & (D a,D b){
  fwt(1); return a;
}
D operator | (D a,D b){
  fwt(2); return a;
}
D operator ^ (D a,D b){
  fwt(3); return a;
}
void operator ^= (D &a,D &bb){
  static D b; b=bb; fwt(3);
}

int n,m,ans=1e8;
char s[20][101000];

int main(){
  cin>>n>>m; ml=n;
  for (int i=0;i<n;++i) cin>>s[i];
  for (int i=0;i<1<<ml;++i)
    f.v[i]=__builtin_popcount(i), f.v[i]=min(f.v[i],n-f.v[i]);
  for (int i=0;i<m;++i){
    int t=0;
    for (int j=0;j<n;++j) t=t<<1|s[j][i]-'0';
    ++c.v[t];
  }
  f^=c;
  for (int i=0;i<1<<ml;++i) ans=min(ans,f.v[i]);
  cout<<ans<<endl;
}