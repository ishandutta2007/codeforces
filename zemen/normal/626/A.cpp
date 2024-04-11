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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
map<char, int> mp;

int solve()
{
    mp['U'] = 0;
    mp['D'] = 1;
    mp['L'] = 2;
    mp['R'] = 3;
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    forn (r, n + 1)
        forn (l, r)
        {
            int x = 0, y = 0;
            forab (i, l, r)
            {
                int dir = mp[s[i]];
                x += dx[dir], y += dy[dir];
            }
            if (x == 0 && y == 0)
                ++res;
        }
    cout << res << '\n';
    return 0;
}