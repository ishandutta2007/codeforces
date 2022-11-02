#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n, l, k;
const int maxn = 205;

double dp[maxn][maxn][maxn];

int p[maxn];
int a[maxn];
pair<int, int> x[maxn];

int main(){
    memset(dp, 0, sizeof(dp));
    cin >> n >> l >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d", &p[i]);
        x[i].second = p[i];
    } 
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        x[i].first = -a[i];
    }
    sort(x + 1, x + 1 + n);
    for(int i = 1;i <= n;i++){
        p[i] = x[i].second;
        a[i] = -x[i].first;
    }
    dp[0][0][k] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= n;j++){
            for(int cap = 0;cap <= 200;cap++){
                dp[i + 1][j][cap] += dp[i][j][cap] * (1 - p[i + 1] / 100.0);
                if(a[i + 1] == -1 and cap > 0){
                    dp[i + 1][j + 1][cap - 1] += dp[i][j][cap] * p[i + 1] / 100.0;
                }
                if(a[i + 1] >= 1){
                    int newcap = min(n, cap + a[i + 1]);
                    dp[i + 1][j + 1][newcap] += dp[i][j][cap] * p[i + 1] / 100.0;
                }
            } 
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= n;j++){
            for(int cap = 0;cap <= n;cap++){
//                cout << i << " " << j << " " << cap << " " << dp[i][j][cap] << endl;
            }
        }
    }
    double ans = 0;
    for(int i = l;i <= n;i++){
        for(int cap = 0;cap <= 200;cap++){
            ans += dp[n][i][cap];
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}