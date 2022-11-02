#include<bits/stdc++.h>
using namespace std;
int f[100010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s,t;cin>>s>>t;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int tmp;
            if(n&1) tmp=i<=n/2?(n/2-i)*2:(i-n/2)*2-1;
            else tmp=i<n/2?(n/2-i)*2-1:(i-n/2)*2;
            f[tmp]=i;
        }
        for(int i=0;i<n;i++){
            ans.push_back(i+1);
            if((s[i]!=t[f[i]])^((n-i)&1)){
                ans.push_back(1);
            }
        }
        cout<<ans.size()<<" ";
        for(auto &it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}