#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int f[200001];
void solve(){
  cin>>s;
  s='a'+s;
  f[0]=0;
  int ans=0;
  for(int i=1; i<s.size(); i++) f[i]=(s[i]=='0')?(f[i-1]+1):0;
  for(int r=1; r<s.size(); r++) for(int l=r; l>=max(r-20, 1); l--) if(s[l]=='1'){
    int res=0;
    for(int k=r; k>=l; k--) if(s[k]=='1') res^=1<<(r-k);
    // cerr<<r<<' '<<l<<' '<<res<<'\n';
    if(res>r) break;
    // if(res<r-l+1) continue;///can't happend?
    if(f[l-1]>=res-(r-l+1)) ans++;
  }    
  cout<<ans<<'\n';
}
int main(){
  cin>>t;
  while(t--) solve();
}