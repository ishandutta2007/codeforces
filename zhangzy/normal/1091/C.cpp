#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n;
set<ll>ans;

void gao(ll x,ll n){
  ll t=n/x;
  ll res=t+t*(t-1)/2*x;
  ans.insert(res);
}

int main(){
  cin>>n;
  for (int i=1;i*i<=n;++i)
    if (n%i==0) gao(i,n), gao(n/i,n);
  for (auto o:ans) printf("%lld ",o); puts("");
}