#include <bits/stdc++.h>
using namespace std;
int n, d, m;
vector <long long> good, bad;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>d>>m;
  for(int i=1, a; i<=n; i++){
    cin>>a;
    if(a>m) bad.push_back(a);
    else good.push_back(a);
  }
  sort(bad.begin(), bad.end());
  reverse(bad.begin(), bad.end());
  sort(good.begin(), good.end());
  good.push_back(0);
  reverse(good.begin(), good.end());
  for(int i=1; i<good.size(); i++) good[i]+=good[i-1];
  while(good.size()<=n) good.push_back(good.back());
  long long sum=0;
  long long ans=good[n];
  for(int i=1; i<=bad.size(); i++){
    sum+=bad[i-1];
    int req=1+(d+1)*(i-1);
    if(req>n) break;
    ans=max(ans, sum+good[n-req]);
  }
  cout<<ans<<'\n';
}