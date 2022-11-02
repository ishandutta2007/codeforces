#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1010];
int dp[100][100][100*100];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;

    int m=0,now=0,cnt=0;
    for(int i=1;i<=n+1;i++){
        if(i==n+1) a[++m]=now;
        else{
            int tmp;cin>>tmp;
            if(tmp==1){
                a[++m]=now;
                now=0;
                cnt++;
            }
            else now++;
        }
    }

    int sum=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n-cnt;j++){
            for(int k=0;k<=n*(n-1)/2;k++){
                if(i==0){
                    dp[i][j][k]=j==0?0:1e9;
                }
                else{
                    dp[i][j][k]=1e9;
                    for(int o=0;o<=j;o++){
                        int now=k-abs(sum-o);
                        if(now<0) continue;
                        dp[i][j][k]=min(
                            dp[i][j][k],dp[i-1][o][now]+(j-o)*(j-o));
                            // if(i==1&&j==1&&k==0){
                            //     cout<<"now"<<endl;
                            //     cout<<i-1<<" "<<o<<" "<<now<<" "<<dp[i-1][o][now]<<endl;
                            // }
                    }
                }
                // cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
                if(i==m&&j==n-cnt) cout<<((n-cnt)*(n-cnt)-dp[i][j][k])/2<<" ";
            }
        }
        sum+=a[i];
    }
    
}