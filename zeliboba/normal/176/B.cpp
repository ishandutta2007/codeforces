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

int d (int i, int n) {
    if (i < n)
        return i;
    return i - n;
}

const ll mod = 1000000007;

int main() {
    int k;
    string s1,s2;
    cin >> s1 >> s2 >> k;
    int n = s1.size();
    if (k == 0) {
        cout << (int)(s1 == s2) << endl;
        return 0;
    }
    int cnt = 0;
    for (int t = 0; t < s1.size(); ++t) {
        bool ok = 1;
        for (int i = 0; i < s1.size(); ++i) if (s2[i] != s1[d(i + t, n)]) {
            ok = 0;
            break;
        }
        cnt += ok;
    }
    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll d0 = (s1 == s2);
    ll d1 = 1 - d0;
    for (int i = 0; i < k; ++i) {
        ll n0 = (d1 * cnt + d0 * (cnt - 1)) % mod;
        ll n1 = (d0 * (n - cnt) + d1 * (n - cnt - 1)) % mod;
        swap(d0, n0);
        swap(d1, n1);
    }
    cout << d0 << endl;
    return 0;
}