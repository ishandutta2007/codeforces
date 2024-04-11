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
// #define lld long double
vector<pair<ll,ll> > vec;

ll dis[100];
#define S(x,y) ((x)*(x)+(y)*(y))
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll x0,y0,a1,a2,b1,b2;
    ll sx,sy,t;
    cin>>x0>>y0>>a1>>a2>>b1>>b2>>sx>>sy>>t;

    while(x0<=(2e16+10)&&y0<=(2e16+10)){
        vec.push_back({x0,y0});
        x0=x0*a1+b1;
        y0=y0*a2+b2;
    }

    int sz=vec.size();
    for(int i=1;i<sz;i++){
        // cout<<vec[i].first<<" "<<vec[i].second<<endl;
        dis[i]=dis[i-1]+abs(vec[i].first-vec[i-1].first)+abs(vec[i].second-vec[i-1].second);
    }

    // for(int i=1;i<=10;i++){
    //     cout<<dis[i]<<endl;
    // }

    int ans=0;
    for(int i=0;i<sz;i++){
        ll tmp=abs(vec[i].first-sx)+abs(vec[i].second-sy);
        for(int j=0;j<sz;j++){
            if(t>=tmp+abs(dis[i]-dis[j])){
                ans=max(ans,abs(i-j)+1);
            }
        }
    }
    cout<<ans<<endl;
}