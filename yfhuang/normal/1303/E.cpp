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

int T;

const int maxn = 405;

char s[maxn], t[maxn];

int dp[maxn][maxn];

int main(){
    cin >> T;
    while(T--){
        int n, m;
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        n = strlen(s + 1);
        m = strlen(t + 1);
        bool flag = false;
        for(int len1 = 1;len1 <= m;len1++){
            int len2 = m - len1;
            for(int i = 0;i <= n;i++){
                for(int j = 0;j <= len1;j++){
                    dp[i][j] = -1;
                }
            }
            dp[0][0] = 0;
            for(int i = 0;i < n;i++){
                for(int j = 0;j <= len1;j++){
                    if(dp[i][j] == -1){
                        continue;
                    }
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                    if(j < len1 and s[i + 1] == t[j + 1]){
                        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                    }
                    if(dp[i][j] < len2 and s[i + 1] == t[len1 + dp[i][j] + 1]){
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
                    }
                } 
            } 
            if(dp[n][len1] == len2){
                flag = true;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}