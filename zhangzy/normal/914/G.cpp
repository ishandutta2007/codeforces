#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
#define N 132000
#define ll long long
#define mod 1000000007
void U(int &x,int y){ x+=y; if (x>=mod) x-=mod; }

#define ml 17
#define iv2 (mod+1ll)/2
struct D{
  int v[N];
}a,c,fb;
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
    for (int i=0;i<1<<ml;i+=len*2){
      int *l=a.v+i, *r=a.v+i+len;
      for (int j=0;j<len;++j)
        doit(l[j],r[j],ty);
    }
  return a;
}
D operator * (D a,D b){
  for (int i=0;i<1<<ml;++i)
    a.v[i]=(ll)a.v[i]*b.v[i]%mod;
  return a;
}
#define fwt(x) tf(a,x),tf(b,x),a=a*b,tf(a,-x)
D operator & (D a,D b){
  fwt(1); return a;
}
D operator | (D a,D b){
  fwt(2); return a;
}
D operator ^ (D a,D b){
  fwt(3); return a;
}
#undef ml

int n,x,ans;

int main(){
  scanf("%d",&n);
  for (int i=n;i--;) scanf("%d",&x), ++c.v[x];
  for (int i=0;i<1<<17;++i)
    for (int j=i;j<1<<17;j=j+1|i)
      U(a.v[j],(ll)c.v[i]*c.v[j^i]%mod);
  fb.v[0]=0, fb.v[1]=1;
  for (int i=2;i<1<<17;++i) fb.v[i]=(fb.v[i-1]+fb.v[i-2])%mod;
  a=(a*fb)&(c*fb)&((c^c)*fb);
  for (int i=1;i<1<<17;i<<=1) U(ans,a.v[i]);
  cout<<ans<<endl;
}