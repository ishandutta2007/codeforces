#include <bits/stdc++.h>
using namespace std;
int n, x;
int d[100];
int h[100];
void solve(){
  cin>>n>>x;
  for(int i=0; i<n; i++) cin>>d[i]>>h[i];
  int mxd=*max_element(d, d+n);
  if(mxd>=x){
    cout<<"1\n";
    return;
  }
  int ans=2e9;
  for(int i=0; i<n; i++) if(d[i]>h[i]) ans=min(ans, (x-mxd-1)/(d[i]-h[i])+2);
  if(ans==2e9) ans=-1;
  cout<<ans<<'\n';
}
int main(){
  int t;
  cin>>t;
  while(t--) solve();
}