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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int f(const vvi & h, const vvi & m, int x) {
    vector<vii> v(2);
    for (int i = 0; i < 2; ++i) for (int j = 0; j < h[i].size(); ++j) {
        v[i].push_back(pii(h[i][j], m[i][j]));
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    vi it(2);
    set<pii> q[2];
    int res = 0;
    for (int t = 0; t < v[0].size(); ++t) {
        while (it[0] < v[0].size() && v[0][it[0]].first <= x) {
            q[0].insert(pii(-v[0][it[0]].second, it[0]));
            ++it[0];
        } 
        if (q[0].empty()) break;
        ++res;
        x -= q[0].begin()->first;
        //cerr << it[0] << ' ' << x << ' ' << v[0][0].first << ' ' << v[0][0].second << endl; 
        q[0].erase(q[0].begin());
        while (it[1] < v[1].size() && v[1][it[1]].first <= x) {
            q[1].insert(pii(-v[1][it[1]].second, it[1]));
            ++it[1];
        } 
        if (q[1].empty()) break;
        ++res;
        x -= q[1].begin()->first;
        //cerr << x << endl; 
        q[1].erase(q[1].begin());
    }
    return res;
}

int main() {
    int n, x;
    cin >> n >> x;
    vvi h(2), m(2);
    for (int i = 0; i < n; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        h[a].push_back(b);
        m[a].push_back(c);
    }
    int res = f(h, m, x);
    m[0].swap(m[1]);
    h[0].swap(h[1]);
    res = max(res, f(h, m, x));
    cout << res << endl;
    return 0;
}