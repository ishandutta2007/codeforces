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
#include <unordered_map>
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

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vi l(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    int d = l[0];
    for (int i = 0; i < n; ++i) {
        d = gcd(d, l[i]);
    }
    for (int i = 0; i < n; ++i) cin >> c[i];
    if (d > 1) {
        cout << -1 << endl;
        return 0;
    }
    unordered_map<int, int> v;
    v[0] = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> nv = v;
        for (auto it : v) {
            int x = it.first;
//            cerr << i << ' ' << x << ' ' << it.second << endl;
            int nx = gcd(x, l[i]);
            int cost = it.second + c[i];
            if (!nv.count(nx)) {
                nv[nx] = cost;
            } else {
                nv[nx] = min(nv[nx], cost);
            }
        }
        v.swap(nv);
    }
    cout << v[1] << endl;
    return 0;
}