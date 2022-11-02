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

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.size();
        string cmp("twone");
        string cmp2("two");
        string cmp3("one");
        string cmp4("tw");
        vector<int> ans;
        for(int i=0;i+2<n;i++){
            if(i+4<n&&s.substr(i,5)==cmp){
                ans.push_back(i+2);
            }
            else if(s.substr(i,3)==cmp2){
                ans.push_back(i+1);
            }
            else if((i<2||s.substr(i-2,2)!=cmp4)&&s.substr(i,3)==cmp3){
                ans.push_back(i+1);
            }
        }
        cout<<ans.size()<<endl;
        for(auto &it:ans){
            cout<<it+1<<" ";
        }
        cout<<endl;
    }
}