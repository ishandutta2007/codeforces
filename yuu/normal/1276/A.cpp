#include <bits/stdc++.h>
using namespace std;
#define next Rin
string s;
int f[150001][6];
int trace[150001][6];
int next[6][256];
int n;
void solve(){
  cin>>s;
  n=s.size();
  s='0'+s;
  for(int i=1; i<=n; i++) for(int j=0; j<6; j++) f[i][j]=1e9;
  for(int i=0; i<n; i++) for(int j=0; j<5; j++){
    if(f[i+1][next[j][s[i+1]]]>f[i][j]){
      f[i+1][next[j][s[i+1]]]=f[i][j];
      trace[i+1][next[j][s[i+1]]]=j;
    }
    if(f[i+1][j]>f[i][j]+1){
      f[i+1][j]=f[i][j]+1;
      trace[i+1][j]=j;
    }
  }
  int best=0;
  for(int j=1; j<5; j++) if(f[n][j]<f[n][best]) best=j;
  vector <int> ans;
  while(n>0){
    if(f[n][best]>f[n-1][trace[n][best]]) ans.push_back(n);
    best=trace[n][best];
    n--;
  }
  cout<<ans.size()<<'\n';
  for(auto &x: ans) cout<<x<<' ';
  cout<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  for(int i=0; i<5; i++) next[i]['o']=1;
  for(int i=0; i<5; i++) next[i]['t']=3;
  next[1]['n']=2;
  next[2]['e']=5;
  next[3]['w']=4;
  next[4]['o']=5;
  int t;
  cin>>t;
  while(t--) solve();
}