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
#include <random>
#include <chrono>
using namespace std;

int n;
const int maxn = 505;


int dp[maxn][maxn];
int ans[maxn][maxn];
int a[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= n;i++){
        dp[i][i] = 1;
        ans[i][i] = a[i];
    } 
    for(int len = 2;len <= n;len++){
        for(int i = 1;i + len - 1 <= n;i++){
            int j = i + len - 1;
            dp[i][j] = len;
            for(int k = i;k < j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                if(dp[i][k] == 1 and dp[k + 1][j] == 1 and ans[i][k] == ans[k + 1][j]){
                    dp[i][j] = 1;
                    ans[i][j] = ans[i][k] + 1; 
                }
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}