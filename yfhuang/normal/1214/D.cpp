#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


const int maxn = 3000000;
int dp[maxn];
int dp1[maxn];
int cnt[maxn];
int n, m;
char s[maxn], t[maxn];

int in(int x, int y){
    if(x < 1 || x > n) return false;
    if(y < 1 || y > m) return false;
    return true;
}

int id(int x, int y){
    return (x - 1) * m + y;
}

int main(){
    cin >> n >> m;
    int now = 1;
    for(int i = 1;i <= n;i++){
        scanf("%s", s);
        int len = strlen(s);
        strcpy((t + now), s);
        now += len;
    }
    dp[id(1, 1)] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            int idx = id(i, j);
            if(t[idx] == '#'){  
                dp[idx] = 0;
                continue;
            }else{
                if(in(i - 1, j)){
                    dp[idx] += dp[id(i - 1, j)];
                }
                if(in(i, j - 1)){
                    dp[idx] += dp[id(i, j - 1)];
                }
                dp[idx] = min(2000, dp[idx]);
            }
        }
    }
    dp1[id(n, m)] = 1;
    for(int i = n;i >= 1;i--){
        for(int j = m;j >= 1;j--){
            int idx = id(i, j);
            if(t[idx] == '#'){
                dp1[idx] = 0;
                continue;
            }else{
                if(in(i + 1, j)){
                    dp1[idx] += dp1[id(i + 1, j)];
                }
                if(in(i, j + 1)){
                    dp1[idx] += dp1[id(i, j + 1)];
                }
                dp1[idx] = min(2000, dp1[idx]);
            }
        }
    }
    int ans = min(2, dp[id(n, m)]);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            int idx = id(i, j);
            if(dp[idx] != 0 && dp1[idx] != 0){
                cnt[i + j]++;
            }
        }
    }
    for(int i = 3;i < n + m;i++){
        if(cnt[i] == 1){
            ans = min(ans, 1);
        }
        if(cnt[i] == 0){
            ans = 0;
        }
    }
    cout << ans << endl;
    return 0;
}