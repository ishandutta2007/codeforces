#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int tmp=(n-m)/(m+1);
        int cnt1=(n-m)%(m+1),val1=tmp+1;
        int cnt2=m+1-cnt1,val2=tmp;
        ll ans=0;
        ans+=1ll*cnt1*(val1)*(val1+1)/2;
        ans+=1ll*cnt2*(val2)*(val2+1)/2;
        ans=1ll*n*(n+1)/2-ans;
        cout<<ans<<"\n";
    }
}