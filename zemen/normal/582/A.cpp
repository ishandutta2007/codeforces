#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

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
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int gcd(int a, int b)
{
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    forn (i, n * n)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    vector<int> ans;
    while (sz(ans) < n)
    {
        auto it = std::prev(m.end());
        assert(it->second > 0);
        int val = it->first;
        assert(m[val] > 0);
        m[val]--;
        if (m[val] == 0)
            m.erase(val);
        for (auto x: ans)
            {
                int g = gcd(val, x);
                assert(m[g] > 1);
                m[g] -= 2;
                if (m[g] == 0)
                    m.erase(g);
            }
        ans.push_back(val);
    }
    for (int x: ans)
        cout << x << ' ';
    cout << '\n';
    return 0;
}