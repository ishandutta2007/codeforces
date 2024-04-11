#include <bits/stdc++.h>
using namespace std;
int r, c, n;
bool f[3001][6001];
int rt[3000*6000+1];
int root(int u){
  while(rt[u]>0) u=rt[u];
  return u;
}
vector <pair <int, int>> rb;
void unite(int u, int v){
  u=root(u);
  v=root(v);
  if(u==v) return;
  if(rt[u]>rt[v]) swap(u, v);
  rb.push_back({u, rt[u]});
  rb.push_back({v, rt[v]});
  rt[u]+=rt[v];
  rt[v]=u;
}
void rollBack(){
  while(!rb.empty()){
    rt[rb.back().first]=rb.back().second;
    rb.pop_back();
  }
}
int id(int x, int y){
  return (x-1)*c*2+y;
}
const int cx[]={-1, -1, -1, 0, 0, 1, 1, 1};
const int cy[]={-1, 0, 1, -1, 1, -1, 0, 1};
void turnOn(int x, int y){
  f[x][y]=1;
  int i=id(x, y);
  for(int k=0; k<8; k++){
    int xx=x+cx[k];
    int yy=y+cy[k];
    if(xx<1||xx>r) continue;
    if(yy==0) yy=c*2;
    else if(yy>c*2) yy=1;
    if(f[xx][yy]) unite(id(xx, yy), i);
  }
}
void turnOff(int x, int y){
  f[x][y]=0;
}
bool sameComponent(int x, int y, int u, int v){
  return root(id(x, y))==root(id(u, v));
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>r>>c>>n;
  for(int i=r*c*2; i>=1; i--) rt[i]=-1;
  int ans=0;
  for(int i=1, x, y; i<=n; i++){
    cin>>x>>y;
    turnOn(x, y);
    turnOn(x, y+c);
    if(sameComponent(x, y, x, y+c)){
      turnOff(x, y);
      turnOff(x, y+c);
      rollBack();
    }
    else{
      ans++;
      rb.clear();
    }
  }
  cout<<ans;
}