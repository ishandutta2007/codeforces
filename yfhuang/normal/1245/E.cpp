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

const int maxn = 15;
int a[maxn][maxn];

double dp[maxn][maxn];

int main(){
    for(int i = 1;i <= 10;i++){
        for(int j = 1;j <= 10;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1;i <= 10;i++){
        int st, ed, step;
        if(i & 1){
            st = 1, ed = 11, step = 1;
        }else{
            st = 10, ed = 0, step = -1;
        }
        for(int j = st;j != ed;j += step){
            if(i == 1 and j == 1){
                dp[i][j] = 0.0;
            }else{
                int dir;
                if(i & 1){
                    dir = -1;
                }else{
                    dir = 1;
                }
                int x = i, y = j;
                for(int k = 1; k <= 6;k++){
                    y += dir;
                    if(y == 0){
                        x--;
                        y = 1;
                        dir = -dir;
                    }else if(y == 11){
                        x--;
                        y = 10;
                        dir = -dir;
                    }
                    int nx = x, ny = y;
                    if(a[nx][ny] != 0){
                        if(dp[nx - a[nx][ny]][ny] < dp[nx][ny]){
                            nx = nx - a[nx][ny];
                        }
                    }
                    dp[i][j] += 1.0 / 6 * dp[nx][ny];
                }
                dp[i][j] += 1.0;
                if(i == 1 and j <= 6){
                    dp[i][j] *= 1.0 * 6 / (j - 1); 
                }
            }
        }
    }
    //for(int i = 1;i <= 10;i++){
    //    for(int j = 1;j <= 10;j++){
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    printf("%.10lf\n", dp[10][1]);
    return 0;
}