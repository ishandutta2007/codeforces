#include<iostream>
#include<vector>
using namespace std;
#define ll long long
// #define int long long

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;int m;cin>>n>>m;
        int a[100]={};
        ll cnt=0;
        for(int i=1;i<=m;i++){
            int tmp;cin>>tmp;
            cnt+=tmp;
            for(int i=0;i<=30;i++){
                if((tmp)==(1<<i))a[i]++;
            }
        }
        if(cnt<n){
            cout<<"-1"<<endl;
            continue;
        }
        int ans=0;
        for(int i=0;i<=62;i++){
            if((1ll<<i)&n){
                if(a[i]){
                    a[i]--;
                }
                else{
                    for(int j=i+1;j<=62;j++){
                        if(a[j]){
                            ans+=j-i;
                            // cout<<i<<" "<<j<<endl;
                            a[j]--;
                            for(int k=i;k<j;k++)a[k]++;
                            break;
                        }
                    }
                }
            }
            a[i+1]+=a[i]/2;
        }
        cout<<ans<<endl;
    }
}