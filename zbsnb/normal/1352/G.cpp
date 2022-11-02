#include<bits/stdc++.h>
using namespace std;
int a[8010];
int sum[8010];
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    if(n<=3)cout<<-1<<endl;
    else if(n==4)cout<<"2 4 1 3"<<endl;
    else{
      if(n%2){
        for(int i=1;i<=n;i+=2){
          cout<<i<<" ";
        }
        cout<<n-3<<" "<<n-1<<" ";
        for(int i=n-5;i>=2;i-=2){
          cout<<i<<" ";
        }
        cout<<endl;
      }
      else{
        for(int i=1;i<=n;i+=2){
          cout<<i<<" ";
        }
        cout<<n-4<<" "<<n<<" "<<n-2<<" ";
        for(int i=n-6;i>=2;i-=2){
          cout<<i<<" ";
        }
        cout<<endl;
      }
    }
  }
}