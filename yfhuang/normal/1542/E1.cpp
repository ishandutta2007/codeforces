#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;


int n, mod;
const int maxn = 505;
int dp[maxn][maxn * maxn / 2];
int pre[maxn][maxn * maxn / 2];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

void sub(int &a, int b){
    a -= b;
    if(a < 0)
        a += mod;
}

void init(){
    dp[1][0] = 1;
    for(int i = 2;i <= n;i++){
        for(int j = 0;j <= i * (i - 1) / 2;j++){
            add(dp[i][j], dp[i-1][j]);
            if(j > 0)
                add(dp[i][j], dp[i][j-1]);
            if(j >= i)
                sub(dp[i][j], dp[i-1][j-i]);
            pre[i][j] = dp[i][j];
            if(j > 0)
                add(pre[i][j], pre[i][j-1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> mod;
    init();
    int val = 1;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int delta = 1;delta + 1 <= n + 1 - i;delta++){
            int len = n - i;
            int tmp = 0;
            for(int i = delta+1;i <= len * (len - 1) / 2;i++){
                add(tmp, 1LL * dp[len][i] * pre[len][i-delta-1] % mod);
            }
            add(ans, 1LL * (len + 1 - delta) * tmp % mod * val % mod);
        }
        val = 1LL * val * (n + 1 - i) % mod;
    }
    cout << ans << endl;
    return 0;
}