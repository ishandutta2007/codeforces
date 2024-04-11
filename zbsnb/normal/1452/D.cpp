#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+10;
const ll mod = 998244353;

ll mypow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
ll fac[maxn],inv[maxn];
void init(){
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=mypow(fac[maxn-1],mod-2);
    for(int i=maxn-1;i>=1;i--)inv[i-1]=inv[i]*i%mod;
}
ll C(int n,int m){
    if(n<0||m<0||n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int rest=n-i;
        if(rest%2) continue;
        else{
            int now=rest/2;
            ans=(ans+C(now+i-1,i-1))%mod;
        }
    }
    cout<<ans*mypow(mypow(2,n),mod-2)%mod<<endl;
}