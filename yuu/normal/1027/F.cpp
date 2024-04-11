#include <bits/stdc++.h>
using namespace std;
int n;
pair <int, int> p[1000001];
vector <int> v;
pair <int, int> r[2000001];
int root(int u){
  if(r[u].first<0) return u;
  return r[u].first=root(r[u].first);
}
void unite(int u, int v){
  u=root(u);
  v=root(v);
  r[u].second++;
  if(u==v) return;
  if(r[u].first>r[v].first) swap(u, v);
  r[u].first+=r[v].first;
  r[u].second+=r[v].second;
  r[v].first=u;
}
bool check(int lim){
  for(int i=0; i<=lim; i++) r[i].first=-1, r[i].second=0;
  for(int i=1; i<=n; i++){
    if(p[i].first>lim) return 0;
    if(p[i].second>lim) unite(p[i].first, p[i].first);
    else unite(p[i].first, p[i].second);
  }
  for(int i=0; i<=lim; i++) if(i==root(i)) if(r[i].second>-r[i].first) return 0;
  return 1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>p[i].first>>p[i].second;
    v.push_back(p[i].first);
    v.push_back(p[i].second);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i=1; i<=n; i++){
    p[i].first=lower_bound(v.begin(), v.end(), p[i].first)-v.begin();
    p[i].second=lower_bound(v.begin(), v.end(), p[i].second)-v.begin();
  }
  int low=0, high=v.size()-1, mid, res=v.size();
  while(low<=high){
    mid=(low+high)/2;
    if(check(mid)){
      res=mid;
      high=mid-1;
    }
    else low=mid+1;
  }
  if(res==v.size()) res=-1;
  else res=v[res];
  cout<<res<<'\n';
  
}