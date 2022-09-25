#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
const int k = 30;
int a[maxn];

bool b(int x, int c) {
    return (x >> c) & 1;
}

set<int> S;
int n;

bool check(int C) {
    S.clear();
    forn (i, n) {
        int x = a[i];
        while (x && (x > C || S.count(x)))
            x /= 2;
        if (x == 0)
            return true;
        S.insert(x);
    }
    return false;
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    cin >> n;
    forn (i, n)
        cin >> a[i];
    int L = 0, R = 1e9;
    while (L + 1 < R) {
        int C = (L + R) / 2;
        if (check(C))
            L = C;
        else
            R = C;
    }
    assert(!check(R));
    for (int x: S)
        cout << x << ' ';
    cout << '\n';
}