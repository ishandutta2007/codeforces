#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            mp[k-1-(tmp-1)%k]++;
        }
        ll ans=0;
        for(auto &it:mp){
            // cout<<"??:"<<it.first<<" "<<it.second<<endl;
            if(it.first!=0){
                ans=max(ans,1ll*(it.second-1)*k+it.first+1);
            }
        }
        cout<<ans<<endl;
    }
}