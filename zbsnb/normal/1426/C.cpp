#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=1e9;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,(n-1)/i+i-1);
        }
        cout<<ans<<endl;
    }
}