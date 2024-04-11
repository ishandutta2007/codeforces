#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxn = 105;
int a[maxn];
int dp[2][maxn][maxn][maxn];

void upd(int &a, int b){
    if(a == -1)
        a = b;
    else
        a = min(a, b);
}

int main(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    dp[0][0][(n) / 2][(n + 1) / 2] = 0;
    dp[1][0][(n) / 2][(n + 1) / 2] = 0;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= (n) / 2;j++){
            for(int k = 0;k <= (n + 1) / 2;k++){
                if(dp[0][i][j][k] != -1){
                    if(a[i + 1] == 0){
                        if(j > 0){
                            upd(dp[0][i + 1][j - 1][k], dp[0][i][j][k]);       
                        }
                        if(k > 0){
                            upd(dp[1][i + 1][j][k - 1], dp[0][i][j][k] + 1);
                        }
                    }else{
                        if(a[i + 1] & 1){
                            if(k > 0){
                                upd(dp[1][i + 1][j][k - 1], dp[0][i][j][k] + 1);
                            }
                        }else{
                            if(j > 0){
                                upd(dp[0][i + 1][j - 1][k], dp[0][i][j][k]);
                            }
                        }
                    }
                }
                if(dp[1][i][j][k] != -1){
                    if(a[i + 1] == 0){
                        if(j > 0){
                            upd(dp[0][i + 1][j - 1][k], dp[1][i][j][k] + 1);       
                        }
                        if(k > 0){
                            upd(dp[1][i + 1][j][k - 1], dp[1][i][j][k]);
                        }
                    }else{
                        if(a[i + 1] & 1){
                            if(k > 0){
                                upd(dp[1][i + 1][j][k - 1], dp[1][i][j][k]);
                            }
                        }else{
                            if(j > 0){
                                upd(dp[0][i + 1][j - 1][k], dp[1][i][j][k] + 1);
                            }
                        }
                    }

                }
            }
        }
    }
    //cout << dp[1][1][2][2] << endl;
    //cout << dp[1][2][2][1] << endl;
    //cout << dp[0][3][1][1] << endl;
    if(dp[0][n][0][0] == -1){
        cout << dp[1][n][0][0] << endl;
        return 0;
    }
    if(dp[1][n][0][0] == -1){
        cout << dp[0][n][0][0] << endl;
        return 0;
    }
    cout << min(dp[0][n][0][0], dp[1][n][0][0]) << endl;
    return 0;
}