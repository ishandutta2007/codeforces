#pragma GCC target("arch=corei7-avx")
#include<bits/stdc++.h>
using namespace std;

char ss[1<<20],*A=ss,*B=ss;
inline char gc(){if(A==B){B=(A=ss)+fread(ss,1,1<<20,stdin);}return*A++;}
inline void read(int &x){
  x=0; char c=gc();
  for (;!(c<='9'&&c>='0'); c=gc()) ;
  for (; (c<='9'&&c>='0'); c=gc()) x=(x<<3)+(x<<1)+c-'0';
}

int n, ans[101000], f[101000], dft, a[101000];
vector<int>G[101000];

void pre(int x,int fff){
  a[++dft]=x;
  if (fff){
    vector<int>::iterator it=find(G[x].begin(),G[x].end(),fff);
    G[x].erase(it);
  }
  for (auto y:G[x]) pre(y,x);
}

int gao(int k){
  if (~ans[k]) return ans[k];
  int res=0;
  memset(f,0,sizeof f);
  for (int i=n;i;--i){
    int x=a[i], mx=0, mx2=0;
    for (auto y:G[x]){
      int t=f[y];
      if (t>mx){
        mx2=mx; mx=t;
      }else if (t>mx2){
        mx2=t;
      }
    }
    if (++mx+mx2>=k) ++res, f[x]=0;
    else f[x]=mx;
  }
  return ans[k]=res;
}

void doit(int l,int r){
  if (gao(l)==gao(r)){
    for (int i=l+1;i<r;++i) ans[i]=ans[l];
    return;
  }
  if (l+1>=r) return;
  int mid=l+r>>1;
  doit(l,mid); doit(mid,r);
}

int main(){
  read(n);
  int u, v;
  for (int i=1;i<n;++i){
    read(u); read(v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  pre(1,0);
  memset(ans,-1,sizeof ans); ans[1]=n;
  int s; for (s=2;s<=min(500,n);++s) gao(s);
  doit(s-1,n);
  for (int i=1;i<=n;++i) printf("%d\n",ans[i]);
}