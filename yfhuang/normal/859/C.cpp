#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

const int maxn = 55;

int a[maxn];
int n;
int dp[maxn][2];

int main(){
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }
    memset(dp,0,sizeof(dp));
    for(int i = n;i >= 1;i--){
        dp[i][0] = dp[i + 1][0] - a[i];
        dp[i][0] = max(dp[i][0],a[i] + dp[i + 1][1]);
        dp[i][1] = dp[i + 1][1] + a[i];
        dp[i][1] = min(dp[i][1],dp[i + 1][0] - a[i]);
    }
    cout << (sum - dp[1][0]) / 2 << " " << (sum + dp[1][0]) / 2 << endl;
    return 0;
}