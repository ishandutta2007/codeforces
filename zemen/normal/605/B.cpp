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
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 100100;
bool type[maxn];
int w[maxn];

vector<pair<int, int>> available;
pair<int, int> g[maxn];

bool cmp(int a, int b)
{
    if (w[a] != w[b])
        return w[a] < w[b];
    return type[a] > type[b];
}

int solve()
{
    int N, m;
    cin >> N >> m;
    vector<int> e;
    forn (i, m)
    {
        int w, t;
        cin >> w >> t;
        e.push_back(i);
        type[i] = t;
        ::w[i] = w;
    }
    sort(e.begin(), e.end(), cmp);
    int n = 1;
    for (int id: e)
    {
        if (type[id] == 1)
        {
            g[id] = {n - 1, n};
            forn (u, n - 1)
            {
                if (sz(available) > maxn * 2)
                    break;
                available.emplace_back(u, n);
            }
            ++n;
        }
        else
        {
            if (available.empty())
            {
                cout << -1 << '\n';
                return 0;
            }
            g[id] = available.back();
            available.pop_back();
        }
    }
    assert(n == N);
    forn (i, m)
        cout << g[i].first + 1 << ' ' << g[i].second + 1 << '\n';
    return 0;
}