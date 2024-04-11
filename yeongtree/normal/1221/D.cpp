#include <iostream>
#include <utility>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#include <algorithm>
#include <queue>

using namespace std;

struct cmp
{
    bool operator() (const pii &x, const pii &y) {return x.ss < y.ss;}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        pii arr[n]; for(auto &i : arr) cin >> i.ff >> i.ss;

        long long dp[n][3]; for(auto &i : dp) for(auto &j : i) j = 2e18;
        dp[0][0] = 0; dp[0][1] = arr[0].ss; dp[0][2] = arr[0].ss * 2;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                for(int k = 0; k < 3; ++k)
                {
                    if(arr[i - 1].ff + j == arr[i].ff + k) continue;
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + arr[i].ss * k);
                }
            }
        }

        long long ans = 2e18;
        for(int i = 0; i < 3; ++i) ans = min(ans, dp[n - 1][i]);
        cout << ans << '\n';
    }

    return 0;
}