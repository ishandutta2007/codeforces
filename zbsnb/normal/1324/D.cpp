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
// int h[200010],n;
// #define lowb(x) (x&(-x))
// void upd(int x,uint y){
//     for(int i=x;i<=n;i+=lowb(i))h[i]+=y;
// }
// int que(int x){
//     int ret=0;
//     for(int i=x;i>=1;i-=lowb(i))ret+=h[i];
//     return ret;
// }
int a[200010];
int b[200010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        a[i]-=tmp;
    }
    sort(a+1,a+n+1);
    int r=n+1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        while(r-1>i&&a[r-1]+a[i]>0)r--;
        int cnt=min(n-r+1,n-i);
        ans+=cnt;
    }
    cout<<ans<<"\n";
}