#include <bits/stdc++.h>
using namespace std;
int s, i, e;
void solve(){
  cin>>s>>i>>e;
  ///i+2j<s+e
  int j=(s+e-i)/2;
  while(i+j+j>=s+e) j--;
  // cerr<<j<<'\n';
  j=max(j, -1);
  j=min(j, e);
  cout<<j+1<<'\n';
}
int main(){
  int t;
  cin>>t;
  while(t--) solve();
}