#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
#define up(it,vec) for(auto it=vec.begin();it!=vec.end();it++)
#define dn(it,vec) for(auto it=vec.rbegin();it!=vec.rend();it++)
// #define int long long

ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
const int inf=1e9;
int dp[110][110][110][2];
int a[110];
int vis[110];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]=1;
    }
    int ji=0,o=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(i%2)ji++;
            else o++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            for(int j=0;j<=100;j++){
                for(int k=0;k<=100;k++){
                    if(a[i]%2){
                        dp[i][j][k][1]=min(dp[i-1][j][k][1],dp[i-1][j][k][0]+1);
                        dp[i][j][k][0]=1e9;
                    }
                    else{
                        dp[i][j][k][0]=min(dp[i-1][j][k][1]+1,dp[i-1][j][k][0]);
                        dp[i][j][k][1]=1e9;
                    }
                }
            }
        }
        else{
            for(int j=0;j<=100;j++){
                for(int k=0;k<=100;k++){
                    dp[i][j][k][1]=min(j==0?inf:dp[i-1][j-1][k][1],j==0?inf:(dp[i-1][j-1][k][0]+1));
                    dp[i][j][k][0]=min(k==0?inf:(dp[i-1][j][k-1][1]+1),k==0?inf:dp[i-1][j][k-1][0]);
                }
            }
        }
    }
    cout<<min(dp[n][ji][o][0],dp[n][ji][o][1])<<endl;
}