#include <bits/stdc++.h>
using namespace std;
int n;
using ll=long long;
ll a[26][26];
int main(){
  cin>>n;
  ll mx=0;
  for(int i=3; i<=n+n-1; i++){
    for(int x=1, y; x<=n; x++){
      y=i-x;
      if(y<1||y>n) continue;
      if(x%2) a[x][y]=1LL<<(i-3);
      else a[x][y]=0;
      mx=max(mx, a[x][y]);
    }
  }
  // cerr<<mx<<'\n';
  for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cout<<a[i][j]<<" \n"[j==n];
  cout.flush();
  int q;
  cin>>q;
  while(q--){
    ll k;
    cin>>k;
    int x=1, y=1;
    cout<<x<<' '<<y<<'\n';
    while((x!=n)&&(y!=n)){
      int i=x+y+1;
      if(k&(1LL<<(i-3))){//x should become odd
        if(x%2==0) x++;
        else y++;
      }
      else{//x should become even
        if(x%2) x++;
        else y++;
      }
      cout<<x<<' '<<y<<'\n';
    }
    while(x<n){
      x++;
      cout<<x<<' '<<y<<'\n';
    }
    while(y<n){
      y++;
      cout<<x<<' '<<y<<'\n';
    }
    cout.flush();
  }
}