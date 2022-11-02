#include <bits/stdc++.h>
using namespace std;

int n, k;
const int maxn = 505;

typedef long long LL;

int a[maxn], b[maxn];

LL pre[maxn];

LL dp[maxn][maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    pre[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
        pre[i] = pre[i - 1] + a[i] + b[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < k;j++){
            if(dp[i - 1][j] == -1)
                continue;
            int j1 = pre[i - 1] - dp[i - 1][j] * k - j;
            for(int l = 0;l <= min(k - 1, a[i]);l++){
                int num = (a[i] + b[i] - l) / k;
                int red = l;
                if(b[i] < (a[i] + b[i] - l) - num * k)
                    continue;
                int blue = a[i] + b[i] - l - num * k;
                //int blue = min(b[i], (a[i] + b[i] - l) - num * k);
                int nred = (red + j) % k;
                int nblue = (blue + j1) % k;
                int add = (red + j) / k + (blue + j1) / k;
                dp[i][nred] = max(dp[i][nred], dp[i - 1][j] + add + num); 
            }
        }
    }
    //for(int i = 1;i <= n;i++){
    //    for(int j = 0;j < k;j++){
    //        cout << i << " " << j << " " << dp[i][j] << endl;
    //    }
    //}
    LL ans = 0;
    for(int j = 0;j < k;j++){
        ans = max(ans, dp[n][j]);
    }
    cout << ans << endl;
    return 0;
}