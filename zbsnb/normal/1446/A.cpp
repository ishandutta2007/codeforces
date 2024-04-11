#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> a[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;ll w;cin>>n>>w;
        for(int i=1;i<=n;i++){
            cin>>a[i].first;a[i].second=i;
        }
        sort(a+1,a+n+1,greater<pair<int,int> >());
        vector<int> ans;
        ll now=0;
        for(int i=1;i<=n;i++){
            if(now+a[i].first<=w){
                now+=a[i].first;
                ans.push_back(a[i].second);
            }
            if(now>=(w+1)/2) break;
        }
        if(now>=(w+1)/2){
            cout<<ans.size()<<endl;
            for(auto &it:ans) cout<<it<<" ";
            cout<<endl;
        }
        else{
            cout<<-1<<endl;            
        }
    }
}