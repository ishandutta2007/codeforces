#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>

using namespace std;
#define ll long long
ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
#define int long long
bool pd(int m,int a){
    int cnt=0;
    for(int i=60;i>=0;i--){
        if((1ll<<i)&a)cnt++;
    }
    //cout<<m<<" "<<a<<" "<<cnt<<endl;
    return a>=m&&m>=cnt;
}
signed main(){
    int n,p;cin>>n>>p;
    int ans=-1;
    for(int i=0;i<=60;i++){
        if(pd(i,n-i*p)){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
}