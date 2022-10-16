#include <bits/stdc++.h>
using namespace std;
void solve(){
  string s;
  cin>>s;
  if(s.find('0')==-1){
    cout<<"cyan\n";
  }
  else{
    int x=0;
    int good=0;
    for(auto c: s){
      x+=c-'0';
      if(c%2==0) good++;
    }
    if((x%3)||(good==1)){
      cout<<"cyan\n";
    }
    else cout<<"red\n";
  }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  int n;
  cin>>n;
  while(n--) solve();
}