#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll calc(ll i) {
    if (i%2) {
        return i*(i-1)/2+1;
    }
    ll u = i/2-1;
    return i*(i-1)/2+u+1;
}
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v;
    for (int i = 0; i < m; i++) {
        ll q, w;
        cin >> q >> w;
        v.push_back(w);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ma;
    ll r = 0;
    for (ma = 1; ma <= m; ma++) {
        if (n < calc(ma)) break;
        r += v[ma-1];
    }
    cout << r << endl;
    return 0;
}