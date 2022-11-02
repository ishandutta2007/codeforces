#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> vec;
        int maxn=0,minn=1e9;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            vec.push_back(tmp);
            maxn=max(maxn,tmp);
            minn=min(minn,tmp);
        }
        if(k==0){
            cout<<maxn-minn<<endl;
        }
        else{
            ll ans=0;
            sort(vec.begin(),vec.end());
            for(int i=n-1;i>=n-k-1;i--){
                ans+=vec[i];
            }
            cout<<ans<<endl;
        }
    }
}