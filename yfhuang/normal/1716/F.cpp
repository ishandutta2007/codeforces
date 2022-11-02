#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int mod = 998244353;

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

int n, m, k;
const int maxn = 2005;
int dp[maxn][maxn];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

void init(){
    dp[0][0] = 1;
    for(int i = 1;i < maxn ;i++){
        for(int j = 0;j < maxn;j++){
            dp[i][j] = 1LL * dp[i-1][j] * j % mod;
            if(j > 0){
                add(dp[i][j], dp[i-1][j-1]); 
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    init();
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        int ans = 0;
        int val = 1;
        for(int i = 0;i <= min(n, k);i++){
            add(ans, 1LL * dp[k][i] * val % mod * qpow((m + 1) / 2, i) % mod * qpow(m, n - i) % mod);
            val = 1LL * val * (n - i) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}