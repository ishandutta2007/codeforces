#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[200001];
int first[200001];
int last[200001];
int cnt[200001];
int f[200001];
vector <int> now;
int solve(){
  int res=0;
  for(auto a: now) res=max(res, cnt[a]);
  res=now.size()-res;
  now.clear();
  return res;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin>>n>>q;
  for(int i=1; i<=n; i++) cin>>a[i];
  for(int i=1; i<=n; i++) cnt[a[i]]++;
  for(int i=1; i<=n; i++) last[a[i]]=i;
  for(int i=n; i>=1; i--) first[a[i]]=i;
  for(int i=1; i<=200000; i++) f[first[i]]++;
  for(int i=1; i<=200000; i++) f[last[i]]--;
  int ans=0;
  for(int i=1; i<=n; i++){
    f[i]+=f[i-1];
    now.push_back(a[i]);
    if(f[i]==0) ans+=solve();
  }
  cout<<ans<<'\n';
}