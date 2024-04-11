#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s,t;cin>>s>>t;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                ans.push_back(i+1);
                ans.push_back(1);
                ans.push_back(i+1);
            }
        }
        cout<<ans.size()<<" ";
        for(auto &it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}