#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1000010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int ans=1e9;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i<=k)ans=min(ans,n/i);
                if(n/i<=k)ans=min(ans,i);
            }
        }
        cout<<ans<<endl;
    }
}