#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

struct Pair {
    int a, b;

    bool operator<(const Pair &c) const {
        return a + b < c.a + c.b;
    }
};

vector<Pair> v;

int main() {
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    ll score = 0;
    forn (i, n) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if (a1 <= b2 && a2 >= b1)
            continue;
        if (a1 + b1 >= a2 + b2) {
            v.push_back(Pair{a1, b1});
            v.push_back(Pair{a2, b2});
        } else if (a1 <= b2) {
            score += a2 - b1;
        } else if (a2 >= b1) {
            score += a1 - b2;
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    forn (i, sz(v)) {
        if (i % 2 == 0)
            score += v[i].a;
        else
            score -= v[i].b;
    }
    cout << score << '\n';
}