#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
deque <bool> da, db;
vector <int> ans;
void solve(){
  cin>>n>>a>>b;
  da.clear();
  db.clear();
  ans.clear();
  for(char c: a) da.push_back(c=='1');
  for(char c: b) db.push_back(c=='1');
  bool now=0;
  while(db.size()){
    if(now==0){
      if(da.front()==db.back()) ans.push_back(1);
      ans.push_back(da.size());
      da.pop_front();
      db.pop_back();
    }
    else{
      if(da.back()!=db.back()) ans.push_back(1);
      ans.push_back(da.size());
      da.pop_back();
      db.pop_back();
    }
    now=!now;
  }
  // if(now==0){
    // if(da.front()!=db.back()) ans.push_back(1);
  // }
  // else{
    // if(da.back()==db.back()) ans.push_back(1);
  // }
  cout<<ans.size();
  for(int x: ans) cout<<' '<<x;
  cout<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--) solve();
}