#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const ll p = 131;

vii f(const string & s) {
    vl h;
    for (int i = 0; i < s.size(); ++i) {
        ll cur = 0;
        for (int j = i; j < s.size(); ++j) {
            cur = cur * p + s[j];
            h.push_back(cur);
        }
    }
    sort(h.begin(), h.end());
    vii res(1, pii(h[0], 1));
    for (int i = 1; i < h.size(); ++i) {
        if (h[i] == h[i-1])
            ++res.back().second;
        else res.push_back(pii(h[i], 1));
    }
    return res;
}

int main() {
    vl pw(2005, 1);
    for (int i = 1; i < pw.size(); ++i)
        pw[i] = pw[i-1] * p;
    string s;
    int n;
    cin >> s >> n;
    vii all = f(s);
    vi ok(all.size(), 1);
    for (int ii = 0; ii < n; ++ii) {
        string v;
        int l,r;
        cin >> v >> l >> r;
        vii cur = f(v);
//        cerr << cur.size() << endl;
        for (int i = 0; i < all.size(); ++i) if (ok[i]) {
            int it = lower_bound(cur.begin(), cur.end(), pii(all[i].first, 0)) - cur.begin();
            if (it < cur.size() && all[i].first == cur[it].first) {
//                cerr << all[i].first << ' ' << cur[it].first << endl;
                if (cur[it].second < l || cur[it].second > r)
                    ok[i] = 0;
            } else {
                if (l > 0)
                    ok[i] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < ok.size(); ++i)
        cnt += ok[i];
    cout << cnt << endl;
    return 0;
}