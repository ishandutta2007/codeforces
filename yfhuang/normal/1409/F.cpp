#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, k;

const int maxn = 205;
int dp[2][maxn][maxn];
string s, t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    cin >> s;
    cin >> t;
    if(t[0] == t[1]){
        for(int i = 0;i < s.length();i++){
            if(s[i] != t[0] and k > 0){
                s[i] = t[0];
                k--;
            }
        }
        int cnt = 0;
        for(int i = 0;i < s.length();i++){
            if(s[i] == t[0])
                cnt++;
        }
        cout << 1LL * cnt * (cnt - 1) / 2 << endl;
    }else{
        memset(dp, -1, sizeof(dp));
        dp[0][k][0] = 0;
        for(int i = 0;i < s.length();i++){
            int cur = i & 1;
            int nxt = cur ^ 1;
            memset(dp[nxt], -1, sizeof(dp[nxt]));
            for(int j = 0;j <= k;j++){
                for(int l = 0;l <= s.length();l++){
                    if(dp[cur][j][l] != -1){
                        dp[nxt][j][l] =  max(dp[nxt][j][l], dp[cur][j][l]);
                        if(s[i] == t[0]){
                            dp[nxt][j][l+1] = max(dp[nxt][j][l+1], dp[cur][j][l]);
                        }else{
                            if(j > 0)
                                dp[nxt][j-1][l+1] = max(dp[nxt][j-1][l+1], dp[cur][j][l]);
                        }
                        if(s[i] == t[1]){
                            dp[nxt][j][l] = max(dp[nxt][j][l], dp[cur][j][l] + l);
                        }else{
                            if(j > 0){
                                dp[nxt][j-1][l] = max(dp[nxt][j-1][l], dp[cur][j][l] + l);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int j = 0;j <= k;j++){
            for(int l = 0;l <= s.length();l++){
                ans = max(ans, dp[s.length()&1][j][l]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}