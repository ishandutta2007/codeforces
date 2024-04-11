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

ll n,k;
ll solve(ll x){
    int cnt1,cnt2;
    for(int i=62;i>=0;i--){
        if((1ll<<i)&n){
            cnt1=i;
            break;
        }
    }
    for(int i=62;i>=0;i--){
        if((1ll<<i)&x){
            cnt2=i;
            break;
        }
    }

    ll ret=(x&1?1:2)*((1ll<<(cnt1-cnt2))-1);
    // cout<<x<<" "<<ret<<endl;

    ll add=1;
    for(int i=0;i<cnt1-cnt2;i++){
        add+=(1ll<<i)&n;
    }

    ll now=0;
    for(int i=cnt1-cnt2;i<=cnt1;i++){
        now|=(1ll<<i)&n;
    }

    ll num=1ll<<(cnt1-cnt2);

    // cout<<x<<" "<<add<<" "<<now<<" "<<num<<" "<<ret<<endl;

    if((x&1)==0){
        ll tmp=x|1;
        x<<=(cnt1-cnt2);
        tmp<<=(cnt1-cnt2);

        if(n>=x)ret+=now==x?add:num;
        if(n>=tmp)ret+=now==tmp?add:num;
    }
    else{
        x<<=(cnt1-cnt2);
        if(n>=x)ret+=now==x?add:num;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    ll tmp=n;
    while(tmp){
        for(ll i=tmp+3;i>=tmp-3;i--){
            if(i>n)continue;
            ll tmp1=solve(i);

            // cout<<i<<" "<<tmp1<<endl;
            if(tmp1>=k){
                cout<<i<<endl;
                return 0;
            }
        }
        tmp/=2;
    }
}