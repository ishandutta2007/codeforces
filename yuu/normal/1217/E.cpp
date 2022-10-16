#include <bits/stdc++.h>
const int mx=1e9+7;
using namespace std;
int n, m;
int a[200001];
pair <int, int> mix(pair <int, int> A, pair <int, int> B){
  if(A.first>B.first) swap(A, B);
  return {A.first, min(A.second, B.first)};
}
class segment_tree{
public:
  using pointer=segment_tree*;
  int l, r, m;
  pair <int, int> mi[9];
  pointer left, right;
  void fix(){
    int first=a[l];
    int now=first;
    for(int i=0; i<9; i++){
      if(now%10) mi[i]={first, mx};
      else mi[i]={mx, mx};
      now/=10;
    }
  }
  void up(){
    for(int i=0; i<9; i++) mi[i]=mix(left->mi[i], right->mi[i]);
  }
  segment_tree(int l, int r){
    this->l=l;
    this->r=r;
    m=(l+r)/2;
    if(l==r) fix();
    else{
      left=new segment_tree(l, m);
      right=new segment_tree(m+1, r);
      up();
    }
  }
  void update(int u){
    if(l==r) fix();
    else{
      if(m>=u) left->update(u);
      else right->update(u);
      up();
    }
  }
  void get(int u, int v, pair <int, int> *res){
    if(l>v||r<u) return;
    if(u<=l&&v>=r){
      for(int i=0; i<9; i++) res[i]=mix(res[i], mi[i]);
    }
    else{
      left->get(u, v, res);
      right->get(u, v, res);
    }
  }
};
segment_tree::pointer tree;
pair <int, int> res[9];
int get(int l, int r){
  for(int i=0; i<9; i++) res[i].first=res[i].second=mx;
  tree->get(l, r, res);
  // for(int i=0; i<9; i++) cerr<<res[i].first<<' '<<res[i].second<<'\n';
  // cerr<<'\n';
  int ans=mx*2;
  for(int i=0; i<9; i++) if(res[i].second!=mx){
    ans=min(ans, res[i].first+res[i].second);
  }
  if(ans==mx*2) ans=-1;
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=1; i<=n; i++) cin>>a[i];
  tree=new segment_tree(1, n);
  for(int i=1, q, x, y; i<=m; i++){
    cin>>q>>x>>y;
    if(q==1){
      a[x]=y;
      tree->update(x);
    }
    else{
      cout<<get(x, y)<<'\n';
    }
  }
}