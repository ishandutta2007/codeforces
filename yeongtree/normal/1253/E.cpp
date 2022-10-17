#include <iostream>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

const int INF = (int)2e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    pii arr[n]; for(auto &i : arr) {cin >> i.ff >> i.ss; --i.ff;}
    sort(arr, arr + n);

    int dp[m + 1][n + 1]{};
    for(int i = 0; i < m; ++i)
    {
        dp[i + 1][0] = i + 1;
        for(int j = 0; j < n; ++j)
        {
            int l = max(arr[j].ff - arr[j].ss, 0);
            int r = min(arr[j].ff + arr[j].ss, m - 1);
            if(i < l) dp[i + 1][j + 1] = dp[i + 1][j];
            else if(i <= r) dp[i + 1][j + 1] = dp[l][j];
            else dp[i + 1][j + 1] = min(dp[i + 1][j], dp[max(0, l + r - i)][j] + i - r);
        }
    }

    cout << dp[m][n];
    return 0;
}