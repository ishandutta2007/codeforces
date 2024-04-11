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
int x[100010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;cin>>n>>q;
    int cnt=0;
    int cnt2=0;
    for(int i=1;i<=q;i++){
        int a,b;cin>>a>>b;
        if(x[b]==3)cnt--;
        if(a==1){
            if(x[b]&1){
                if(x[b-1]&2)cnt2--;
                if(x[b+1]&2)cnt2--;
            }
            x[b]^=1;
            if(x[b]&1){
                if(x[b-1]&2)cnt2++;
                if(x[b+1]&2)cnt2++;
            }
        }
        else{
            if(x[b]&2){
                if(x[b-1]&1)cnt2--;
                if(x[b+1]&1)cnt2--;
            }
            x[b]^=2;
            if(x[b]&2){
                if(x[b-1]&1)cnt2++;
                if(x[b+1]&1)cnt2++;
            }
        }
        if(x[b]==3)cnt++;
        if(cnt==0&&cnt2==0){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}