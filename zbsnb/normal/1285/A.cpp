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
char s[100010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L')a++;
        else b++;
    }
    cout<<a+b+1<<endl;
}