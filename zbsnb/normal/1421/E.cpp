#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000010];
ll dp[6][1000010];
ll dp2[6][1000010];
inline int t(string x){
    if(x=="++") return 0;
    if(x=="--") return 1;
    if(x=="+-") return 2;
    if(x=="-+") return 3;
    if(x=="+") return 4;
    if(x=="-") return 5;
}
void solve(string x,string y,string z,int i){
    dp[t(z)][i]=max(dp[t(z)][i],dp[t(x)][i-1]+(y=="+"?a[i]:-a[i]));
}
void solve2(string x,string y,string z,int i){
    dp2[t(z)][i]=max(dp2[t(z)][i],dp2[t(x)][i+1]+(y=="+"?a[i]:-a[i]));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<6;j++){
            dp[j][i]=dp2[j][i]=-1e18;
        }
    }
    for(int i=1;i<=n;i++){
        // ++,--,+-,-+,+,-
        if(i==1){
            dp[t("+")][i]=a[i];
            dp[t("-")][i]=-a[i];
        }
        else{
            solve("++","-","+-",i);
            solve("++","+","-",i);
            solve("--","-","+",i);
            solve("--","+","-+",i);
            solve("+-","-","-",i);
            solve("+-","+","++",i);
            solve("-+","-","--",i);
            solve("-+","+","+",i);
            solve("+","-","+-",i);
            solve("+","+","-",i);
            solve("-","-","+",i);
            solve("-","+","-+",i);
        }
    }
    for(int i=n;i>=1;i--){
        // ++,--,+-,-+,+,-
        if(i==n){
            dp2[t("+")][i]=a[i];
            dp2[t("-")][i]=-a[i];
        }
        else{
            solve2("++","-","+-",i);
            solve2("++","+","-",i);
            solve2("--","-","+",i);
            solve2("--","+","-+",i);
            solve2("+-","-","-",i);
            solve2("+-","+","++",i);
            solve2("-+","-","--",i);
            solve2("-+","+","+",i);
            solve2("+","-","+-",i);
            solve2("+","+","-",i);
            solve2("-","-","+",i);
            solve2("-","+","-+",i);
        }
    }
    ll ans=dp[t("+")][n];
    for(int i=1;i<=n-1;i++){
        ans=max(ans,dp[t("-")][i]+dp2[t("-")][i+1]);
    }
    cout<<ans<<endl;
}