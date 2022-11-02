#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 405;
const int maxm = 250005;

int n, m;
int a[maxn];
int dp[maxn][maxn][maxn];

void init(){
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            dp[0][i][j] = a[j] - a[i];
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = i, t = i;j <= n;j++){
                while(t < j && max(dp[k - 1][i][t], a[j] - a[t]) > max(dp[k - 1][i][t + 1], a[j] - a[t + 1]))
                    t++;
                dp[k][i][j] = max(dp[k - 1][i][t], a[j] - a[t]);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d", a + i);
    } 
    init();
    long long ans = 0;
    for(int i = 1;i <= m;i++){
        int s, f, c, r;
        scanf("%d%d%d%d", &s, &f, &c, &r);
        ans = max(ans, 1LL * c * dp[r][s][f]);
    }
    cout << ans << endl;
    return 0;
}