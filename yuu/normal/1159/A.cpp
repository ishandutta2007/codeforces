#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  int n;
  cin>>n;
  string s;
  cin>>s;
  int val=0;
  for(auto &c: s){
    if(c=='+') val++;
    else val--;
    if(val<0) val=0;
  }
  cout<<val<<'\n';
}