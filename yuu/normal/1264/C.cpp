#include <bits/stdc++.h>
using namespace std;
int n, q;
using ll=long long;
const ll base=998244353;
ll power(ll x, ll y){
  if(y==0) return 1;
  ll t=power(x, y/2);
  (t*=t)%=base;
  if(y%2) (t*=x)%=base;
  return t;
}
const ll inv=power(100, base-2);
ll p[200001];
class matrix{
public:
  ll f[3][3];
  matrix operator *(matrix x){
    matrix res;
    for(int i=0; i<3; i++) for(int j=0; j<3; j++){
      res.f[i][j]=0;
      for(int k=0; k<3; k++) res.f[i][j]+=f[i][k]*x.f[k][j];
      res.f[i][j]%=base;
    }
    return res;
  }
  void set(ll p){
    f[0][0]=f[1][1]=p;
    f[0][1]=f[0][2]=f[1][0]=f[1][2]=0;
    f[2][0]=(base+1-p)%base;
    f[2][1]=f[2][2]=1;
  }
  void make_unit(){
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) f[i][j]=i==j;
  }
  void make_spec(){
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) f[i][j]=0;
    f[0][2]=1;
  }
  ll extract(){
    return (f[0][1]*power(base+1-f[0][0], base-2))%base;
  }
};
matrix unit;
matrix spec;
class segment_tree{
public:
  using pointer=segment_tree*;
  matrix a;
  int l, r, m;
  pointer left, right;
  segment_tree(int l, int r): l(l), r(r){
    m=(l+r)/2;
    if(l!=r){
      left=new segment_tree(l, m);
      right=new segment_tree(m+1, r);
      a=right->a*left->a;
    }
    else{
      left=right=nullptr;
      a.set(p[l]);
    }
  }
  matrix get(int u, int v){
    if(l>v||r<u) return unit;
    if(u<=l&&v>=r) return a;
    if(m<u) return right->get(u, v);
    if(m>=v) return left->get(u, v);
    return right->get(u, v)*left->get(u, v);
  }
};
segment_tree::pointer tree;
set <int> key;
ll ans=0;
matrix get_mat(int l, int r){
  return spec*tree->get(l, r);
}
map <pair <int, int>, ll> M;
ll get(int l, int r){
  auto it=M.find(make_pair(l, r));
  if(it!=M.end()) return it->second;
  return M[make_pair(l, r)]=get_mat(l, r).extract();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  unit.make_unit();
  spec.make_spec();
  cin>>n>>q;
  for(int i=1; i<=n; i++) cin>>p[i];
  for(int i=1; i<=n; i++) (p[i]*=inv)%=base;
  
  // cerr<<(inv*100)%base<<'\n';
  tree=new segment_tree(1, n);
  key.insert(1);
  key.insert(n+1);
  
  ans=get(1, n);
  // cout<<ans<<'\n';
  for(int i=1, x; i<=q; i++){
    cin>>x;
    auto it=key.find(x);
    if(it==key.end()){
      auto phigh=key.upper_bound(x);
      auto plow=phigh;
      plow--;
      int low=*plow;
      int high=*phigh;
      ans-=get(low, high-1);
      ans+=get(low, x-1);
      ans+=get(x, high-1);
      key.insert(x);
    }
    else{
      auto phigh=it;
      auto plow=it;
      plow--;
      phigh++;
      int low=*plow;
      int high=*phigh;
      ans+=get(low, high-1);
      ans-=get(low, x-1);
      ans-=get(x, high-1);
      key.erase(it);
    }
    ans%=base;
    if(ans<0) ans+=base;
    cout<<ans<<'\n';
  }
}