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
int n,m;
int a[300010][10];
int num[300010];
pair<int,int> check(int mid){
    int vec[1<<m]={};
    for(int i=1;i<=n;i++){
        num[i]=0;
        for(int j=1;j<=m;j++){
            if(a[i][j]>=mid){
                // if(mid==2)cout<<j<<endl;
                num[i]|=(1<<(j-1));
                // if(mid==2)cout<<(1<<j)<<endl;
            }
        }
        // if(mid==2)cout<<i<<" "<<num[i]<<" "<<endl;
        vec[num[i]]=i;
    }

    // if(mid==2){
    //     cout<<"num:"<<endl;
    //     for(int i=0;i<(1<<m);i++)cout<<vec[i]<<endl;
    // }
    
    for(int i=0;i<(1<<m);i++){
        for(int j=0;j<(1<<m);j++){
            if((i|j)!=(1<<m)-1)continue;
            if(vec[i]&&vec[j]){
                return {vec[i],vec[j]};
            }
        }
    }
    return {0,0};
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int l=0,r=1e9;
    int ans1,ans2;
    while(l<=r){
        int mid=l+r>>1;
        auto tmp=check(mid);
        if(tmp.first){
            // cout<<mid<<endl;
            ans1=tmp.first;
            ans2=tmp.second;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans1<<" "<<ans2<<endl;
}