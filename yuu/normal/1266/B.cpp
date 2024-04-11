#include <bits/stdc++.h>
using namespace std;
void solve(){
  long long x;
  cin>>x;
  if((x<15)||(x%14==0)||(x%14>6)) cout<<"NO\n";
  else cout<<"YES\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  int t;
  cin>>t;
  while(t--) solve();
}