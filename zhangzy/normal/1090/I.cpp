#include<bits/stdc++.h>
using namespace std;

typedef long long li;
#define ll li
const int maxn = 1e7+233;
int n, a[maxn], b[maxn];

const li infl = ~0LLU >> 1;

void Read(void) {
  int l, r;
  unsigned x, y, z, b1, b2;
  static unsigned b[maxn];
  scanf("%d%d%d%u%u%u%u%u", &n, &l, &r, &x, &y, &z, &b1, &b2);
  //sscanf("2000 -2000000000 -1000000000 11 13 17 230 3", "%d%d%d%u%u%u%u%u", &n, &l, &r, &x, &y, &z, &b1, &b2);
  b[0] = b1;
  b[1] = b2;
  for (int i = 2; i < n; ++i) {
    b[i] = (b[i - 2] * x + b[i - 1] * y + z);
  }
  for (int i = 0; i < n; ++i) {
    a[i] = (li)b[i] % ((li)r - l + 1) + l;
  }
}

void Main(void) {
  li ans = infl;

  int max_pos = -1;
  for (int i = n - 1; i >= 0; --i) {
    if (max_pos > 0 && a[i] < 0) {
      ans = min(ans, (li)a[i] * max_pos);
    }
    max_pos = max(max_pos, a[i]);
  }
  if (ans<0){
    printf("%lld\n",ans);
    return;
  }
  
  // --------------------
  static int c[maxn], m, vec[maxn], tot;
  {
    m=0; tot=0;
    for (int i=0;i<n;++i)
      if (a[i]>=0)
        c[++m]=a[i];
    int mn=2e9+233;
    for (int i=1;i<=m;++i)
      if (c[i]<mn){
        mn=c[i]; vec[++tot]=i;
      }
    reverse(vec+1,vec+tot+1);
    int las=m;
    for (int z=1;z<=tot;++z){
      int p=vec[z];
      if ((ll)c[p]*(c[p]+1)>=ans) continue;
      int t=2e9+2333, org=t;
      for (register int i=p+1;i<=las;++i)
        if (c[i]>c[p])
          t=min(t,c[i]);
      if (t!=org) ans=min(ans,(ll)c[p]*t);
      las=p;
    }
  }
  {
    m=0; tot=0;
    for (int i=0;i<n;++i)
      if (a[i]<=0)
        c[++m]=a[i];
    int mx=-2e9-233;
    for (int i=m;i>=1;--i)
      if (c[i]>mx){
        mx=c[i]; vec[++tot]=i;
      }
    reverse(vec+1,vec+tot+1);
    int las=1;
    for (int z=1;z<=tot;++z){
      int p=vec[z];
      if ((ll)c[p]*(c[p]-1)>=ans) continue;
      int t=-2e9-2333, org=t;
      for (register int i=p-1;i>=las;--i)
        if (c[i]<c[p])
          t=max(t,c[i]);
      if (t!=org) ans=min(ans,(ll)c[p]*t);
      las=p;
    }
  }
  if (ans==infl) puts("IMPOSSIBLE");
  else printf("%lld\n",ans);
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    Read();
    Main();
  }
  return 0;
}