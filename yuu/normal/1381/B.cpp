#include <bits/stdc++.h>
using namespace std;
int n;
int p[4001];
bitset <4001> f;
void solve(){
  cin>>n;
  for(int i=1; i<=n*2; i++) cin>>p[i];
  for(int i=1; i<=n*2; i++) f[i]=0;
  f[0]=1;
  for(int i=1; i<=n*2; i++){
    int j=i;
    while((j<n*2)&&(p[j+1]<p[i])) j++;
    f|=f<<(j-i+1);
    i=j;
  }
  if(f[n]) cout<<"YES\n";
  else cout<<"NO\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--) solve();
}