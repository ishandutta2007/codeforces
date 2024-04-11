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
    freopen("a.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

map <string, int> m;

int solve()
{
    int n;
    cin >> n;
    m["polycarp"] = 1;
    int best = 1;
    for (int i = 0; i < n; ++i)
    {
        string s, r, t;
        cin >> s >> r >> t;
        assert(r == "reposted");
        for (char &c: s)
            if (!islower(c))
                c = tolower(c);
        for (char &c: t)
            if (!islower(c))
                c = tolower(c);
        assert(m.count(t));
        assert(!m.count(s));
        m[s] = m[t] + 1;
        best = max(best, m[s]);
    }
    cout << best << '\n';
    return 0;
}