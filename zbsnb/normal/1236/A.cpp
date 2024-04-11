#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
#define ll long long 
const ll mod=1e9+7;

ll mypow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

int main(){
    int t;cin>>t;
    while(t--){
        int a,b,c;cin>>a>>b>>c;
        int ans=0;
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                if(a>=i&&b>=2*i+j&&c>=2*j){
                    ans=max(ans,i+j);
                }
            }
        }
        cout<<3*ans<<endl;
    }
}