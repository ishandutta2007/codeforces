#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct P{
  int x, y;
}p[2020];
P operator - (const P &a,const P &b){
  return (P){a.x-b.x,a.y-b.y};
}

#define pdi pair<double,int>
pdi op[4040];

int n, m, cnt; ll ans;
ll C2(ll x){ return x*(x-1)/2; }

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) cin>>p[i].x>>p[i].y;
  for (int i=1;i<=n;++i){
    m=cnt=0;
    for (int j=1;j<=n;++j)
      if (j!=i){
        P v=p[j]-p[i]; cnt+= v.y? v.y<0: v.x>0;
        op[++m]={atan2(v.y,v.x),-1};
        v=p[i]-p[j];
        op[++m]={atan2(v.y,v.x),1};
      }
    sort(op+1,op+m+1);
    for (int j=1;j<=m;++j){
      if (op[j].second==-1) --cnt, ans+=C2(cnt)*C2(n-2-cnt);
      else ++cnt;
    }
  }
  cout<<ans/2<<endl;
}