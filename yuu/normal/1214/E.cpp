#include <bits/stdc++.h>
using namespace std;
int n;
int d[100001];
vector <int> chain;
vector <pair <int, int>> ans;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  for(int i=1; i<=n; i++) cin>>d[i];
  for(int i=1; i<=n; i++) chain.push_back(i);
  sort(chain.begin(), chain.end(), [](int a, int b){
    return d[a]>d[b];
  });
  for(auto &x: chain) x=x*2-1;
  for(int i=0; i<n; i++){
    if(i) ans.push_back(make_pair(chain[i], chain[i-1]));
    int id=(chain[i]+1)/2;
    if(d[id]+i==chain.size()){
      chain.push_back(id*2);
    }
    ans.push_back(make_pair(chain[d[id]+i-1], id*2)); 
  }
  for(auto p: ans) cout<<p.first<<' '<<p.second<<'\n';
}