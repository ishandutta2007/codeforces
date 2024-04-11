#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 505;
const int maxi = maxn * maxn;
const int zero = maxi / 2;

int dp[2][maxi];
int pre[maxi], prei[maxi];
int n, mod;
int fac[maxn], comb[maxn][maxn];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> mod;
    fac[0] = 1;
    for(int i = 1;i < maxn;i++){
        fac[i] = 1LL * fac[i-1] * i % mod;
    }
    comb[0][0] = 1;
    for(int i = 1;i < maxn;i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1;j < i;j++){
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
        }
    }
    dp[1][zero] = 1;
    int ans = 0;
    for(int i = 1;i < n;i++){
        int old = i & 1;
        int cur = old ^ 1;
        int inv = i * (i + 1) / 2; 
        pre[zero - inv - 1] = 0;
        prei[zero - inv - 1] = 0; 
        memset(dp[cur], 0, sizeof(dp[cur]));
        for(int j = -inv;j <= inv;j++){
            pre[j + zero] = dp[old][j + zero];
            prei[j + zero] = (1LL * j * dp[old][j + zero] % mod + mod) % mod; 
            add(pre[j + zero], pre[j-1 + zero]); 
            add(prei[j + zero], prei[j-1 + zero]);
        }
        for(int j = 1;j <= i + 1;j++){
            for(int k = j + 1;k <= i + 1;k++){
                int delta = k - j;
                add(ans, 1LL * comb[n][n-i-1] * fac[n-i-1] % mod * (pre[inv + zero] - pre[delta + zero] + mod) % mod);
                //cout << comb[n][n-i-1] << " " << fac[n-i-1] << " " << pre[inv + zero] << " " <<  pre[delta + zero] << endl;
                //cout << ans << endl;
            }
        }
        for(int j = -inv;j <= inv;j++){
            int coeff, tmp;
            coeff = (i + 1 - j) % mod + mod;
            int lb = max(-inv, j - i); 
            dp[cur][j + zero] = 1LL * coeff  * (pre[j + zero] - pre[lb-1 + zero] + mod) % mod;
            tmp = (prei[j + zero] - prei[lb-1 + zero] + mod) % mod;
            add(dp[cur][j + zero], tmp);
            coeff = (i + 1 + j) % mod + mod;
            int ub = min(inv, j + i);
            tmp = 1LL * coeff * (pre[ub + zero] - pre[j + zero] + mod) % mod;
            add(dp[cur][j + zero], tmp);
            tmp = (prei[j + zero] - prei[ub + zero] + mod) % mod;
            add(dp[cur][j + zero], tmp);
        }
    }
    cout << ans << '\n';
    return 0;
}