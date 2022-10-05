#include<bits/stdc++.h>
using namespace std;

int n, a[1111], b[1111], c[1111], d[1111];
#define pii pair<int,int>
vector<pii>t1, t2;

void chk(int x,int y){
  t1.clear(); t2.clear();
  for (int i=1;i<=n;++i){
    t1.push_back((pii){c[i],d[i]});
    t2.push_back((pii){x-a[i],y-b[i]});
  }
  sort(t1.begin(),t1.end());
  sort(t2.begin(),t2.end());
  if (t1==t2){
    printf("%d %d\n",x,y);
    exit(0);
  }
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) cin>>a[i]>>b[i];
  for (int i=1;i<=n;++i) cin>>c[i]>>d[i];
  for (int i=1;i<=n;++i){
    chk(a[1]+c[i],b[1]+d[i]);
  }
  
}