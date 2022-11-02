#include<bits/stdc++.h>
using namespace std;
#define ll long long

char mp[55][55];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>mp[i]+1;
        vector<string> vec;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(char k='a';k<='z';k++){
                    string s;
                    for(int o=1;o<j;o++)s.push_back(mp[i][o]);
                    s.push_back(k);
                    for(int o=j+1;o<=m;o++)s.push_back(mp[i][o]);
                    vec.push_back(s);
                }
            }
        }
        int flg=0;
        string ans;
        for(auto &s:vec){
            // cout<<s<<endl;
            int tot=0;
            for(int i=1;i<=n;i++){
                int cnt=0;
                for(int j=1;j<=m;j++){
                    if(s[j-1]==mp[i][j])cnt++;
                }
                if(cnt>=m-1)tot++;
            }
            if(tot>=n){
                flg=1;
                ans=s;
                break;
            }
        }
        if(flg)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}