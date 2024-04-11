#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;

int cal(ll l,ll r){
  printf("%lld %lld\n",l,r);
  fflush(stdout);
  string s; cin>>s;
  return s[0]=='Y';
}

int main(){
  srand(time(0));
  cin>>n>>k;
  ll l=1, r=n;
  for (;;){
    l=max(l-k,1ll); r=min(r+k,n);
    if (r-l<=100){
      ll w=rand()%(r-l+1)+l;
      if (cal(w,w)) return 0;
    }else{
      ll mid=l+r>>1;
      if (cal(l,mid)) r=mid;
      else l=mid+1;
    }
  }
}