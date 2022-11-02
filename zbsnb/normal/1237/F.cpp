#include<iostream>
using namespace std;
#define ll long long 
const int mod=998244353;

int x[3610],y[3610];
int dp1[3610][3610],dp2[3610][3610];
void calcu(int dp[][3610],int vis[],int n){
    dp[0][0]=dp[1][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n/2;j++){
            dp[i][j]=dp[i-1][j];
            if(!vis[i]&&!vis[i-1]){
                dp[i][j]+=dp[i-2][j-1];
                dp[i][j]%=mod;
            }
        }
    }
}
ll c[3610][3610];
void init(){
    for(int i=0;i<3610;i++)c[i][0]=c[i][i]=1;
    for(int i=2;i<3610;i++){
        for(int j=1;j<i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    //for(int i=0;i<=4;i++)for(int j=0;j<=4;j++)cout<<c[i][j]<<" ";
}
ll fac[3610];
int main(){
    fac[0]=1;
    for(int i=1;i<3610;i++)fac[i]=fac[i-1]*i%mod;
    init();
    int a,b,n;cin>>a>>b>>n;
    int ra=a,rb=b;
    for(int i=1;i<=n;i++){
        int x1,y1;
        cin>>x1>>y1;x[x1]=y[y1]=1;
        cin>>x1>>y1;x[x1]=y[y1]=1;
    }
    for(int i=1;i<=a;i++)ra-=x[i];
    for(int i=1;i<=b;i++)rb-=y[i];
    //cout<<ra<<" "<<rb<<endl;
    calcu(dp1,x,a);
    calcu(dp2,y,b);
    ll ans=0;
    for(int i=0;i<=ra/2;i++){
        for(int j=0;j<=rb/2;j++){
            int ri=ra-2*i,rj=rb-2*j;
            if(ri<j||rj<i)continue;
            //cout<<i<<" "<<j<<" "<<dp1[a][i]<<" "<<dp2[b][j]<<" "<<c[ri][j]<<" "<<c[rj][i]<<endl;
            ans+=(fac[i]*fac[j]%mod)*(1ll*dp1[a][i]*dp2[b][j]%mod)%mod*(c[ri][j]*c[rj][i]%mod)%mod;
        }
    }
    cout<<ans%mod<<endl;
}