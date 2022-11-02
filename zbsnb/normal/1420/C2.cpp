#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        a[n+1]=0;
        for(int i=1;i<=n;i++){
            if(a[i]>a[i+1]) ans+=a[i]-a[i+1];
        }
        cout<<ans<<endl;
        for(int i=1;i<=q;i++){
            int l,r;cin>>l>>r;
            if(l==r){
                cout<<ans<<endl;
                continue;
            }
            vector<int> pos;
            if(l!=1) pos.push_back(l-1);
            pos.push_back(l);
            if(l+1!=r) pos.push_back(r-1);
            pos.push_back(r);
            for(auto &it:pos){
                if(a[it]>a[it+1]) ans-=a[it]-a[it+1];
            }
            swap(a[l],a[r]);
            for(auto &it:pos){
                if(a[it]>a[it+1]) ans+=a[it]-a[it+1];
            }
            cout<<ans<<endl;
        }
    }
}