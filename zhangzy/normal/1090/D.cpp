#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<int,int>G[101000];
int n, m, a[101000];

int main(){
  cin>>n>>m;
  int u, v;
  for (;m--;){
    scanf("%d%d",&u,&v);
    G[u][v]=G[v][u]=233;
  }
  for (int i=1;i<=n;++i)
    for (int j=i+1;j<=n;++j)
      if (!G[i].count(j)){
        puts("YES");
        {
          int t=2;
          for (int k=1;k<=n;++k){
            if (k==i){
              a[k]=1; continue;
            }
            if (k==j){
              a[k]=2; continue;
            }
            a[k]=++t;
          }
          for (int k=1;k<=n;++k) printf("%d ",a[k]); puts("");
        }
        {
          int t=2;
          for (int k=1;k<=n;++k){
            if (k==i){
              a[k]=1; continue;
            }
            if (k==j){
              a[k]=1; continue;
            }
            a[k]=++t;
          }
          for (int k=1;k<=n;++k) printf("%d ",a[k]); puts("");
        }
        return 0;
      }
  puts("NO");
}