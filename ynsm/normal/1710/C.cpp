#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500, inf = 1e9, mod = 998244353;

int sum(int a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}
int mult(int a, int b){
    return 1ll * a * b % mod;
}
int bp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int x){
    return bp(x, mod - 2);
}

int dp[N][8][8], ans;
string s;

void solve() {
    cin >> s;
    dp[0][7][7] = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < (1 << 3); j++) {
            for (int q = 0; q < (1 << 3); q++) {
                for (int w = 0; w < (1 << 3); w++) {
                    if (s[i] == '0' && (q & w) != 0)
                        continue;
                    int nq;
                    if (s[i] == '1')
                        nq = (w & q);
                    else
                        nq = q;
                    int nj = j, cnt = __builtin_popcount(w);
                    if(cnt == 1)
                        nj &= (7 ^ w);
                    if(cnt == 2)
                        nj &= w;
                    dp[i + 1][nj][nq] = sum(dp[i + 1][nj][nq], dp[i][j][q]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << 3); i++)
        ans = sum(ans, dp[s.size()][0][i]);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}