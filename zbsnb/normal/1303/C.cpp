#include<iostream>
#include<vector>
using namespace std;
// #define int long long

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        if(s.size()==1){
            cout<<"YES"<<endl;
            for(char i='a';i<='z';i++){
                cout<<i;
            }
            cout<<endl;
            continue;
        }
        char ans[1000];
        int l=449,r=452;
        ans[450]=s[0];
        ans[451]=s[1];
        int now=451;
        int flg=0;
        for(int i=2;i<s.size();i++){
            if(now==l+1){
                if(s[i]==ans[now+1]){
                    now++;
                }
                else{
                    ans[l--]=s[i];
                    now--;
                }
            }
            else if(now==r-1){
                if(s[i]==ans[now-1]){
                    now--;
                }
                else{
                    ans[r++]=s[i];
                    now++;
                }
            }
            else {
                if(s[i]==ans[now+1])now++;
                else if(s[i]==ans[now-1])now--;
                else {
                    cout<<"NO"<<endl;
                    flg=1;
                    break;
                }
            }
        }
        if(flg)continue;
        int vis[26]={};
        // cout<<l<<" "<<r<<endl;
        for(int i=l+1;i<=r-1;i++){
            // cout<<ans[i];
            vis[ans[i]-'a']++;
        }
        // cout<<endl;
        for(int i=0;i<26;i++){
            if(vis[i]>=2){
                cout<<"NO"<<endl;
                flg=1;
                break;
            }
        }
        if(flg)continue;
        cout<<"YES"<<endl;
        for(int i=l+1;i<=r-1;i++){
            cout<<ans[i];
        }
        for(int i=0;i<26;i++){
            char tmp=i+'a';
            if(!vis[i])cout<<tmp;
        }
        cout<<endl;
    }
}