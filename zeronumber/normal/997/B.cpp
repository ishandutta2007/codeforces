#include<bits/stdc++.h>
#define maxn 423456
#define F first
#define S second

using namespace std;
typedef long long ll;
bool dp[210][10005],f[10005],g[10005];
ll n,k,ans;

int main(){
    cin >> n;
    if (n<=200){
        dp[0][0]=1;
        for (int i=1;i<=n;i++){
            for (int j=0;j<=(i-1)*50;j++){
                dp[i][j+1]|=dp[i-1][j];
                dp[i][j+5]|=dp[i-1][j];
                dp[i][j+10]|=dp[i-1][j];
                dp[i][j+50]|=dp[i-1][j];
            }
        }
        ans=0;
        for (int i=0;i<=n*50;i++) ans+=dp[n][i];
        cout << ans << endl;
        return 0;
    }
    f[0]=1; g[0]=1;
    for (int i=0;i<=2500;i++) {
        f[i+4]|=f[i];
        f[i+9]|=f[i];
        f[i+49]|=f[i];
        g[i+40]|=g[i];
        g[i+45]|=g[i];
        g[i+49]|=g[i];
    }
    ans=n*50-n+1;
    for (int i=1;i<=2500;i++) if (!f[i]) ans--;
    for (int i=1;i<=2500;i++) if (!g[i]) ans--;
    cout << ans << endl;
}