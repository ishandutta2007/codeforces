#include<bits/stdc++.h>
using namespace std;
int a[8010];
int sum[8010];
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      sum[i]=a[i]+sum[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
      int l=1,r=0;
      while(1){
        int tmp=sum[r]-sum[l-1];
        if(tmp==a[i]){
          if(!(l==r)){
            ans++;
            // cout<<i<<" "<<l<<" "<<r<<endl;
            break;
          }
          l++;
        }
        else if(tmp<a[i]){
          r++;
          if(r==n+1)break;
        }
        else l++;
      }
    }
    cout<<ans<<endl;
  }
}