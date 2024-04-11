#include <bits/stdc++.h>
using namespace std;
int n, d, e;
int main(){
  cin>>n>>d>>e;
  e*=5;
  ///d<e
  int ans=n;
  for(int x=0, y=0; x<10000; x++, y+=e){
    if(y>n) break;
    ans=min(ans, (n-y)%d);
  }
  cout<<ans<<'\n';
}