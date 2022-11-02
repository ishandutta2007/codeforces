#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    int base=1;
    vector<int> ans;
    while(n){
      int tmp=n%10*base;
      if(tmp)ans.push_back(tmp);
      n/=10,base*=10;
    }
    cout<<ans.size()<<endl;
    for(auto &it:ans)cout<<it<<" ";cout<<endl;
  }
}