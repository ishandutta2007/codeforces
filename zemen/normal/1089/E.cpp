#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

string to(int x, int y) {
    return string(1, 'a'+x) + string(1, '1'+y);
}

int b[8][8];
vector<pii> st;

void nxt(int &x, int &y) {
    if (y == 7) ++x, y = 0;
    else ++y;
}

bool go(int x, int y, int rem) {
    if (x == 7 && y == 7) {
        if (rem == 0) {
            return true;
        } else {
            return false;
        }
    }

    if (rem == 0) return false;

    int sx = x, sy = y;
    x = 0;
    y = 0;

    while (true) {
        nxt(x, y);
        if (b[x][y] == 0 && (x == sx || y == sy)) {
            st.emplace_back(x, y);
            b[x][y] = 1;
            if (go(x, y, rem-1)) return true;
            b[x][y] = 0;
            st.pop_back();
        }
        if (x == 7 && y == 7) break;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif

    int n;
    cin >> n;

    st.emplace_back(0, 0);
    assert(go(0, 0, n));

    for (auto p : st) {
        cout << to(p.fi, p.se) << " ";
    }
    cout << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}