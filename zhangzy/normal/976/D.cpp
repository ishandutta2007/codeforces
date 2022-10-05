#include<bits/stdc++.h>
using namespace std;

int u[505000], v[505000], m, n, d[505];

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) cin>>d[i];
  for (int i=1;i<=n;++i){
    for (int s=d[i];s>d[i-1];--s)
      for (int t=d[n+1-i]+1;t>s;--t)
        tie(u[m],v[m])=tie(s,t), ++m;
  }
  printf("%d\n",m);
  for (int i=0;i<m;++i) printf("%d %d\n",u[i],v[i]);
}