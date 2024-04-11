#include <iostream>
#include <algorithm>
 
typedef long long ll;
 
using namespace std;

const ll INF = ll(4.5e18);
ll add(ll a, ll b)
{
    a+=b;
    if(a>=INF) return INF;
    return a;
}

ll mult(ll a, ll b)
{
    if(b==0) return 0;
    if(a>INF/b) return INF;
    return a*b;
}
int main() {
  int n, k;
  cin >> n >> k;
  ll a[n], b[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }
  ll lo = 0, hi = 1e17, mid, ans=0;
  while(lo <= hi){
    mid = (lo + hi)/2;
    ll cur = 0;
    for(int i = 0; i < n; i++){
      cur = add(cur,max(0LL, ll(mult(a[i],mid) - b[i])));
    }
    if(cur > k){
      hi=mid-1;
    }
    else{
      ans=mid;
      lo=mid+1;
    }
  }
  cout << ans;
}