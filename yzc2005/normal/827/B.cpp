#include <bits/stdc++.h>
using namespace std; 
const int N=2e5+5;
int n,k,len[N],last[N],dep[N];
vector<pair<int,int>>ans;
int main(){
  cin>>n>>k;
  fill(last+1,last+k+1,1);
  for(int i=2;i<=n;){
    for(int j=1;j<=k&&i<=n;++j){
      ans.emplace_back(last[j],i);
      last[j]=i++;
      ++dep[j];
    }
  }
  cout<<dep[1]+dep[2]<<endl;
  for(auto p:ans){
    cout<<p.first<<' '<<p.second<<endl;
  }
}