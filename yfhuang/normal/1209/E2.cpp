#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int t;
int n, m;

int a[15][2005];
int b[15][15];
int s[(1 << 12) + 5];
int dp[2][(1 << 12) + 5];
int sum[(1 << 12) + 5];
int maxsum[(1 << 12) + 5];
pair<int, int> maxa[2005];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0;i < n;i++){
            for(int j = 1;j <= m;j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int j = 1;j <= m;j++){
            maxa[j] = make_pair(a[0][j], j);
            for(int i = 1;i < n;i++){
                maxa[j].first = max(maxa[j].first, a[i][j]);
            }
        }
        sort(maxa + 1, maxa + m + 1);
        for(int j = 1;j <= n;j++){
            for(int i = 0;i < n;i++){
                b[i][j] = a[i][maxa[m + 1 - j].second]; 
            }
        }

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1;i <= n;i++){
            int cur = i & 1;
            int pre = cur ^ 1;
            memset(dp[cur], -1, sizeof(dp[cur]));
            for(int j = 0;j < (1 << n);j++){
                maxsum[j] = 0;
            }
            for(int j = 0;j < n;j++){
                int tmp = b[0][i];
                for(int k = 0;k < n - 1;k++){
                    b[k][i] = b[k + 1][i]; 
                }
                b[n - 1][i] = tmp;
                for(int mask = 0;mask < (1 << n);mask++){
                    sum[mask] = 0;
                    for(int k = 0;k < n;k++){
                        if(mask & (1 << k)){
                            sum[mask] += b[k][i];
                        }
                    }
                    maxsum[mask] = max(maxsum[mask], sum[mask]);
                } 
            }
            for(int j = 0;j < (1 << n);j++){
                dp[cur][j] = dp[pre][j];
                for(int k = j; k != 0;k = (k - 1) & j){
                    if(dp[pre][j ^ k] != -1){
                        dp[cur][j] = max(dp[cur][j], dp[pre][j ^ k] + maxsum[k]);
                    }
                }
                //printf("dp[%d][%d] = %d\n", i, j, dp[cur][j]);
            }
        }
        cout << dp[n & 1][(1 << n) - 1] << endl;
    }
    return 0;
}