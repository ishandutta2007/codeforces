#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        ll ans=0;
        ll sum=0;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            if(i!=1){
                if(sum*k<1ll*100*tmp){
                    ll now=(1ll*100*tmp+k-1)/k;
                    ans+=now-sum;
                    sum=now;
                }
            }
            sum+=tmp;
        }
        cout<<ans<<endl;
    }
}