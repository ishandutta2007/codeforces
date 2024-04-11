#pragma GCC target("arch=corei7-avx") 
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
map<ll,set<pii> >mp;
map<pii,int>ans;

pii gao(pii a,pii b=(pii){0,0}){
  int x=a.fi+b.fi, y=a.se+b.se;
  int g=__gcd(abs(x),abs(y));
  return (pii){x/g,y/g};
}

int main(){
  int T, all=0;
  for (cin>>T;T--;){
    int t; pii p;
    scanf("%d%d%d",&t,&p.fi,&p.se);
    ll d=(ll)p.fi*p.fi+(ll)p.se*p.se;
    switch(t){
    case 1: for (auto o:mp[d]) ans[gao(o,p)]+=2; mp[d].insert(p);
      ++all; ++ans[gao(p)]; break;
    case 2: mp[d].erase(p); for (auto o:mp[d]) ans[gao(o,p)]-=2;
      --all; --ans[gao(p)]; break;
    case 3: printf("%d\n",all-ans[gao(p)]);
    }
  }
}