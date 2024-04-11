#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

vector<int> V[3030];
int m[3030];
long long S[3030];
long long ans = 0;
long long dp[3030];

void f(int s, int e, int k)
{
    if(s + 1 == e)
    {
        long long t = 0;
        for(int i = 0; i < m[s] && i <= k; ++i)
        {
            ans = max(ans, t + dp[k - i]);
            t += V[s][i];
        }
        if(m[s] <= k) ans = max(ans, t + dp[k - m[s]]);
        return;
    }

    int mid = s + e >> 1;
    long long _dp[k + 1];
    for(int i = 0; i <= k; ++i) _dp[i] = dp[i];

    for(int i = mid; i < e; ++i)
    {
        for(int j = k; j >= m[i]; --j)
            dp[j] = max(dp[j], dp[j - m[i]] + S[i]);
    }
    f(s, mid, k);

    for(int i = 0; i <= k; ++i) dp[i] = _dp[i];

    for(int i = s; i < mid; ++i)
    {
        for(int j = k; j >= m[i]; --j)
            dp[j] = max(dp[j], dp[j - m[i]] + S[i]);
    }
    f(mid, e, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> m[i];
        for(int j = 0; j < m[i]; ++j)
        {
            int x; cin >> x;
            V[i].push_back(x);
            S[i] += x;
        }
    }

    f(0, n, k);
    cout << ans;
}