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
#include <cstring>

using namespace std;

typedef long long ll;

const int MN = 100100;
const ll MD = 1e9+7;

int n;
vector<int> g[MN];
ll res[MN][2];
void solve(int p) {
    for (int d: g[p]) {
        solve(d);
    }
    ll l[2] = {};
    l[0] = 1;
    for (int d: g[p]) {
        auto &r = res[d];
        int ll[2];
        ll[0] = r[0]*l[0]%MD + r[1]*l[1]%MD;
        ll[1] = r[0]*l[1]%MD + r[1]*l[0]%MD;
        l[0] = ll[0]%MD;
        l[1] = ll[1]%MD;
    }
    ll k = 1;
    for (int d: g[p]) {
        k *= res[d][0];
        k %= MD;
    }
    ll m[2] = {};
    m[0] = 1;
    for (int d: g[p]) {
        ll mm[2];
        auto &r = res[d];
        mm[0] = m[0] + m[1]*r[1]%MD;
        mm[1] = m[1] + m[0]*r[1]%MD;
        m[0] = mm[0]%MD;
        m[1] = mm[1]%MD;
    }
    res[p][0] = ((l[1]*2+1 - m[1])%MD + MD) % MD;
    res[p][1] = ((l[0]*2 - k)%MD + MD) % MD;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int d;
        cin >> d; d--;
        g[d].push_back(i);
    }
    solve(0);
    cout << (res[0][0]+res[0][1]-1+MD)%MD << endl;
}