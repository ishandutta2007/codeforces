#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> a[2010];
int pos[1000010];
int e[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int tt=0;
    vector<pair<int,int> > vec;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        pos[a]=max(pos[a],b+1);
        tt=max(tt,a);
    }

    for(int i=1000000;i>=0;i--){
        pos[i]=max(pos[i],pos[i+1]);
    }

    for(int i=0;i<=1000000;i++){
        if(pos[i]!=pos[i+1]){
            vec.push_back({i,pos[i]});
        }
    }
    vec.push_back({tt+1,0});

    int ans=1e9;
    for(int i=1;i<=n;i++){
        for(auto &it:vec){
            // cout<<it.first<<" "<<it.second<<endl;
            // cout<<a[i].first<<" "<<a[i].second<<endl;
            if(it.first-a[i].first<0) continue;
            if(it.second-a[i].second<0) continue;
            int now1=max(0,it.first-a[i].first);
            int now2=max(0,it.second-a[i].second);
            e[now1]=max(e[now1],now2);
            // cout<<now1<<" "<<now2<<endl;
        }
        // cout<<endl;
    }
    for(int i=1000001;i>=0;i--){
        e[i]=max(e[i],e[i+1]);
        ans=min(ans,i+e[i]);
        // cout<<i<<" "<<e[i]<<endl;
    }
    cout<<ans<<endl;

}