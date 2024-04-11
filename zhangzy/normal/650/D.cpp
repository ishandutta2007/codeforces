#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int read(){
  static int x; static char c;
  x=0; c=getchar();
  for (;!(c>='0'&&c<='9');c=getchar());
  for (; (c>='0'&&c<='9');c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
  return x;
}
 
const int m=808000; int c[m+2];
int n, a[505000], T, ans[505000];
struct OPT{
  int who, val, id;
}opt[505000];
vector<int>ls;
int LS(int &x){
  x=upper_bound(ls.begin(),ls.end(),x)-ls.begin();
}
 
inline void Umx(int &x,int y){
  x=max(x,y);
}
int add(register int x,int v){
  for (;x<=m;x+=x&-x) Umx(c[x],v);
}
int que(register int x){
  int t=0;
  for (;x;x-=x&-x) Umx(t,c[x]);
  return t;
}
 
namespace fxxk1{
  bool cmp(const OPT &a,const OPT &b){
    return a.who<b.who;
  }
  void realmain(){
    sort(opt+1,opt+T+1,cmp);
    memset(c,0,sizeof c);
    int pos=0;
    for (int i=1;i<=T;++i){
      for (;pos+1<opt[i].who;){
    ++pos;
    add(a[pos],que(a[pos]-1)+1);
      }
      ans[opt[i].id]+=que(opt[i].val-1);
    }
  }
}
namespace fxxk2{
  void rev(){
    for (int i=1;i<=n;++i) a[i]=m-a[i];
    for (int i=1;i<=T;++i) opt[i].val=m-opt[i].val;
  }
  void realmain(){
    rev();
    memset(c,0,sizeof c);
    int pos=n+1;
    for (int i=T;i>=1;--i){
      for (;pos-1>opt[i].who;){
    --pos;
    add(a[pos],que(a[pos]-1)+1);
      }
      ans[opt[i].id]+=que(opt[i].val-1)+1;
    }
    rev();
  }
}
namespace fxxk3{
  int mxall, f[505000], must[505000];
  vector<int>pos[505000], now;
  void chk(){
    if (now.size()==1) must[now.back()]=1;
  }
  void gao(vector<int>u,vector<int>&v){
    now.clear();
    for (int fl, mx=-1;u.size()||v.size();){
      if (u.size()==0) fl=2;
      else if (v.size()==0) fl=1;
      else fl= u.back()>v.back()? 1: 2;
      if (fl==1){
    Umx(mx,a[u.back()]);
    u.pop_back();
      }else{
    if (a[v.back()]<mx) now.push_back(v.back());
    v.pop_back();
      }
    }
    reverse(now.begin(),now.end());
  }
   
  void realmain(){
    memset(c,0,sizeof c);
    for (int i=1;i<=n;++i){
      add(a[i],f[i]=(que(a[i]-1)+1));
      pos[f[i]].push_back(i);
    }
    mxall=*max_element(f+1,f+n+1);
    now=pos[mxall]; chk();
    for (int i=mxall-1;i>=1;--i){
      gao(now,pos[i]);
      chk();
    }
    for (int i=1;i<=T;++i)
      Umx(ans[opt[i].id],mxall-must[opt[i].who]);
  }
}
 
namespace brt{
  int f[505000];
  int realmain(int ban){
    memset(c,0,sizeof c);
    memset(f,0,sizeof f);
    for (int i=1;i<=n;++i){
      if (i==ban) continue;
      add(a[i],f[i]=(que(a[i]-1)+1));
    }
    return *max_element(f+1,f+n+1);
  }
}
 
int main(){
 // freopen("kite.in","r",stdin); freopen("kite.out","w",stdout);
  n=read(); T=read();
  for (int i=1;i<=n;++i) scanf("%d",&a[i]), ls.push_back(a[i]);
  for (int i=1;i<=T;++i){
    opt[i].who=read(); scanf("%d",&opt[i].val);
    opt[i].id=i; ls.push_back(opt[i].val);
  }
  sort(ls.begin(),ls.end());
  ls.resize(unique(ls.begin(),ls.end())-ls.begin());
  for (int i=1;i<=n;++i) LS(a[i]);
  for (int i=1;i<=T;++i) LS(opt[i].val);
   
  fxxk1::realmain();
  fxxk2::realmain();
  fxxk3::realmain();
  for (int i=1;i<=T;++i) printf("%d\n",ans[i]);
}