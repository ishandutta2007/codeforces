#include<bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main(){
  cin>>s; n=s.length();
  int t=0, fl=1;
  for (int i=0;i<n;++i){
    if (!isdigit(s[i])){
      ans+=fl*t;
      t=0;
      fl=s[i]=='+'? 1: -1;
    }
    t=t*10+s[i]-'0';
  }
  ans+=fl*t;
  cout<<ans;
}