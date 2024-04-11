#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;

const int maxn = 2e5 + 5;
int a[maxn];

long long dp[maxn];
long long sum[maxn];
int mx[maxn];
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
        //cout << sum[i] << endl;
    }
    for(int i = 1;i <= m;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        mx[x] = max(mx[x], y); 
    }
    dp[0] = 0;
    for(int i = 1;i <= k;i++){
        dp[i] = dp[i - 1] + a[i];
        //cout << i << " " << dp[i] << endl;
        for(int j = i - 1;j >= 0;j--){
            int len = i - j;
            int delta = len - mx[len];
            //cout << j << " " << dp[j] << " " << sum[i] - sum[i - delta] << endl;
            dp[i] = min(dp[i], dp[j] + sum[i] - sum[i - delta]);
        }
    }
    cout << dp[k] << endl;
    return 0;
}