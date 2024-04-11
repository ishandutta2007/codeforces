#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long a, b, c, d; cin >> n >> a >> b >> c >> d;
    long long A[n]; for(auto &i : A) cin >> i;
    long long dp[n + 1]{}; dp[0] = -d;
    for(int i = 0; i < n; ++i)
    {
        dp[i + 1] = dp[i] + min(A[i] * a + c, min(b + a, (A[i] + 2) * a) + 2 * d) + d;
        if(i > 0)
        {
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + min(b + a, (A[i] + 2) * a) + min(b + a, (A[i - 1] + 2) * a) + 4 * d);
        }
    }

    long long ans = dp[n];
    long long cnt = A[n - 1] * a + c + d;
    for(int i = n - 2; i >= 0; --i)
    {
        cnt += 2 * d + min((A[i] + 2) * a, min(A[i] * a + c, b + a));
        ans = min(ans, dp[i] + cnt);
    }

    cout << ans;
}