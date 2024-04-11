#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n;
const int maxn = 5005;
char s[maxn];
int dp[maxn][maxn];
int ans[maxn];
int main(){
    scanf("%s",s + 1);
    n = strlen(s + 1);
    for(int len = 1;len <= n;len++){
        for(int i = 1;i  + len - 1 <= n;i++){
            int r = i + len - 1;
            int l = i;
            int m = (l + r - 1) / 2;
            if(len == 1){
                dp[l][r] = 1;
                continue;
            }else if(len == 2){
                if(s[l] == s[r]) dp[l][r] = 2;
                else dp[l][r] = 0;
                continue;
            }
            if(s[l] != s[r]) continue;
            if(!dp[l + 1][r - 1]) continue;
            dp[l][r] = 1;
            if(len & 1){
                if(dp[l][m] && dp[m + 2][r]){
                    dp[l][r] = dp[l][m] + 1;
                }
            }else{
                if(dp[l][m] && dp[m + 1][r]){
                    dp[l][r] = dp[l][m] + 1;
                }
            }
        }
    }
    for(int len = 1;len <= n;len++){
        for(int i = 1;i + len - 1 <= n;i++){
            ans[dp[i][i + len - 1]]++;
        }
    }
    for(int i = n;i >= 1;i--){
        ans[i] += ans[i + 1];
    }
    for(int i = 1;i <= n;i++){
        printf("%d%c",ans[i],i == n ? '\n' : ' ');
    }
    return 0;
}