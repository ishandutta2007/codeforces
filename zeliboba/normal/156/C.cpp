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

ll mod = 1000000007;

int d(int x) {
    if (x < mod)
        return x;
    return x - mod;
}

int main() {
//    mod *= mod;
    int T;
    vector<vl> c(3000, vl(3000));
    for (int i = 0; i < c.size(); ++i)
        c[0][i] = 1;
    for (int i = 1; i < c.size(); ++i)
        for (int j = 1; j <= i; ++j)
            c[j][i] = d(c[j][i - 1] + c[j - 1][i - 1]);
/*    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)
            cout << c[j][i] << " ";
        cout << endl;
    }*/
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        string s;
        cin >> s;
        int n = s.size(), sum = 0;
        for (int i = 0; i < n; ++i)
            sum += s[i] - 'a';
//        cerr << sum << endl;
        ll res = 0, m = 1;
        for (int i = 0; i <= n && i * 26 <= sum; ++i) {
            res += m * c[i][n] * c[n - 1][n - 1 + sum - i * 26] % mod;
            m = -m;
        }
//        cout << res << endl;
        cout << (res % mod + mod - 1) % mod << endl;
    }
    return 0;
}