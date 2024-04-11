#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int val[N],n,m,s[N],h[N],vis[N];
struct data {
  int p,h,id;
  bool operator < (const data& a) const {
    return p < a.p;
  }
} dat[N];
vector<int> ansl,ansr;
bool check(int hp,int p1,int p2,int sgn) {
  if (!sgn) {
    for (int i = p1 ; i <= p2 ; ++ i) {
      hp += val[i];
      if (hp < 0) return 0;
    }
    return 1;
  } else {
    for (int i = p1 ; i >= p2 ; -- i) {
      hp += val[i];
      if (hp < 0) return 0;
    }
    return 1;
  }
}
void doit(int p) {
  ansl.clear();
  ansr.clear();
  memset(vis,0,sizeof vis);
  int pos = lower_bound(s+1,s+m+1,p) - s;
  for (int i = pos - 1, j = p - 1 ; i >= 1 ; -- i) {
    if (check(h[i],s[i],j,0)) {
      ansl.push_back(i);
      vis[i] = 1;
      j = s[i] - 1;
    } else if (i == 1) return;
  }
  for (int i = pos, j = p - 1 ; i <= m ; ++ i) {
    if (check(h[i],s[i],j+1,1)) {
      ansr.push_back(i);
      vis[i] = 1;
      j = s[i];
    } else if (i == m) return;
  }
  if (pos <= m) {
    printf("%d\n",p);
    for (int i = 0 ; i < (int)ansr.size() ; ++ i)
      printf("%d ",dat[ansr[i]].id);
    for (int i = 0 ; i < (int)ansl.size() ; ++ i)
      printf("%d ",dat[ansl[i]].id);
    for (int i = 1 ; i <= m ; ++ i)
      if (!vis[i]) printf("%d ",dat[i].id);
    puts("");
  } else {
    printf("%d\n",p-1);
    for (int i = 0 ; i < (int)ansl.size() ; ++ i)
      printf("%d ",dat[ansl[i]].id);
    for (int i = 0 ; i < (int)ansr.size() ; ++ i)
      printf("%d ",dat[ansr[i]].id);
    for (int i = 1 ; i <= m ; ++ i)
      if (!vis[i]) printf("%d ",dat[i].id);
    puts("");    
  }
  exit(0);
}
int main() {
  scanf("%d%d",&n,&m);
  for (int i = 1 ; i <= m ; ++ i)
    scanf("%d%d",&dat[i].p,&dat[i].h), dat[i].id = i;
  for (int i = 1 ; i <= n ; ++ i)
    scanf("%d",&val[i]);
  sort(dat+1,dat+m+1);
  for (int i = 1 ; i <= m ; ++ i)
    s[i] = dat[i].p, h[i] = dat[i].h;
  for (int i = 1 ; i <= n + 1 ; ++ i)
    doit(i);
  puts("-1");
  return 0;
}