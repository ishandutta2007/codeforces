#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[1010];
int dp[1010][1010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr + n);
        for(int i = 0; i <= n; ++i) for(int j = 0; j <= 2 * n; ++j) dp[i][j] = (int)1e9;
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            int mn = dp[i - 1][0];
            for(int j = 1; j <= 2 * n; ++j)
            {
                mn = min(mn, dp[i - 1][j - 1]);
                dp[i][j] = mn + abs(arr[i - 1] - j);
            }
        }
        int ans = (int)1e9;
        for(int i = 0; i <= 2 * n; ++i) ans = min(ans, dp[n][i]);
        cout << ans << '\n';
    }
}