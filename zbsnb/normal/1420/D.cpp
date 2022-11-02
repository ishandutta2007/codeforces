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
    init();
    int n,k;cin>>n>>k;
    vector<pair<int,int> > vec;
    for(int i=1;i<=n;i++){
        int l,r;cin>>l>>r;
        vec.push_back({l,i});
        vec.push_back({r+1,-i});
    }
    sort(vec.begin(),vec.end());
    ll ans=0;
    int cnt=0;
    for(auto &it:vec){
        if(it.second<0) cnt--;
        else{
            cnt++;
            if(cnt>=k) ans+=C(cnt-1,k-1);
        }
    }
    cout<<ans%mod<<endl;
}