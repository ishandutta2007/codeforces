#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=0;
        int now=n;
        while(now){
            if(now/10==0){
                ans+=now%10;
                break;
            }
            ans+=now/10*10;
            now=now/10+now%10;
        }
        cout<<ans<<endl;
    }
}