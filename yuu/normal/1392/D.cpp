#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int f[200001][2][2];
int dp(){
  //fix the attack pattern of 0
  for(int i=0; i<=n; i++) for(int a=0; a<=1; a++) for(int b=0; b<=1; b++) f[i][a][b]=1e9;
  f[1][s[1]=='L'][s[0]==s[1]]=0;
  for(int i=2; i<n; i++){
    for(int a=0; a<=1; a++){
      f[i][a][0]=min(f[i][a][0], f[i-1][1-a][0]+((s[i]=='L')!=a));
      f[i][a][0]=min(f[i][a][0], f[i-1][1-a][1]+((s[i]=='L')!=a));
      f[i][a][1]=min(f[i][a][1], f[i-1][a][0]+((s[i]=='L')!=a));
    }
  }
  int ans=1e9;
  if(s[0]!=s[1]){
    ans=min(ans, f[n-1][0][0]);
    ans=min(ans, f[n-1][1][0]);
    ans=min(ans, f[n-1][s[0]!='L'][1]);
  }
  else{
    ans=min(ans, f[n-1][s[0]!='L'][0]);
    ans=min(ans, f[n-1][s[0]!='L'][1]);
  }
  return ans;
}
void solve(){
  cin>>n>>s;
  int ans=dp();
  
  s[0]^='L'^'R';
  ans=min(ans, dp()+1);
  s[1]^='L'^'R';
  ans=min(ans, dp()+2);
  s[0]^='L'^'R';
  ans=min(ans, dp()+1);
  cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin>>t;
  while(t--) solve();
  
}