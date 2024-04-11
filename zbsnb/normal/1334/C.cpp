#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long
int a[1000010];
int b[1000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
        }
        a[n+1]=a[1],b[n+1]=b[1];
        ll ans=0;int minn=1e18;
        for(int i=1;i<=n;i++){
            int to=min(b[i],a[i+1]);
            // cout<<i<<" "<<to<<endl;
            minn=min(minn,to);
            ans+=a[i+1]-to;
        }
        cout<<minn+ans<<endl;
    }
}