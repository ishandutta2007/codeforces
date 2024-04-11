//
//  main.cpp
//  D
//
//  Created by  on 10/11/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 105;

double dp[maxn][maxn][maxn];

int r,s,p;

int main(int argc, const char * argv[]) {
    cin >> r >> s >> p;
    memset(dp,0,sizeof(dp));
    dp[r][s][p] = 1.0;
    for(int i = r;i >= 0;i--){
        for(int j = s;j >= 0;j--){
            for(int k = p;k >= 0;k--){
                if(i > 0 && k > 0){
                    dp[i - 1][j][k] += 1.0 * i * k / (1.0 * i * k + 1.0 * i * j + 1.0 * j * k) * dp[i][j][k];
                }
                if(j > 0 && i > 0){
                    dp[i][j - 1][k] += 1.0 * i * j / (1.0 * i * j + 1.0 * i * k + 1.0 * j * k) * dp[i][j][k];
                }
                if(k > 0 && j > 0){
                    dp[i][j][k - 1] += 1.0 * k * j / (1.0 * i * j + 1.0 * j * k + 1.0 * i * k) * dp[i][j][k];
                }
            }
        }
    }
    double ans1 = 0,ans2 = 0,ans3 = 0;
    for(int i = 1;i <= r;i++){
        ans1 += dp[i][0][0];
    }
    for(int i = 1;i <= s;i++){
        ans2 += dp[0][i][0];
    }
    for(int i = 1;i <= p;i++){
        ans3 += dp[0][0][i];
    }
    printf("%.12lf %.12lf %.12lf\n",ans1,ans2,ans3);
    return 0;
}