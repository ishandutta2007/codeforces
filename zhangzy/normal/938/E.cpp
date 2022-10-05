#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mod=(1e9)+7, n, a[1001000], mx; ll jc=1, ans;
ll K(ll x,int y=mod-2){ return y? K(x*x%mod,y/2)*(y&1?x:1)%mod: 1; }

int main(){
  cin>>n;
  for (int i=0;i<n;jc=jc*++i%mod) 
    scanf("%d",&a[i]), mx=max(a[i],mx);
  sort(a,a+n);
  for (int i=0;a[i]!=mx;++i){
    int t=lower_bound(a,a+n,a[i])-a;
    ans+= a[i] *jc%mod *K(n-t)%mod; ans%=mod;
  }
  cout<<ans;
}