#include<iostream>
using namespace std;
#define ll long long
int main(){
   int t;cin>>t;
   while(t--){
       ll a,b;cin>>a>>b;
       if(a==1){
           if(b==1)cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
       }
       if(a==2||a==3){
           if(b<=3)cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
       }
       if(a>=4){
           cout<<"YES"<<endl;
       }
   }
}