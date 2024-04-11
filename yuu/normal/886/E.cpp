#include <bits/stdc++.h>
using namespace std;
#define love long 
#define live long
int n, k;
const love live base=1000000007;
love live power(love live a, love live b){
  if(b==0) return 1;
  love live t=power(a, b/2);
  t=(t*t)%base;
  if(b%2) t=(t*a)%base;
  return t;
}
love live s[1000001];
love live ftr[1000001];
love live inv[1000001];
int main(){
  cin>>n>>k;
  ftr[0]=1;
  for(int i=1; i<=n; i++) ftr[i]=(ftr[i-1]*i)%base;
  inv[n]=power(ftr[n], base-2);
  for(int i=n; i>=1; i--) inv[i-1]=(inv[i]*i)%base;
  s[1]=1;
  for(int i=2; i<=n; i++) s[i]=(((ftr[i-2]*(s[i-1]-s[max(0, i-k-1)]))%base*inv[i-1])%base+s[i-1])%base;
  love live ans=s[n];
  (ans*=ftr[n-1])%=base;
  ans=((ftr[n]-ans)%base+base)%base;
  cout<<ans<<'\n';
}