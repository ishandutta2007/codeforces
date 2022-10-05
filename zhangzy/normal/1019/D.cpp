#pragma GCC target("arch=corei7-avx")
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, x[2020], y[2020];
ll S, G[2020][2020];

int main(){
  cin>>n>>S; S<<=1;
  for (int i=1;i<=n;++i) cin>>x[i]>>y[i];
  for (int i=1;i<n;++i)
    for (int j=i+1;j<=n;++j)
      G[i][j]= (ll)x[i]*y[j]-(ll)x[j]*y[i];
  for (int i=1;i<n;++i)
    for (int j=i+1;j<n;++j){
      ll aim1=S-G[i][j], aim2=-S-G[i][j];
      for (register int k=j+1;k<=n;++k){
        ll t=-G[i][k]+G[j][k];
        if (t==aim1||t==aim2){
          printf("Yes\n%d %d\n%d %d\n%d %d\n",x[i],y[i],x[j],y[j],x[k],y[k]);
          return 0;
        }
      }
    }
  puts("No");
}