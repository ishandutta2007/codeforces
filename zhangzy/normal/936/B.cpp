#include<bits/stdc++.h>
using namespace std;

int n, m, f[101000][2], to[101000][2], deg[101000];
vector<int>nG[101000];

struct ZT{
  int x, xx;
};
queue<ZT>q;

int main(){
  scanf("%d%d",&n,&m);
  int t, x;
  for (int i=1;i<=n;++i){
    scanf("%d",&t); deg[i]=t;
    if (!t){
      f[i][1]=-1; q.push((ZT){i,1});
      f[i][0]=1;  q.push((ZT){i,0});
    }
    for (;t--;) scanf("%d",&x), nG[x].push_back(i);
  }
  
  for (ZT u,v;!q.empty();){
    u=q.front(); q.pop();
    //printf("%d %d %d\n",u.x,u.xx,f[u.x][u.xx]);
    if (f[u.x][u.xx]==1){
      for (auto y:nG[u.x]){
        v=(ZT){y,u.xx^1};
        if (f[v.x][v.xx]) continue;
        f[v.x][v.xx]=1; q.push(v); to[v.x][v.xx]=u.x;
      }
    }else{
      for (auto y:nG[u.x]){
        v=(ZT){y,u.xx^1};
        if (f[v.x][v.xx]) continue;
        if (!--deg[v.x]){
          f[v.x][v.xx]=-1; q.push(v);
        }
      }
    }
  }
  cin>>x;
  if (f[x][1]==-1) return 0*puts("Lose");
  if (!f[x][1]) return 0*puts("Draw");
  puts("Win");
  for (t=1;x;){
    printf("%d ",x);
    x=to[x][t]; t^=1;
  }
}