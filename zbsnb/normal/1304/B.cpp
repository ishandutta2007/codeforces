#include<iostream>
#include<vector>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int n,m;cin>>n>>m;
    string s[110];
    int vis[110]={};
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    vector<pair<int,int> > ans;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        for(int j=i+1;j<=n;j++){

            int flg=0;
            for(int k=0;k<m;k++){
                if(s[i][k]!=s[j][m-1-k]){
                    flg=1;
                    break;
                }
            }
            if(flg==0){
                ans.push_back({i,j});
                vis[i]=1;
                vis[j]=1;
            }
        }
    }
    // cout<<ans.size()<<endl;
    // for(auto &it:ans){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    int flg=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        int flg1=0;
        for(int k=0;k<m;k++){
            if(s[i][k]!=s[i][m-1-k]){
                flg1=1;
                break;
            }
        }
        if(flg1==0){
            flg=i;
            break;
        }
    }
    if(flg){
        cout<<m*(ans.size()*2+1)<<endl;
    }
    else cout<<m*ans.size()*2<<endl;

    for(int i=0;i<ans.size();i++){
        cout<<s[ans[i].first];
    }
    if(flg)cout<<s[flg];
    for(int i=int(ans.size())-1;i>=0;i--){
        cout<<s[ans[i].second];
    }
    cout<<endl;

}