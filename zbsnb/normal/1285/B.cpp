#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
#define up(it,vec) for(auto it=vec.begin();it!=vec.end();it++)
#define dn(it,vec) for(auto it=vec.rbegin();it!=vec.rend();it++)
// #define int long long

ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
int a[100010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll sum=0;
        for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
        ll now=0;
        ll ans=0;

        for(int i=1;i<=n;i++){
            now+=a[i];
            if(now<0)now=0;
            else ans=max(ans,now);
        }
        if(ans>sum)cout<<"NO"<<endl;
        else{
            now=0,ans=0;
            for(int i=2;i<=n;i++){
                now+=a[i];
                if(now<0)now=0;
                else ans=max(ans,now);
            }
            if(ans==sum)cout<<"NO"<<endl;
            else{
                now=0,ans=0;
                for(int i=1;i<n;i++){
                    now+=a[i];
                    if(now<0)now=0;
                    else ans=max(ans,now);
                }
                if(ans==sum)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }    
            
        }
    }
}