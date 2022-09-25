#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

vector<int> res;
vector<char> ch;

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif

    string token;
    cin >> token;
    assert(token == "?");
    ch.push_back('+');

    while (cin >> token) {
        if (token == "=")
            break;
        ch.push_back(token[0]);
        cin >> token;
        assert(token == "?");
    }
    ll s;
    cin >> s;

    ll vmin = 0, vmax = 0;
    int n = sz(ch);
    for (auto c: ch)
        if (c == '+') {
            vmin += 1;
            vmax += s;
        } else {
            vmin -= s;
            vmax -= 1;
        }
    if (vmin > s || vmax < s) {
        cout << "Impossible\n";
        return 0;
    }
    cout << "Possible\n";
    forn (i, n) {
        int val = 1;
        if (ch[i] == '+') {
            vmax -= s - 1;
            if (vmax < s) {
                int delta = s - vmax;
                val += delta;
                vmin += delta;
                vmax += delta;
            }
        } else {
            vmin += s - 1;
            if (vmin > s) {
                int delta = vmin - s;
                val += delta;
                vmin -= delta;
                vmax -= delta;
            }
        }
        res.push_back(val);
    }
    forn (i, n) {
        if (i)
            cout << ch[i] << ' ';
        cout << res[i] << ' ';
    }
    cout << "= " << s << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}