#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k, p;
int cnt=0;
vector<ll>ans;

void doit(ll k,ll p){
  if (++cnt>23335200){
    puts("-1");
    exit(0);
  }
  if (!p) return;
  ll fl=1;
  if (p<0){
    fl=-1;
  }
  ll b=abs(p)/k;
  if (-fl*b*k+p<0) ++b;
  b*=-fl;
  //printf("%lld %lld %lld\n",k,p,b);
  ans.push_back(b*k+p);
  doit(k,b);
}

int main(){
  cin>>p>>k;
  doit(k,p);
  printf("%d\n",(int)ans.size());
  for (auto o:ans) printf("%lld ",o);
}