#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second

vector<pii> ps;

const int INF = 0x3f3f3f3f;
const pii _no = make_pair(-1, -1);

pii can(int mid) {
    int x1 = 1, x2 = INF;
    int y1 = 0, y2 = INF;
    for (pii p: ps) {
        x1 = max(x1, max(0, p.F - mid));
        x2 = min(x2, p.F + mid);
        y1 = max(y1, max(0, p.S - mid));
        y2 = min(y2, p.S + mid);
    }
    if (x1 <= x2 && y1 <= y2) {
        int ll = x1 - y2;
        int rr = x2 - y1;
        for (pii p: ps) {
            ll = max(ll, p.F - p.S - mid);
            rr = min(rr, p.F + mid - p.S);
        }
        if (ll <= rr) {
            for (int x = x1; x <= x2; ++x) {
                int y = x - ll;
                if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                    return make_pair(x, y);
                }
            }
        }
    }
    x1 = 0, x2 = INF;
    y1 = 1, y2 = INF;
    for (pii p: ps) {
        x1 = max(x1, max(0, p.F - mid));
        x2 = min(x2, p.F + mid);
        y1 = max(y1, max(0, p.S - mid));
        y2 = min(y2, p.S + mid);
    }
    if (x1 <= x2 && y1 <= y2) {
        int ll = x1 - y2;
        int rr = x2 - y1;
        for (pii p: ps) {
            ll = max(ll, p.F - p.S - mid);
            rr = min(rr, p.F + mid - p.S);
        }
        if (ll <= rr) {
            for (int x = x1; x <= x2; ++x) {
                int y = x - ll;
                if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                    return make_pair(x, y);
                }
            }
        }
    }
    return _no;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int c1 = 0, c2 = 0;
        for (char c: s) {
            c1 += (c == 'B');
            c2 += (c == 'N');
        }
        ps.push_back(make_pair(c1, c2));
        // cerr << "( " << c1 << " , " << c2 << " )" << endl;
    }
    int l = -1, r = 2001001;
    while (r - l != 1) {
        int mid = (l + r) >> 1;
        if (can(mid) != _no) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << endl;
    pii ret = can(r);
    // cerr << "ret.F = " << ret.F << " , ret.S = " << ret.S << endl;
    while (ret.F--) cout << 'B';
    while (ret.S--) cout << 'N';
    cout << '\n';
}