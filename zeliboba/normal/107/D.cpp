#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

const ll mod = 12345;
vi ind, modes;

vvi mul(const vvi & a, const vvi & b) {
    vvi res(a.size(), vi(a.size()));
    for (int i = 0; i < res.size(); ++i) for (int j = 0; j < res[i].size(); ++j) {
        res[i][j] = 0;
        for (int l = 0; l < res.size(); ++l)
            res[i][j] += a[i][l] * b[l][j];
        res[i][j] %= mod;
    }
    return res;
}

vvi id (int n) {
    vvi res(n, vi(n));
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;
    return res;
}

vvi mpow (vvi x, ll n) {
    vvi res = id(x.size());
    while (n) {
        if (n % 2)
            res = mul(res, x);
        n /= 2;
        x = mul(x, x);
    }
    return res;
}

vi get_rem (int tot) {
    vi res;
    for (int i = 0; i < modes.size(); ++i) {
        res.push_back(tot % modes[i]);
        tot /= modes[i];
    }
    return res;
}

int get_num (const vi & rems) {
    int res = 0;
    for (int i = modes.size() - 1; i >= 0; --i)
        res = res * modes[i] + rems[i];
    return res;
}

int main() {
    ll n, c;
    cin >> n >> c;
    vector<vi> kr(26);
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (c == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < c; ++i) {
        string s;
        int t;
        cin >> s >> t;
        kr[s[0] - 'A'].push_back(t);
    }
    int tot = 1;
    for (int i = 0; i < 26; ++i) {
        if (!kr[i].empty()) {
            ind.push_back(i);
            modes.push_back(1);
            for (int l = 0; l < kr[i].size(); ++l) {
                modes.back() *= kr[i][l];
                tot *= kr[i][l];
            }
        }
    }
    vector<vi> base(tot, vi(tot, 0));
    for (int num = 0; num < tot; ++num) {
        vi rems = get_rem(num);
        for (int i = 0; i < modes.size(); ++i) {
            rems[i] = (rems[i] + 1) % modes[i];
            ++base[get_num(rems)][num];
            rems[i] = (rems[i] + modes[i] - 1) % modes[i];
        }
    }
    vvi res = mpow(base, n);
    ll ans = 0;
    for (int i = 0; i < tot; ++i) {
        vi cur = get_rem(i);
        for (int l = 0; l < modes.size(); ++l) {
            bool ok = 0;
            for (int j = 0; j < kr[ind[l]].size(); ++j)
                if (cur[l] % kr[ind[l]][j] == 0)
                    ok = 1;
            if (!ok)
                res[i][0] = 0;
        }
        ans += res[i][0];
    }
    cout << ans % mod << endl;
    return 0;
}