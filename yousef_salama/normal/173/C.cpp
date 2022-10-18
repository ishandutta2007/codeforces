#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int n, m, g[505][505], sum[505][505], dp[2][505][505];
int getSum(int a, int b, int c, int d){
    return sum[c][d] - (a > 0?sum[a - 1][d]:0) - (b > 0?sum[c][b - 1]:0) + (a > 0 && b > 0?sum[a - 1][b - 1]:0);
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin >> g[i][j];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        sum[i][j] = (i > 0?sum[i - 1][j]:0) + (j > 0?sum[i][j - 1]:0) - (i > 0 && j > 0?sum[i - 1][j - 1]:0) +
                g[i][j];
    int max = -1 << 30;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        dp[0][i][j] = g[i][j];
    int idx = 1;
    for(int k = 3; k <= min(n, m); k += 2){
        for(int i = 0; i + k <= n; i++)
        for(int j = 0; j + k <= m; j++){
            int sum = getSum(i, j, i + k - 1, j + k - 1);
            int sub = getSum(i + 1, j + 1, i + k - 2, j + k - 2);
            dp[idx&1][i][j] = sum - dp[(idx - 1)&1][i + 1][j + 1] - g[i + 1][j];
            max = std::max(max, dp[idx&1][i][j]);
        }
        idx++;
    }
    cout << max << endl;
    return 0;
}