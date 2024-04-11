#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

ll n, T, x;

ll cal(ll x,ll n){
  if (x&1) return x+1>>1;
  return cal(n-x/2,n-x/2)+x/2;
}

int main(){
  cin>>n>>T;
  for (;T--;){
    scanf("%lld",&x);
    printf("%lld\n",cal(x,n));
  }
}