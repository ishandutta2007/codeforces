#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353
#define pii pair<ll,ll>
#define fi first
#define se second

ll n, a[101000], ans, fl3, fl5;
char s[101000];
deque<pii>t3, t5;

void fuck(ll las){
  while (las){
    if (t3.size()){
      ll mn=min(t3.back().se,las);
      t3.back().se-=mn; las-=mn; ans+=mn*4;
      if (t3.back().se==0) t3.pop_back();
      
    }else if (t5.size()){
      ll mn=min(t5.front().se,las);
      t5.front().se-=mn; las-=mn; ans+=mn*6;
      if (t5.front().se==0) t5.pop_front();
      
    }else{
      if (fl3){
	ans+=las*4; return;
      }else if (fl5){
	ans+=las*6; return;
      }
      assert(0);
    }
  }
}

#define piii pair<pii,ll>

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) scanf("%lld",&a[i]), a[i]*=2;
  scanf("%s",s+1);
  for (int i=1;i<=n;++i){
    if (s[i]=='G'){
      t5.push_back((pii){i,a[i]});
      fl5=1;
    }else if (s[i]=='W'){
      t3.push_back((pii){i,a[i]});
      fl3=1;
    }else{
      fuck(a[i]);
    }
  }
  vector<piii>vec;
  for (auto o:t3) vec.push_back((piii){o,3});
  for (auto o:t5) vec.push_back((piii){o,5});
  sort(vec.begin(),vec.end());
  ll now=0;
  for (auto o:vec){
    if (o.se==3){
      now+=o.fi.se;
    }else{
      ll mn=min(now,o.fi.se); now-=mn;
      ans+=mn*4+(o.fi.se-mn)/2*6;
    }
  }
  ans+=now/2*4;
  cout<<ans/2<<endl;
}