#include<bits/stdc++.h>
#define rint register int
using namespace std;

int n, tot, now, l, r, f[10100], g[10100];

struct Node{
  int h, type;
}a[10100];
bool cmp(Node a,Node b){
  return a.type==b.type? a.h>b.h: a.type<b.type;
}

inline void U(int &x,int y){
  x=max(x,y);
}
inline int chk(int x){
  return x>=l&&x<=r;
}

int main(){
  cin>>n>>l>>r;
  for (int i=1;i<=n;++i) cin>>a[i].h, tot+=a[i].h;
  for (int i=1;i<=n;++i) cin>>a[i].type;
  sort(a+1,a+n+1,cmp);
  memset(f,-1,sizeof f); f[0]=0;
  for (int i=1;i<=n;++i){
    memset(g,-1,sizeof g);
    for (rint j=0;j<=now;++j)
      if (~f[j]){
        U(g[j+a[i].h],f[j]+(a[i].type&&chk(j)));
        U(g[j],f[j]+(a[i].type&&chk(tot-now+j-a[i].h)));
      }
    now+=a[i].h;
    memcpy(f,g,sizeof g);
  }
  cout<<*max_element(f,f+tot+1);
}