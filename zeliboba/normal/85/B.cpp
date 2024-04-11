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
typedef vector<ll> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;


void out(const vi & v) {
    cerr << endl;
    for (int i = 0; i < v.size(); ++i)
        cerr << v[i] << " ";
    cerr << endl;
}

vi f (const vi & c, int k, int t) {
    int n = c.size();
    vi queue, res(n);
    int it = 0;
    for (int i = 0; i < min(k, n); ++i) {
        queue.push_back(c[i]);
        res[i] = c[i] + t;
    }
    for (int i = min(k, n); i < n; ++i) {
        ll tin = max(c[i], queue[it] + t);
        queue.push_back(tin);
        ++it;
        res[i] = t + tin;
    }
//    out(queue);
    return res;
}
int main() {
    ll n;
    vi k(3), t(3);
    for (int i = 0; i < 3; ++i)
        cin >> k[i];
    for (int i = 0; i < 3; ++i)
        cin >> t[i];
    cin >> n;
    vi c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    vi cur = c;
    for (int i = 0; i < 3; ++i) {
        cur = f(cur, k[i], t[i]);
//        out (cur);
    }
    ll ma = 0;
    for (int i = 0; i < n; ++i) {
        ma = max(ma, cur[i] - c[i]);
    }
    cout << ma << endl;
    return 0;
}