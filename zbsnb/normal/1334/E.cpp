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

signed main(){
    init();
    ios::sync_with_stdio(0);cin.tie(0);
    ll D;cin>>D;
    vector<ll> f;
    for(ll i=2;i*i<=D;i++){
        if(D%i==0){
            f.push_back(i);
            while(D%i==0) D/=i;
        }
    }
    if(D!=1) f.push_back(D);
    
    // for(auto &it:f) cout<<it<<" ";
    // cout<<endl;
    
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        ll x,y;cin>>x>>y;if(x<y) swap(x,y);
        vector<int> a(f.size(),0);
        vector<int> b(f.size(),0);
        for(int i=0;i<int(f.size());i++){
            while(x%f[i]==0) a[i]++,x/=f[i];
            while(y%f[i]==0) b[i]++,y/=f[i];
        }
        vector<int> v1,v2;
        int s1=0,s2=0;
		for(int i=0;i<int(f.size());i++){
            if(a[i]>b[i])v1.push_back(a[i]-b[i]),s1+=a[i]-b[i];
            if(b[i]>a[i])v2.push_back(b[i]-a[i]),s2+=b[i]-a[i];
        }
        
        // cout<<"s:"<<s1<<" "<<s2<<endl;
        // for(auto &it:v1) cout<<it<<" ";
        // cout<<endl;
        // for(auto &it:v2) cout<<it<<" ";
        // cout<<endl;

        ll ans=fac[s1]*fac[s2]%mod;
        for(auto &it:v1) ans=ans*inv[it]%mod;
        for(auto &it:v2) ans=ans*inv[it]%mod;
        cout<<ans<<endl;
    }
}