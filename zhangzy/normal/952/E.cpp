#include<bits/stdc++.h>
using namespace std;

int n, cnt[2], lim[2];
string s, t="soft";

bool chk(int x){
  lim[0]=x*x/2;
  lim[1]=x*x-lim[0];
  return cnt[0]<=lim[0]&&cnt[1]<=lim[1];
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i){
    cin>>s; cin>>s;
    ++cnt[s==t];
  }
  if (cnt[0]>cnt[1]) swap(cnt[0],cnt[1]);
  for (int i=1;;++i){
    if (chk(i)){
      cout<<i<<endl;
      return 0;
    }
  }
}