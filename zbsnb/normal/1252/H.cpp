#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long 
const ll mod=1e9+7;
ll dp[2010][2010][2];
int sumx[2010][2010],sumy[2010][2010];
int nowx[2010],nowy[2010];
char mp[2010][2010];
void add(ll &a,ll b){a+=b;a%=mod;}
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            sumx[i][j]=sumx[i+1][j]+(mp[i][j]=='R');
            sumy[i][j]=sumy[i][j+1]+(mp[i][j]=='R');
        }
    }

    if(n==1&&m==1){
        cout<<1<<endl;
        return 0;
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<sumx[i][j];
    //     }cout<<endl;
    // }cout<<endl;

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<sumy[i][j];
    //     }cout<<endl;
    // }cout<<endl;

    dp[1][1][0]=dp[1][1][1]=1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)continue;

            while(sumx[nowx[j]+2][j]>n-i)nowx[j]++;
            while(sumy[i][nowy[i]+2]>m-j)nowy[i]++;
            
            //cout<<i<<" "<<j<<" "<<nowx[j]<<" "<<nowy[i]<<endl;

            add(dp[i][j][0],dp[i-1][j][1]);
            add(dp[i][j][0],-dp[nowx[j]][j][1]);

            add(dp[i][j][1],dp[i][j-1][0]);
            add(dp[i][j][1],-dp[i][nowy[i]][0]);

            if(i==n&&j==m)ans+=(dp[i][j][0]+dp[i][j][1])%mod;
            add(dp[i][j][0],dp[i][j-1][0]);
            add(dp[i][j][1],dp[i-1][j][1]);
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j][0];
    //     }cout<<endl;
    // }cout<<endl;

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j][1];
    //     }cout<<endl;
    // }cout<<endl;

    cout<<(ans+mod)%mod<<endl;
}