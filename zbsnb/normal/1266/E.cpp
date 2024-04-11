#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vc vector
#define pb push_back
#define st first
#define nd second

// #define int long longs
int s[1000010];
int t[1000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        ans+=s[i];
    }

    map<pii,int> mp;
    int m;cin>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        int tmp=mp[{a,b}];
        if(tmp){
            if(t[tmp]<=s[tmp])ans++;
            t[tmp]--;
            mp.erase({a,b});
        }
        t[c]++;
        mp[{a,b}]=c;
        if(t[c]<=s[c])ans--;
        cout<<ans<<"\n";
    }
}