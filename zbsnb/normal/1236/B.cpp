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
    int n,m;cin>>n>>m;
    cout<<mypow(mypow(2,m)-1,n)<<endl;
}