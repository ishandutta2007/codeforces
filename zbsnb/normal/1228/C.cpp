#include<iostream>
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

int p[20],cnt;
int main(){
    int x;ll n;cin>>x>>n;
    for(int i=2;i<=100010;i++){
        if(x<i)break;
        if(x%i==0){
            p[cnt++]=i;
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)p[cnt++]=x;
    //for(int i=0;i<cnt;i++)cout<<p[i]<<" ";cout<<endl;

    ll ans=1;
    for(int i=0;i<cnt;i++){
        ll now=1;
        while((long double)now*p[i]<=n){
            now*=p[i];
            ans*=mypow(p[i],n/now);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}