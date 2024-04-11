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
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int p = 131;
const int mod = 999999937;

vvl hash0 (const string & s) {
    int n = s.size();
    vvl h(26, vl(n + 1));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            h[j][i] = h[j][i+1]*p;
        }
        h[s[i]-'a'][i] += 1;
    }
    return h;
}

vvl hash1 (const string & s) {
    int n = s.size();
    vvl h(26, vl(n + 1));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            h[j][i] = (h[j][i+1]*p) % mod;
        }
        h[s[i]-'a'][i] = (h[s[i]-'a'][i] + 1) % mod;
    }
    return h;
}

ll cut(ll x) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

int main() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vi ct(26);
    vvi cs(26, vi(n + 1));
    for (int i = 0; i < t.size(); ++i) ct[t[i] - 'a']++;
    for (int i = 0; i < s.size(); ++i) {
        for (int a = 0; a < 26; ++a) cs[a][i+1] = cs[a][i];
        cs[s[i]-'a'][i+1]++;
    }
    vvl hs0 = hash0(s);
    vvl ht0 = hash0(t);
    vl pw0(1000000, 1);
    for (int i = 1; i < pw0.size(); ++i) pw0[i] = pw0[i-1] * p;
    vvl hs = hash1(s);
    vvl ht = hash1(t);
    vl pw(1000000, 1);
    for (int i = 1; i < pw.size(); ++i) pw[i] = pw[i-1] * p % mod;
    vi pos(26, -1);
    for (int i = 0; i < t.size(); ++i) pos[t[i]-'a'] = i;
    vi res;
    for (int j = 0; j + t.size() <= s.size(); ++j) {
        vi x(26);
        vi was(26, -1);
        bool fail = 0;
        for (int i = 0; i < 26; ++i) if (pos[i] >= 0) {
            x[i] = s[j + pos[i]] - 'a';
            if (was[x[i]] != -1) {
                fail = 1;
                break;
            }
            was[x[i]] = i;
        }
        for (int i = 0; i < 26; ++i) if (pos[i] >= 0) {
            if (pos[x[i]] >= 0 && x[x[i]] != i) {
                fail = 1;
                break;
            }
        }
        if (fail) continue;
        for (int i = 0; i < 26; ++i) if (pos[i] >= 0) {
            if (ht0[i][0] != hs0[x[i]][j] - hs0[x[i]][j + m] * pw0[m] ||
                ht[i][0] != cut(hs[x[i]][j] - hs[x[i]][j + m] * pw[m]) ||
                ct[i] != cs[x[i]][j+m] - cs[x[i]][j]) {
                fail = 1;
                break;
            }
        }
        if (!fail) res.push_back(j + 1);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) cout << res[i] << ' ';
    return 0;
}