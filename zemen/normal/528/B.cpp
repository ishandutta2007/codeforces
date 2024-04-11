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
    freopen("b.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

vector <pair <int, int> > e;

int solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, w;
        cin >> x >> w;
        e.emplace_back(x + w, x - w);
    }
    sort(e.begin(), e.end());
    int res = 0, rb = -INF;
    for (int i = 0; i < n; ++i)
    {
        if (e[i].second >= rb)
        {
            ++res;
            rb = e[i].first;
        }
    }
    cout << res << '\n';
    return 0;
}