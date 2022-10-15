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

int main() {
    int n, t;
    cin >> n >> t; --t;
    vi a(n-1);
    for (int i = 0; i < a.size(); ++i) cin >> a[i];
    int cur = 0;
    while (cur <= t) {
        if (cur == t) {
            cout << "YES\n";
            return 0;
        }
        cur += a[cur];
    }
    cout << "NO\n";
    return 0;
}