#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int _,dp[maxn][4],n,a[maxn];
char s[maxn];
void Min(int &x,int y){if (y<x)x=y;}

int main(){
    cin >> _;
    while (_--){
        cin >> n >> s;
        for (int i=0;i<n;i++) a[i]=(s[i]=='R');
        int ans=n;
        for (int o=0;o<4;o++){
            for (int i=0;i<=n;i++)
                for (int j=0;j<4;j++)
                    dp[i][j]=n;
            dp[0][o]=0;
            for (int i=0;i<n;i++)
                for (int j=0;j<4;j++)
                    for (int k=(j==0);k<=1-(j==3);k++)
                        Min(dp[i+1][(j&1)*2+k],dp[i][j]+(k^a[i]));
            ans=min(ans,dp[n][o]);
        }
        cout << ans << endl;
    }
    return 0;
}