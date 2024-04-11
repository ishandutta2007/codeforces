#include<bits/stdc++.h>
#define pb push_back
#define N 1005
using namespace std;
vector<int>a[N];
int col[N],vis[N],step[N],ans[N],Q[N];
int Ans,n,m,x,y,i,cnt;
int DFS(int x,int color){
  if (col[x]) return col[x]==color;
  vis[x]=cnt;col[x]=color;
  for (int i=0;i<a[x].size();i++)
    if (!DFS(a[x][i],3-color)) return 0;
  return 1;
}
void BFS(int S){
  int h=0,t=1;Q[1]=S;
  for (int i=1;i<=n;i++) step[i]=-1;step[S]=0;
  while (h<t){
    int x=Q[++h];
    for (int i=0;i<a[x].size();i++)
      if (step[a[x][i]]==-1) 
        step[a[x][i]]=step[x]+1,Q[++t]=a[x][i];
  }ans[vis[S]]=max(ans[vis[S]],step[Q[t]]);
}
int main(){
  scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
    scanf("%d%d",&x,&y),a[x].pb(y),a[y].pb(x);
  for (i=1;i<=n;i++){
    if (vis[i]) continue;++cnt;
    if (!DFS(i,1)) return puts("-1"),0;
  }
  for (i=1;i<=n;i++) BFS(i);
  for (i=1;i<=cnt;i++) Ans+=ans[i];
  printf("%d\n",Ans);
}