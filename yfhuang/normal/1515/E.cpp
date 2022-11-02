#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 405;

int n;
int dp[2][maxn][maxn];
int inv[maxn];
int mod;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> mod;
    inv[1] = 1;
    for(int i = 2;i < maxn;i++){
        inv[i] = (mod - 1LL * (mod / i) * inv[mod % i] % mod) % mod; 
    }
    dp[0][0][0] = 1;
    for(int i = 0;i < n;i++){
        int pre = i & 1;
        int cur = pre ^ 1; 
        memset(dp[cur], 0, sizeof(dp[cur]));
        for(int j = 0;j <= i;j++){
            for(int k = 0;k <= j;k++){
                if(k == 0){
                    add(dp[cur][j+1][1], 1LL * dp[pre][j][k] * (j+1) % mod);
                }else{
                    add(dp[cur][j][0], dp[pre][j][k]);
                    add(dp[cur][j+1][k+1], 2LL * dp[pre][j][k] * (j+1) % mod * inv[k+1] % mod);
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0;j <= n;j++){
        for(int k = 1;k <= j;k++){
            add(ans, dp[n&1][j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}