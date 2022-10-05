//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n, ans;

ll gao(ll x){
  ll res=0;
  for (;x;x/=10) res+=x%10;
  return res;
}

int main(){
  cin>>n;
  ll bas=1;
  for (;bas-1<=n;bas*=10){
    ans=max(ans,gao(bas-1)+gao(n-bas+1));
  }
  cout<<ans<<endl;
}