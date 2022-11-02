#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
// #define int long long
 
char s[1000],ss[1000];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>(s+1)>>(ss+1);
        int n=strlen(s+1);
        int m=strlen(ss+1);
        
        int flg=0;
        for(int i=0;i<=m;i++){
            int len1=i;
            int len2=m-i;
            vector<pair<int,int> > dp;
            dp.push_back({0,len1});
            
            for(int i=1;i<=n;i++){
                int sz=dp.size();
                for(int j=0;j<sz;j++){
                    if(dp[j].first==len1&&dp[j].second==m){
                        flg=1;
                        break;
                    }
 
                    if(s[i]==ss[dp[j].first+1]&&s[i]==ss[dp[j].second+1]){
                        dp.push_back({dp[j].first,dp[j].second+1});
                        dp[j].first++;
                    } 
                    else if(s[i]==ss[dp[j].first+1]){
                        dp[j].first++;
                    }
                    else if(s[i]==ss[dp[j].second+1]){
                        dp[j].second++;
                    }
                }
                vector<int> tp(m+2,-1);
                for(int i=0;i<dp.size();i++){
                    tp[dp[i].first]=max(tp[dp[i].first],dp[i].second);
                }
                
                dp.clear();
                for(int i=0;i<tp.size();i++){
                    if(tp[i]!=-1){
                        dp.push_back({i,tp[i]});
                    }
                }
                sort(dp.begin(),dp.end());
                dp.erase(unique(dp.begin(),dp.end()),dp.end());
                // random_shuffle(dp.begin(),dp.end());
                if(flg)break;
            }
            for(auto &it:dp){
                if(it.first==len1&&it.second==m){
                    flg=1;
                    break;
                }
            }
            if(flg)break;
        }
 
        cout<<(flg?"YES":"NO")<<endl;
    }
}
                // sort(dp,dp+p);
                // cout<<"origin"<<endl;
                // for(int i=0;i<p;i++){
                //     cout<<dp[i].first<<" "<<dp[i].second<<endl;
                // }
                // vector<int> tp(m+2,-1);
                // for(int i=0;i<p;i++){
                //     tp[dp[i].first]=max(tp[dp[i].first],dp[i].second);
                // }
                
                // p=0;
                // for(int i=0;i<tp.size();i++){
                //     if(tp[i]!=-1){
                //         dp[p++]={i,tp[i]};
                //     }
                // }
                // cout<<"now"<<endl;
                // for(int i=0;i<p;i++){
                //     cout<<dp[i].first<<" "<<dp[i].second<<endl;
                // }