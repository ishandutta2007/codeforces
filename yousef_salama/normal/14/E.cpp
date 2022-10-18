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
#include <string.h>
using namespace std;
int n, t, dp[22][5][12][12][3];
int main(){
    scanf("%d %d", &n, &t);
    for(int y = 0; y <= 4; y++)
    for(int p = 0; p <= 2; p++)
        dp[n][y][0][0][p] = 1;
    for(int x = n - 1; x > 0; x--)
    for(int y = 1; y <= 4; y++)
        for(int h = 0; h <= t; h++)
        for(int ht = 0; ht <= t; ht++)
        for(int p = 0; p <= 2; p++){
            for(int ny = 1; ny <= 4; ny++)if(y != ny){
                int np = 1 + (ny > y), nh = h - (p == 2 && np == 1), nht = ht - (p == 1 && np == 2);
                if(nh >= 0 && nht >= 0)dp[x][y][h][ht][p] += dp[x + 1][ny][nh][nht][np];
            }
        }
    int ans = 0;
    for(int y = 1; y <= 4; y++)
        ans += dp[1][y][t][t - 1][0];
    printf("%d\n", ans);
    return 0;
}