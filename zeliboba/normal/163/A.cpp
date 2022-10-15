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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

const ll mod = 1000000007;

int d (int x) {
    if (x < mod)
        return x;
    else return x - mod;
}

int main() {
    string s, t;
    cin >> s >> t;
    ll res = 0;
    vector<vi> dyn(t.size() + 1, vi(s.size() + 1));
    for (int i = 0; i <= s.size(); ++i)
        dyn[0][i] = 1;
    for (int i = 0; i < t.size(); ++i) {
        dyn[i + 1][0] = 1;
        for (int j = 0; j < s.size(); ++j) {
            dyn[i + 1][j + 1] = dyn[i][j + 1];
            if (s[j] == t[i])
                dyn[i + 1][j + 1] = d(dyn[i + 1][j + 1] + dyn[i][j]);
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        res = d(res + dyn.back()[i + 1] - 1);
    }
    cout << res << endl;
    return 0;
}