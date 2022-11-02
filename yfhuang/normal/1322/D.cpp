#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
const int maxn = 2005;

typedef long long LL;

LL dp[maxn * 2][maxn];
int l[maxn], s[maxn];
int c[maxn * 2];
int cnt[maxn * 2];
const int INF = 0x3f3f3f3f;

int main(){
    memset(dp, -INF, sizeof(dp));
    scanf("%d%d", &n, &m);
    for(int i = n;i >= 1;i--){
        scanf("%d", &l[i]);
    }
    for(int i = n;i >= 1;i--){
        scanf("%d", &s[i]);
    }
    for(int i = 1;i <= n + m;i++){
        scanf("%d", &c[i]);
    }
    for(int i = 0;i <= m + n;i++){
        dp[i][0] = 0;
    }
    for(int i = 1;i <= n;i++){
        //dp[i][j][cnt] + c[j + 1] * (cnt / 2) -> dp[i][j + 1][cnt / 2]
        //dp[i][j][cnt] + c[j] - s[i] -> dp[i][j][cnt + 1]
        cnt[l[i]]++;
        for(int k = cnt[l[i]];k >= 1;k--){
            if(dp[l[i]][k - 1] != -INF)
                dp[l[i]][k] = max(dp[l[i]][k], dp[l[i]][k - 1] + c[l[i]] - s[i]); 
        }
        for(int j = l[i];j <= n + m;j++){
            for(int k = 0;k <= cnt[j];k++){
                if(dp[j][k] != -INF){
                    dp[j + 1][k / 2] = max(dp[j + 1][k / 2], dp[j][k] + c[j + 1] * (k / 2));
                    if(k / 2 > cnt[j + 1])
                        cnt[j + 1] = k / 2;
                }
            }
        }
    }
    LL ans = 0;
    for(int i = 0;i <= m + n;i++){
        for(int k = 0;k <= 1;k++){
            ans = max(ans, dp[i][k]);
        }
    }
    cout << ans << endl;
    return 0;
}