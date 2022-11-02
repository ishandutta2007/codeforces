#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s,t;cin>>s>>t;
        vector<int> vec[20];
        int mp[20][20]={};
        int flg=0;
        for(int i=0;i<n;i++){
            if(s[i]>t[i]){
                flg=1;
                break;
            }
            else if(s[i]<t[i]){
                vec[s[i]-'a'].push_back(t[i]-'a');
            }
        }
        if(flg)cout<<"-1"<<endl;
        else{
            int cnt=0;
            for(int i=0;i<20;i++){
                int now=i;
                sort(vec[i].begin(),vec[i].end());
                vec[i].erase(unique(vec[i].begin(),vec[i].end()),vec[i].end());
                if(vec[i].size())cnt++;
                for(auto &it:vec[i]){
                    if(now!=i)vec[now].push_back(it);
                    now=it;
                }
            }
            
            // for(int i=0;i<20;i++){
            //     for(int j=0;j<20;j++){
            //         cout<<mp[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }

            // for(int i=0;i<20;i++){
            //     for(int j=0;j<20;j++){
            //         if(mp[i][j])cnt++;
            //     }
            // }

            cout<<cnt<<endl;
        }
    }
}