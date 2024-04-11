//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int n;
int ans;
string s;

int main(){
  cin>>n>>s;
  for (auto c:s)
    ans+=c=='8';
  cout<<min(ans,n/11)<<endl;
}