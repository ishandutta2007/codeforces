#include <bits/stdc++.h>
using namespace std;

string S, T;

const int mod = 998244353;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

const int maxn = 3005;
int dp[maxn][maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> S >> T;
    int n = S.length(), m = T.length();
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(i <= m){
            if(S[0] == T[i - 1])
                dp[i][i] = 2;
            else
                dp[i][i] = 0;
        }else{
            dp[i][i] = 2;    
        }
        if(1 >= m)
            add(ans, dp[1][1]);
    }     
    for(int i = 2;i <= n;i++){
        int len = i - 1;
        for(int j = 1;j + len - 1 <= n;j++){
            if(dp[j][j + len - 1] == 0)
                continue;
            int l = j - 1;
            int r = j + len;
            if(l > 0){
                if(l <= m){
                    if(S[i - 1] == T[l - 1])
                        add(dp[l][j + len - 1], dp[j][j + len - 1]);
                }else{
                    add(dp[l][j + len - 1], dp[j][j + len - 1]);
                }
            }
            if(r <= n){
                if(r <= m){
                    if(S[i - 1] == T[r - 1])
                        add(dp[j][r], dp[j][j + len - 1]);
                }else{
                    add(dp[j][r], dp[j][j + len - 1]);
                }
            }
        }
        if(i >= m){
            add(ans, dp[1][i]);
        }
    }
    cout << ans << endl;
    return 0;
}