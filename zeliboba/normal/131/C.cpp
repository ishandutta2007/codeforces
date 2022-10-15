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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

ll c(int k, int n) {
    ll res = 1;
    for (int i = 0; i < k; ++i) {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    ll res = 0;
    for (int d = 1; d <= t - 4; ++d) {
        res += c(d, m) * c(t - d, n);
    }
    cout << res << endl;
    return 0;
}