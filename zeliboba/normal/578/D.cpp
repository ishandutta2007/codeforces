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

int n, m;
ll f(const string & s) {
    ll res = 0;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] != s[i + 1]) {
            res += (m - 1) * (n - i - 1);
        }
    }
    return res;
}

ll g(const string & s) {
    ll res = 0;
    for (int i = 0; i + 1 < s.size(); ++i) if (s[i] != s[i + 1]) {
        int j = i + 1;
        while (j + 1 < s.size() && s[j + 1] == s[j - 1]) ++j;
        ll l = j - i + 1;
        res += l*(l-1) / 2;
        i = j - 1;
    }
    return res;
}

int main() {
    string s;
    cin >> n >> m >> s;
    ll res = n * (m - 1) + f(s);
    reverse(s.begin(), s.end());
    res += f(s) - g(s);
//    cerr << g(s) << endl;
    cout << res << endl;
    return 0;
}