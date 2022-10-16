#include <bits/stdc++.h>
using namespace std;
int n;
string s;
multiset <char> d;
int last[256];
int first[256];
void solve(){
  cin>>n>>s;
  for(int i='0'; i<='9'; i++) last[i]=-1;
  for(int i='0'; i<='9'; i++) first[i]=n;
  for(int i='0'; i<='9'; i++){
    ///number from '0' to i will be colored 1
    string t, color;
    color=s;
    for(auto &x: color) x='2';
    bool bad=0;
    int last=0;
    for(int j=0; j<n; j++) if(s[j]<i){
      t+=s[j];
      color[j]='1';
      last=j;
      if(t.size()>1){
        if(t[t.size()-1]<t[t.size()-2]){
          bad=1;
          break;
        }
      }
    }
    if(bad) continue;
    for(int j=last+1; j<n; j++) if(s[j]==i){
      color[j]='1';
      t+=s[j];
    }
    for(int j=0; j<n; j++) if(color[j]=='2'){
      t+=s[j];
      if(t.size()>1){
        if(t[t.size()-1]<t[t.size()-2]){
          bad=1;
          break;
        }
      }
    }
    if(bad) continue;
    cout<<color<<'\n';
    return;
  }
  cout<<"-\n";
  
}
int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--) solve();
}