#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 105;
int a[maxn];
int n;
vector<string> res;

string gen(vector<int> pos) {
    string res(n, '0');
    for (int i: pos)
        res[i] = '1';
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    cin >> n;
    forn (i, n)
        cin >> a[i];
    while (true) {
        int x = max_element(a, a + n) - a;
        int mx = a[x];
        a[x] = -1;
        int y = max_element(a, a + n) - a;
        a[x] = mx;

        int mn = *min_element(a, a + n);

        if (mx == mn)
            break;

        if (mn == mx - 1) {
            vector<int> z;
            forn (i, n) {
                if (i == x || i == y)
                    continue;
                if (a[i] == mx)
                    z.push_back(i);
            }
            if (sz(z) == 1) {
                res.push_back(gen({x, y, z[0]}));
                --a[x], --a[y], --a[z[0]];
                break;
            }
        }

        res.push_back(gen({x, y}));
        a[x] = max(a[x] - 1, 0);
        a[y] = max(a[y] - 1, 0);
    }
    forn (i, n - 1)
        assert(a[i] == a[i + 1]);
    assert(a[0] >= 0);
    cout << a[0] << '\n';
    assert(sz(res) <= 10000);
    cout << sz(res) << '\n';
    for (auto s: res)
        cout << s << '\n';
}