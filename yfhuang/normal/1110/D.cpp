#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
const int maxn = 1e6 + 5;

int dp[maxn][3][3][3];
int cnt[maxn];
int main(){
    while(cin >> n >> m){
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1;i <= n;i++){
            int a;
            scanf("%d", &a);
            cnt[a]++;
        }
        for(int i = 1;i <= m;i++){
            for(int j = 0;j < 3;j++){
                for(int k = 0;k < 3;k++){
                    for(int l = 0;l < 3;l++){
                        for(int t = 0;t < 3;t++){
                            if(cnt[i] - k - l - t < 0) continue;
                            if(cnt[i + 1] - l - t < 0) continue;
                            dp[i][k][l][t] = max(dp[i][k][l][t], dp[i - 1][j][k][l] + (cnt[i] - k - l - t) / 3 + t);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= m;i++){
            for(int j = 0;j < 3;j++){
                ans = max(ans, dp[i][j][0][0]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}