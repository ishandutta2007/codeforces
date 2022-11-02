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

int x[1000010];
int y[1000010];
pair<int,int> v[1000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    if(n%2){
        cout<<"NO"<<endl;
        return 0;
    }
    v[1]={x[1]-x[n],y[1]-y[n]};
    for(int i=2;i<=n;i++){
        v[i]={x[i]-x[i-1],y[i]-y[i-1]};
    }
    int flg=0;
    for(int i=1;i<=n/2;i++){
        pair<int,int> tmp={-v[i+n/2].first,-v[i+n/2].second};
        if(tmp!=v[i]){
            flg=1;
            break;
        }
    }
    cout<<(flg?"NO":"YES")<<endl;
}