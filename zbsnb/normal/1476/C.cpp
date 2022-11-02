#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int b[1000010];
int c[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],a[i]--;
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) cin>>c[i];
        ll ans=0;
        ll now=a[n]+2;
        for(int i=n-1;i>=1;i--){
            ll tmp=now+abs(b[i+1]-c[i+1]);
            ans=max(ans,tmp);
            // cout<<i<<" "<<now<<" "<<tmp<<endl;

            if(b[i+1]==c[i+1]) now=a[i]+2;
            else{
                now=max(now+a[i]-abs(b[i+1]-c[i+1])+2,1ll*a[i]+2);
            }
        }
        cout<<ans<<endl;
    }
}