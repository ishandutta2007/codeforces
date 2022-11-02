#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int dp[5005][5005],f[5005],n,ans[5005];
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
int main(){
    cin >> n;
    dp[1][1]=1;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=i;j++)
            dp[i][j]=(1ll*j*dp[i-1][j]+1ll*(i-j+1)*dp[i-1][j-1])%M;
    f[n]=1; for (int i=n;i>1;i--) f[i-1]=1ll*f[i]*i%M;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
            add(ans[j],1ll*f[i]*dp[i][j]%M);
    for (int i=1;i<=n;i++) cout << ans[i] << ' '; cout << endl;
    return 0;
}