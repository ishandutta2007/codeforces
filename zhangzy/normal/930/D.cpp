#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
ll ans;
const int m=202000, M=405000;

int cal(int l,int r){
  if (l>=r) return 0;
  return r/2-l/2;
}

int d0[M+3], d1[M+3], u0[M+3], u1[M+3];
void doit(vector<pii>&a){
  memset(d1,0,sizeof d1); memset(d0,33,sizeof d0);
  for (auto &o:a){
    d1[o.se]=max(d1[o.se],o.fi);
    d0[o.se]=min(d0[o.se],o.fi);
  }
  memcpy(u1,d1,sizeof u1); memcpy(u0,d0,sizeof u0);
  
  for (int i=1;i<=M;++i){
    u1[i]=max(u1[i],u1[i-1]);
    u0[i]=min(u0[i],u0[i-1]);
  }
  for (int i=M;i;--i){
    d1[i]=max(d1[i],d1[i+1]);
    d0[i]=min(d0[i],d0[i+1]);
  }
  
  for (int i=1;i<=M;++i)
    if (i&1) ans+=cal(max(d0[i],u0[i]),min(d1[i],u1[i]));
}

vector<pii>vec[2];

int main(){
  int n,x,y,fl; 
  for (cin>>n;n--;){
    scanf("%d%d",&x,&y);
    if (fl=x+y&1) --x;
    vec[fl].push_back((pii){x-y+m,x+y+m});
  }
  doit(vec[0]); doit(vec[1]);
  cout<<ans<<endl;
}