#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vc vector
#define pb push_back
#define st first
#define nd second

#define int long long

int in[300010];
vc<pll> d1,d2;
vc<pair<pii,ll> > ans;

signed main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,w;cin>>a>>b>>w;
        in[b]+=w;
        in[a]-=w;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<in[i]<<endl;
    // }
    for(int i=1;i<=n;i++){
        if(in[i]<0)d1.pb({i,-in[i]});
        if(in[i]>0)d2.pb({i,in[i]});
    }
    int l=0,r=0;
    int lim1=d1.size(),lim2=d2.size();
    while(l<lim1&&r<lim2){
        int tmp=min(d1[l].nd,d2[r].nd);
        ans.pb({{d1[l].st,d2[r].st},tmp});
        d1[l].nd-=tmp;d2[r].nd-=tmp;
        if(d1[l].nd==0)l++;
        if(d2[r].nd==0)r++;
    }
    cout<<ans.size()<<endl;
    for(auto &it:ans){
        cout<<it.st.st<<" "<<it.st.nd<<" "<<it.nd<<endl;
    }
}