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

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const ll MK = 1001000;
ll x[MK], y[MK];
ll da[1100][1100];
int main() {
    ll n, m, k, p;
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> da[i][j];
        }
    }
    priority_queue<ll> qx, qy;
    for (int i = 0; i < n; i++) {
        int u = 0;
        for (int j = 0; j < m; j++) {
            u += da[i][j];
        }
        qx.push(u);
    }
    for (int j = 0; j < m; j++) {
        int u = 0;
        for (int i = 0; i < n; i++) {
            u += da[i][j];
        }
        qy.push(u);
    }
    x[0] = 0;
    for (int i = 1; i < MK; i++) {
        ll u = qx.top(); qx.pop();
        x[i] = x[i-1]+u;
        qx.push(u-m*p);
    }
    y[0] = 0;
    for (int i = 1; i < MK; i++) {
        ll u = qy.top(); qy.pop();
        y[i] = y[i-1]+u;
        qy.push(u-n*p);
    }
    ll res = -(1LL<<62);
    for (int i = 0; i <= k; i++) {
        ll r = x[i]+y[k-i];
        r -= i*(k-i)*p;
        res = max(res, r);
    }
    cout << res << endl;
    return 0;
}