#include <iostream>
#include <vector>
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

const int Q = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m; cin >> n >> k >> m;
    vector<pii> qr[n];
    for(int i = 0; i < m; ++i)
    {
        int l, r, x; cin >> l >> r >> x; --l; --r;
        qr[l].push_back({r, x});
    }

    int ans = 1;
    for(int w = 0; w < k; ++w)
    {
        pii dp[n + 1]{}; dp[n] = {1, 0};
        int mn = 0, con = -1;
        for(int i = 0; i < n; ++i)
        {
            ++dp[n].ss;
            for(auto &y : qr[i])
            {
                if(y.ss >> w & 1)
                    con = max(con, y.ff);
                else
                    dp[y.ff] = dp[n];
            }
            if(i > con) dp[n].ff = (Q + (2 * dp[n].ff) % Q - mn) % Q;
            if(dp[i + 1].ss < dp[i].ss) dp[i + 1] = dp[i];
            mn = dp[i].ff;
        }
        ans = 1ll * ans * ((Q + dp[n].ff - mn) % Q) % Q;
    }

    cout << ans;
    return 0;
}