#include <bits/stdc++.h>
using namespace std;
const long long base=998244353;
long long power(long long x, long long y){
  if(y==0) return 1;
  long long t=power(x, y/2);
  t=(t*t)%base;
  if(y%2) t=(t*x)%base;
  return t;
}
long long inverse(long long x){//modular inverse
  return power(x, base-2);
}
vector <long long> f({1}), iv({1});

long long C(long long n, long long k){
    return ((f[n]*iv[k]%base)*iv[n-k])%base;
}
long long star(long long n, long long k){
    return C(n+k-1, k-1);
}
long long countGame(long long n, long long k, long long x){//n points total, k players, no player can have x point or more
  if(k==0) return (n==0);
  long long ans=0;
  for(int i=0; i<=k; i++){
    long long t=n-x*i;
    if(t<0) break;
    if(i%2) ans=(ans-C(k, i)*star(t, k))%base;
    else ans=(ans+C(k, i)*star(t, k))%base;
  }
  return ans;
}
int main(){
  for(int i=1; i<5555; i++){
    f.push_back((f[i-1]*i)%base);
    iv.push_back(inverse(f[i]));
  }
  int p, s, r;
  cin>>p>>s>>r;
  long long gameSize=countGame(s-r, p, 1e18);
  gameSize=inverse(gameSize);
  long long ans=0;
  for (int q=r; q<=s; q++){
    for(int i=0; i<p; i++){//exactly i people have the same score
        long long t=s-(i+1)*q;
        if(t<0) break;
        ans=(ans+(((C(p-1, i)*countGame(t, p-i-1, q))%base)*gameSize%base)*inverse(i+1))%base;
    }
  }
  cout<<ans<<'\n';
}