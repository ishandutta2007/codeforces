#include <bits/stdc++.h>
using namespace std;
int n;
vector <string> ans[51];
void solve() {
    cin>>n;
    for(auto&&s: ans[n]) cout<<s<<'\n';
}

int main() {
  for(int i=1; i<=50; i++){
      for(auto&&s: ans[i-1]) ans[i].push_back("("+s+")");
      string n = "";
      for(int j=1; j<=i; j++) n+="()";
      ans[i].push_back(n);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}