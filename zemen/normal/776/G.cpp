#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 20;
ll d[maxn][2][2];

void udd(ll &a, ll b) {
    a += b;
}

ll solve(vector<int> s) {
    if (s.empty())
        return 0;

    int n = sz(s);
    reverse(s.begin(), s.end());
    ll res = 0;
    for (int maxv = 1; maxv < 16; ++maxv) {
        int pos = n - maxv / 4 - 1;
        int bit = 1 << (maxv % 4);
        if (pos < 0)
            break;
        memset(d, 0, sizeof(d));
        d[0][0][1] = 1;

        forn (len, n)
            forn (was, 2)
                forn (eq, 2) {
                    ll val = d[len][was][eq];
                    if (val == 0)
                        continue;

                    for (int dig = 0; dig <= maxv; ++dig) {
                        if (eq && dig > s[len])
                            break;
                        if (len == pos && !(dig & bit))
                            continue;
                        int nwas = was || (dig == maxv);
                        int neq = eq && (dig == s[len]);
                        udd(d[len + 1][nwas][neq], val);
                    }
                }
        forn (eq, 2)
            udd(res, d[n][1][eq]);
    }
    return res;
}

void dec(vector<int> &s) {
    if (s.empty())
        return;
    --s[0];
    int pos = 0;
    while (s[pos] < 0) {
        s[pos] += 16;
        ++pos;
        s[pos]--;
    }
}

vector<int> dig(string s) {
    reverse(s.begin(), s.end());
    vector<int> res;
    forn (i, sz(s)) {
        if (isdigit(s[i]))
            res.push_back(s[i] - '0');
        else
            res.push_back(s[i] - 'a' + 10);
    }
    while (!res.empty() && res.back() == 0)
        res.pop_back();
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
    #else
    #endif
    int q;
    cin >> q;
    forn (i, q) {
        string l, r;
        cin >> l >> r;
        vector<int> L = dig(l);
        vector<int> R = dig(r);
        dec(L);

        //cerr << "l: ";
        //forn (i, sz(L))
            //cerr << L[i] << ' ';
        //cerr << '\n';
        //cerr << "r: ";
        //forn (i, sz(R))
            //cerr << R[i] << ' ';
        //cerr << '\n';

        cout << solve(R) - solve(L) << '\n';
    }
}