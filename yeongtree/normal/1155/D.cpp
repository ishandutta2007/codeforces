#include <iostream>
#include <vector>

using namespace std;

inline int max(int x, int y) {return (x > y ? x : y);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a; cin >> n >> a;
    long long arr[n]; for(int i = 0; i < n; ++i) cin >> arr[i];
    long long sum[n + 1]; sum[0] = 0; for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + arr[i - 1];

    long long dp[n + 1]{};
    int pow[4] = {-1, 1 - a, a - 1, 1};

    for(int i = 0; i < 4; ++i)
        for(int j = 1; j <= n; ++j)
            dp[j] = max(dp[j - 1], dp[j] + pow[i] * sum[j]);

    cout << dp[n];
    return 0;
}