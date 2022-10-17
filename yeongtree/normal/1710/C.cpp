#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <string>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int MOD = 998'244'353;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();

    int dp[200'005][8][8]{};
    dp[0][0][0] = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            for(int k = 0; k < 8; ++k)
            {
                for(int l = 0; l < 8; ++l) if(s[i] != '0' || ((j | l) == j))
                {
                    int jj;
                    if(s[i] == '0') jj = j;
                    else jj = (j | (7 - l));
                    int kk = k;
                    if(l == 1 || l == 6) kk |= 1;
                    if(l == 2 || l == 5) kk |= 2;
                    if(l == 3 || l == 4) kk |= 4;
                    dp[i + 1][jj][kk] = (dp[i + 1][jj][kk] + dp[i][j][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j < 8; ++j) ans = (ans + dp[n][j][7]) % MOD;
    cout << ans;
}