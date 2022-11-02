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
int x[100010];
int y[100010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    // int tmp=(1<<30)-1;
    // cout<<tmp<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    x[1]=~a[1];
    for(int i=2;i<=n;i++){
        x[i]=x[i-1]&(~a[i]);
    }
    y[n]=~a[n];
    for(int i=n-1;i>=1;i--){
        y[i]=y[i+1]&(~a[i]);
    }
    int tmp1=a[1]&y[2];
    int tmp2=a[n]&x[n-1];
    int maxn=max(tmp1,tmp2);
    int pos;
    if(tmp1>tmp2)pos=1;
    else pos=n;
    for(int i=2;i<=n-1;i++){
        int tmp=x[i-1]&a[i]&y[i+1];
        if(tmp>maxn){
            maxn=tmp;
            pos=i;
        }
    }
    cout<<a[pos]<<" ";
    for(int i=1;i<=pos-1;i++)cout<<a[i]<<" ";
    for(int i=pos+1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
}