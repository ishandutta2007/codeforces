#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=0,r=n+1;
    int cnt=0,ans1=0,ans2=0,now1=0,now2=0,flg=0;
    while(l+1<r){
      ++cnt;
      if(flg=1-flg){now1=0;while(now1<=now2&&l+1<r)now1+=a[++l],ans1+=a[l];}
      else {now2=0;while(now2<=now1&&l+1<r)now2+=a[--r],ans2+=a[r];}
      // cout<<l<<" "<<r<<" "<<now1<<" "<<now2<<endl;
    }
    cout<<cnt<<" "<<ans1<<" "<<ans2<<endl;
  }
}