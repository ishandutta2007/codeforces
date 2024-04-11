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
const int mod = 1000000007;

int main() {
    vvl c(2001, vl(2001));
    c[0].assign(c[0].size(), 1);
    for (int i = 1; i < c.size(); ++i) for (int j = 1; j <= i; ++j) {
        c[j][i] = c[j-1][i-1] + c[j][i-1];
        if (c[j][i] >= mod) c[j][i] -= mod;
    }
    int k;
    cin >> k;
    vi v(k);
    for (int i = 0; i < k; ++i) cin >> v[i];
    ll res = 1, sum = v[0] - 1;
    for (int i = 1; i < k; ++i) {
        sum += v[i];
        res = res * c[v[i] - 1][sum] % mod;
    }
    cout << res << endl;
    return 0;
}