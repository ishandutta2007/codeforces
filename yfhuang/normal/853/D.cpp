#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

const int N = 300;
const int INF = 0x3fffffff;
int dp[2][N + 5];
int n;
const int M = 300000 + 5;
int a[M];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < 2;i++){
        for(int j = 0;j <= N;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        int now = i & 1,pre = (now ^ 1);
        for(int j = 0;j <= N;j++) dp[now][j] = INF;
        for(int j = 0;j <= N;j++){
            int c = min(j,a[i] / 10);
            dp[now][j - c] = min(dp[now][j - c],dp[pre][j] + (a[i] - 10 * c));
            if(j + a[i] / 100 <= N)
                dp[now][j + a[i] / 100] = min(dp[now][j + a[i] / 100],dp[pre][j] + a[i]);
        }
    }
    int ans = INF;
    for(int i = 0;i <= N;i++){
        ans = min(ans,dp[n & 1][i]);
    }
    cout << ans << endl;
    return 0;
}