#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
    int n,k;cin>>n>>k;
    if(k%2==0&&n%2)cout<<"NO"<<endl;
    else if(k%2==0&&n%2==0||k%2&&n%2){
      if(k>n)cout<<"NO"<<endl;
      else{
        cout<<"YES"<<endl;
        for(int i=1;i<=k-1;i++)cout<<1<<" ";
        cout<<(n-k+1)<<endl;
      }
    }
    else{
       if(2*k>n)cout<<"NO"<<endl;
       else{
        cout<<"YES"<<endl;
        for(int i=1;i<=k-1;i++)cout<<2<<" ";
        cout<<(n-2*k+2)<<endl;
      }
    }
  }
}