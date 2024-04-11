#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>

using namespace std;

typedef long long ll;

const int MN = 1001000;

int n;
ll a[MN];
vector<int> v;
ll dp[MN];
bool used[MN];
ll solve(int p) {
    auto it = upper_bound(v.begin(), v.end(), p);
    if (it == v.end()) return 0;
    if (used[p]) return dp[p];
    used[p] = true;
    int d = *it;
    dp[p] = max(abs(a[p]-a[d-1]) + solve(d),
        abs(a[p]-a[d]) + solve(d+1));
    return dp[p];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n-1; i++) {
        int x = a[i-1], y = a[i], z = a[i+1];
        bool f = false;
        if (y == z) {
            f = true;
        }
        if (x <= y && y > z) {
            f = true;
        }
        if (x >= y && y < z) {
            f = true;
        }
        if (f) {
            v.push_back(i);
        }
    }
    v.push_back(n-1);
    cout << solve(0) << endl;
    return 0;
}