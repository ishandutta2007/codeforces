#include<bits/stdc++.h>
#define ll long long
#define db long double
using namespace std;

ll lim=1e18;
vector<ll>vec;
int s[1001000], n=1000000;

void pre(){
  vec.push_back(1);
  for (ll i=2;i*i*i<=lim;++i){
    if (i*i<=n) s[i*i]=1;
    for (ll j=i*i*i;j<=lim;j*=i){
      vec.push_back(j);
      if (j>lim/i) break;
    }
  }
  sort(vec.begin(),vec.end());
  vec.resize(unique(vec.begin(),vec.end())-vec.begin());
  for (auto o:vec){
    if (o>n) break;
    s[o]=1;
  }
  for (int i=1;i<=n;++i) s[i]+=s[i-1];
  cerr<<vec.size()<<endl;
}

ll wei(ll x){
  return upper_bound(vec.begin(),vec.end(),x)-vec.begin();
}

ll cal(ll l,ll r){
  if (l>r) return 0;
  if (r<=n) return s[r]-s[l-1];
  ll l2=sqrt((db)l)+10, r2=sqrt((db)r)+10;
  for (;(l2-1)*(l2-1)>=l;) --l2;
  for (;r2*r2>r;) --r2;
  return wei(r)-wei(l-1)+r2-l2+1-cal(l2,r2);
}

int main(){
  pre();
  ll T, l, r;
  for (cin>>T;T--;){
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",cal(l,r));
  }
}