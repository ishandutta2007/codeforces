#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("c.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

map <int, int> m;

int solve()
{
    int n, k;
    cin >> n >> k;
    m[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        for (int j = 1; j <= k; ++j)
        {
            if (m.count(a * j))
                m[a * j] = min(m[a * j], j);
            else
                m[a * j] = j;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int val;
        cin >> val;
        auto it = m.end();
        --it;
        int ans = INF;
        for (auto x: m)
        {
            while (it != m.begin() && it->first + x.first > val)
                --it;
            if (it->first + x.first == val)
                ans = min(ans, it->second + x.second);
        }
        if (ans > k)
            ans = -1;
        cout << ans << '\n';
    }
    return 0;
}