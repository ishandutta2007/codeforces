#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> xs;
class query{
public:
  string type;
  int x, y;
  void input(){
    cin>>type>>x>>y;
    xs.push_back(x);
  }
} q[200000];
class segmentTree{
public:
  using pointer=segmentTree*;
  int l, r, m;
  set <int>* s;
  int value;
  pointer left, right;
  segmentTree(int l, int r): l(l), r(r), m((l+r)/2){
    value=-1;
    if(l!=r){
      left=new segmentTree(l, m);
      right=new segmentTree(m+1, r);
    }
    else{
      s=new set<int>();
      s->insert(-1);
    }
  }
  void add(int u, int x){
    if(l==r){
      s->insert(x);
      value=*s->rbegin();
    }
    else{
      if(u<=m) left->add(u, x);
      else right->add(u, x);
      value=max(left->value, right->value);
    }
  }
  void remove(int u, int x){
    if(l==r){
      s->erase(x);
      value=*s->rbegin();
    }
    else{
      if(u<=m) left->remove(u, x);
      else right->remove(u, x);
      value=max(left->value, right->value);
    }
  }
  pair <int ,int> get(int x, int y){
    if(r<=x||value<=y) return {-1, -1};
    if(l==r) return {l, *(s->upper_bound(y))};
    else{
      auto res=left->get(x, y);
      if(res.first!=-1) return res;
      return right->get(x, y);
    }
  }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin>>n;
  for(int i=0; i<n; i++) q[i].input();
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  auto tree=new segmentTree(0, xs.size()-1);
  for(int i=0; i<n; i++){
    if(q[i].type=="add") tree->add(lower_bound(xs.begin(), xs.end(), q[i].x)-xs.begin(), q[i].y);
    else if(q[i].type=="remove") tree->remove(lower_bound(xs.begin(), xs.end(), q[i].x)-xs.begin(), q[i].y);
    else{
      auto res=tree->get(lower_bound(xs.begin(), xs.end(), q[i].x)-xs.begin(), q[i].y);
      if(res.first==-1){
        cout<<"-1\n";
        continue;
      }
      else cout<<xs[res.first]<<' '<<res.second<<'\n';
    }
  }
}