#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    long long ans=0;
    for(int i=n; i>=2; i--) ans+=max(0, a[i-1]-a[i]);
    cout<<ans<<'\n';
  }
}