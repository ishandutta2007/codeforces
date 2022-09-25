#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long llong;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

const int maxn = 100100;
const int maxb = 12;

string s;
string chs = "ATGC";

struct Fenwick {
    vector<int> t;

    Fenwick() {
    }

    Fenwick(int n): t(n) {
    }

    void put(int pos, int delta) {
        for (int i = pos; i < sz(t); i |= i + 1)
            t[i] += delta;
    }

    int get(int r) {
        int res = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1)
            res += t[i];
        return res;
    }

    int get(int l, int r) {
        r = min(r, sz(t));
        if (l >= r)
            return 0;
        return get(r) - get(l);
    }
};

Fenwick fw[maxb][maxb][4];

void upd(int pos, char c, int delta) {
    int ch = 0;
    while (chs[ch] != c)
        ++ch;
    for (int d = 1; d < maxb; ++d)
        fw[d][pos % d][ch].put(pos / d, delta);
}

void upd(int pos, char to) {
    upd(pos, s[pos], -1);
    s[pos] = to;
    upd(pos, s[pos], 1);
}

int up(int a, int b) {
    return (a + b - 1) / b;
}

int calc(int l, int r, string e) {
    int d = sz(e);
    assert(d < maxb);
    int ans = 0;
    forn (rem, d) {
        int cr = up(r - rem, d);
        int cl = up(l - rem, d);

        int epos = (rem - l % d + d) % d;
        int ch = 0;
        while (chs[ch] != e[epos])
            ++ch;
        ans += fw[d][rem][ch].get(cl, cr);
    }
    return ans;
}

int naive(int l, int r, string e) {
    int res = 0;
    for (int i = l; i < r; ++i) {
        int pos = (i - l) % sz(e);
        res += e[pos] == s[i];
    }
    return res;
}

int main() {
#ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = sz(s);
    for (int d = 1; d < maxb; ++d) {
        forn (rem, d)
            forn (ch, 4)
                fw[d][rem][ch] = Fenwick(n / d + 5);
        forn (i, n) {
            int ch = 0;
            while (chs[ch] != s[i])
                ++ch;
            fw[d][i % d][ch].put(i / d, 1);
        }
    }
    int q;
    cin >> q;
    forn (i, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char to;
            cin >> pos >> to;
            --pos;
            upd(pos, to);
        } else {
            int l, r;
            string e;
            cin >> l >> r >> e;
            --l;
            int res = calc(l, r, e);
#ifdef LOCAL
            assert(res == naive(l, r, e));
#endif
            cout << res << '\n';
        }
    }
}