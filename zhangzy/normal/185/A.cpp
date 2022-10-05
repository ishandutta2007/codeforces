#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
#define ll long long
ll n;

ll K(ll x,ll y){
  ll t=1;
  for (;y;y>>=1,x=x*x%mod)
  if (y&1) t=t*x%mod;
  return t;
}

int main(){
cin>>n; ll x=K(2,n);
cout<<x*(x+1)/2%mod<<endl;
}