#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int a,b;cin>>a>>b;
        int w,h;cin>>w>>h;
        int ans=0;
        for(int i=0;i<=a;i++){
            int cnt1=min(i,n/w),cnt2=min(b,(n-cnt1*w)/h);
            int cnt3=min(a-cnt1,m/w);
            int cnt4=min(b-cnt2,(m-cnt3*w)/h);
            if(w>=h){
                cnt4=min(b-cnt2,m/h);
                cnt3=min(a-cnt1,(m-cnt4*h)/w);
            }
            // cout<<i<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<cnt4<<endl;
            if(cnt1<0||cnt2<0||cnt3<0||cnt4<0) continue;
            ans=max(ans,cnt1+cnt2+cnt3+cnt4);
        }
        cout<<ans<<endl;
    }
}