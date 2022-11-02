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
    int t;cin >> t;
    while(t--){
        int n,x;cin>>n>>x;
        cin>>s;

        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=s[i]=='0'?1:-1;
        }

        if(cnt==0){
            int now=0;
            for(int i=0;i<n;i++){
                if(now==x){
                    cout<<"-1"<<endl;
                    now=-1;
                    break;
                }
                now+=s[i]=='0'?1:-1;
            }
            if(now!=-1){
                cout<<"0"<<endl;
            }
            continue;
        }

        int now=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(((x-now)<=0&&cnt<0 || (x-now)>=0&&cnt>0) &&(now-x)%cnt==0){
                ans++;
            }
            now+=s[i]=='0'?1:-1;
        }
        cout<<ans<<endl;

    }
}