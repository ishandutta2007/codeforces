#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;scanf("%d",&n);
  for(int i=1,x;i<=n;++i)scanf("%d",&x);
  printf("%d\n",n*3);
  for(int i=1;i<=n;i+=2)for(int t=0;t<3;++t)printf("1 %d %d\n",i,i+1),printf("2 %d %d\n",i,i+1);
}
int main(){int t;
  for(scanf("%d",&t);t;--t)solve();
  return 0;
}