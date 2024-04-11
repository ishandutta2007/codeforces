#include<bits/stdc++.h>
using namespace std;

#define ll long long
int T, mu[99]; ll n, ans;

ll gen(ll n,ll k){
  ll t=powl(n,1./k)-0.5;
  return t+(powl(t+1,k)-0.5<=n);
}

int main(){
  for (int i=2;i<60;++i){
    mu[i]=-1-mu[i];
    for (int j=i+i;j<60;j+=i)
      mu[j]+=mu[i];
  }
  for (cin>>T;T--;){
    cin>>n; ans=n-1;
    for (int i=2;i<60;++i)
      ans+=mu[i]*(gen(n,i)-1);
    cout<<ans<<endl;
  }
}