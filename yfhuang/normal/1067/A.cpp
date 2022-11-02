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

int n;
const int maxn = 1e5 + 5;

int a[maxn];
int dp[3][maxn][205];

const int mod = 998244353;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
    if(a < 0)
        a += mod;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    if(a[1] == -1){
        for(int i = 1;i <= 200;i++){
            dp[0][1][i] = 1;
        }
    }else{
        dp[0][1][a[1]] = 1;
    }
    for(int i = 1;i <= 200;i++){
        add(dp[0][1][i], dp[0][1][i - 1]);
    }
    for(int i = 1;i < n;i++){
        if(a[i + 1] == -1){
            for(int val = 1;val <= 200;val++){
                add(dp[0][i + 1][val], dp[0][i][val - 1]);
                add(dp[2][i + 1][val], dp[0][i][val] - dp[0][i][val - 1]);
                add(dp[0][i + 1][val], dp[1][i][val - 1]);
                add(dp[1][i + 1][val], dp[1][i][200] - dp[1][i][val]);
                add(dp[2][i + 1][val], dp[1][i][val] - dp[1][i][val - 1]);
                add(dp[0][i + 1][val], dp[2][i][val - 1]);
                add(dp[2][i + 1][val], dp[2][i][val] - dp[2][i][val - 1]);
                add(dp[1][i + 1][val], dp[2][i][200] - dp[2][i][val]);
            }
        }else{
            int val = a[i + 1];
            add(dp[0][i + 1][val], dp[0][i][val - 1]);
            add(dp[2][i + 1][val], dp[0][i][val] - dp[0][i][val - 1]);
            add(dp[0][i + 1][val], dp[1][i][val - 1]);
            add(dp[1][i + 1][val], dp[1][i][200] - dp[1][i][val]);
            add(dp[2][i + 1][val], dp[1][i][val] - dp[1][i][val - 1]);
            add(dp[0][i + 1][val], dp[2][i][val - 1]);
            add(dp[2][i + 1][val], dp[2][i][val] - dp[2][i][val - 1]);
            add(dp[1][i + 1][val], dp[2][i][200] - dp[2][i][val]);
        }
        for(int j = 0;j < 3;j++){
            for(int val = 1;val <= 200;val++){
                add(dp[j][i + 1][val], dp[j][i + 1][val - 1]);
                //if(dp[j][i + 1][val] != 0){
                //    cout << j << " " << i + 1 << " " << val << " " << dp[j][i + 1][val] << endl;
                //}
            }
        }
    }
    int ans = dp[1][n][200];
    add(ans, dp[2][n][200]);
    cout << ans << endl;
    return 0;
}