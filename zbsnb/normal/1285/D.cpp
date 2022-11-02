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
int n;
int a[100010];
pair<int,int> dfs(int now,int l,int r){
    if(l>r)return {0,0};
    if(now==-1)return {0,0};
    int pos=r+1;
    for(int i=l;i<=r;i++){
        if(a[i]&(1<<now)){
            pos=i;
            break;
        }
    }
    if(pos==r+1){
        return dfs(now-1,l,r);
    }
    else if(pos==l){
        auto tmp=dfs(now-1,l,r);
        return {tmp.first,(1<<now)|tmp.second};
    }
    // cout<<l<<" "<<r<<" "<<pos<<endl;
    auto tmp1=dfs(now-1,l,pos-1);
    auto tmp2=dfs(now-1,pos,r);
    // cout<<tmp1.first<<" "<<tmp1.second<<" "<<tmp2.first<<" "<<tmp2.second<<endl;
    if(tmp1.first>tmp2.first){
        return{(1<<now)|tmp2.first,tmp2.second};
    }
    else{
        return{(1<<now)|tmp1.first,tmp1.second};
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    auto ans=dfs(30,1,n);
    // cout<<ans.first<<" "<<ans.second<<endl;
    cout<<ans.first<<endl;
}