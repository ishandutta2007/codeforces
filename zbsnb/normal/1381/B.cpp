#include<bits/stdc++.h>
using namespace std;
int a[4010];
int dp[2010];
int lim[2010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int maxn=0,cnt=0;
        map<int,int> mp;
        for(int i=1;i<=2*n;i++){
            cin>>a[i];
            if(a[i]>maxn){
                maxn=a[i];
                mp[cnt]++;
                cnt=1;
            }
            else cnt++;
        }
        for(int i=1;i<=n;i++)dp[i]=-1;
        for(auto &it:mp){
            int now=it.first;
            int cnt=it.second;
            for(int i=0;i<=n;i++)lim[i]=0;
            for(int i=0;i<=n;i++){
                if(dp[i]!=-1&&now+i<=n&&dp[now+i]==-1&&lim[i]<cnt){
                    dp[now+i]=1;
                    lim[now+i]=lim[i]+1;
                }
            }
            
        }
        cout<<(dp[n]==-1?"NO":"YES")<<endl;
    }
}