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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, k;
    cin >> n >> k;
    vi q(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        --q[i];
    }
    bool bad = 1;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        --s[i];
        if (s[i] != i)
            bad = 0;
    }
    if (bad) {
                cout << "NO\n";
                return 0;
    }
    vi r(n), m(n);
    for (int i = 0; i < n; ++i) {
        m[i] = 1;
        if (q[i] == i) {
            if (s[i] != i) {
                cout << "NO\n";
                return 0;
            }
            continue;
        }
        int cur = q[i];
        while (cur != i) {
            if (cur == s[i])
                r[i] = m[i];
            ++m[i];
            cur = q[cur];
        }
        if (r[i] == 0 && s[i] != i) {
            cout << "NO\n";
            return 0;
        }
//        cerr << r[i] << " " << m[i] << endl;
    }
    for (int t = k % 2; t <= k; t += 2) {
        bool ok1 = 1, ok2 = 1;
        for (int i = 0; i < n; ++i) {
            if ((t - r[i]) % m[i])
                ok1 = 0;
            if ((-t - r[i]) % m[i])
                ok2 = 0;
        }
//        cerr << t << " " << (int)ok1 << " " << (int)ok2 << endl;
        if (ok1 || ok2) {
            if (t == 0) {
                cout << "NO\n";
                return 0;
            }
            if (t == 1 && ok1 && ok2 && k != 1) {
                cout << "NO\n";
                return 0;
            }
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}