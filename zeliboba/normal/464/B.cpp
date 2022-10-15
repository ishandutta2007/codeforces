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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vi sub(const vi &x, const vi &y) {
    vi z(x.size());
    for (int i = 0; i < x.size(); ++i)
        z[i] = x[i] - y[i];
    return z;
}

ll scal(const vi & x, const vi & y) {
    ll sum = 0;
    for (int i = 0; i < x.size(); ++i)
        sum += x[i]*(ll)y[i];
    return sum;
}

ll norm(const vi & x) {
    return scal(x, x);
}

int main() {
    vvi v(8, vi(3));
    for (int i = 0; i < v.size(); ++i) for (int j = 0; j < v[i].size(); ++j)
        cin >> v[i][j];
    int MAX = 6*6*6*6*6*6*6;
    bool ok = 0;
    for (int mask = 0; mask < MAX; ++mask) {
        vvi x = v;
        int m = mask;
        for (int i = 0; i < v.size(); ++i) {
            int t = m % 6;
            swap(x[i][0], x[i][t/2]);
            if (t % 2) {
                swap(x[i][1], x[i][2]);
            }
            m /= 6;
        }
        vector<pair<ll, int> > ts(7);
        for (int i = 1; i < 8; ++i) {
            ts[i-1] = make_pair(norm(sub(x[i], x[0])), i);
        }
        sort(ts.begin(), ts.end());
        if (ts[0].first == 0 || ts[0].first != ts[1].first || ts[1].first != ts[2].first ||
            2*ts[2].first != ts[3].first || ts[3].first != ts[4].first || ts[4].first != ts[5].first
            || 3*ts[2].first != ts[6].first) continue;
        bool ort = 1;
        int far = ts.back().second;
        for (int i = 0; i < 3; ++i) for (int j = i + 1; j < 3; ++j) {
            if (scal(sub(x[ts[i].second], x[0]), sub(x[ts[j].second], x[0])) != 0 ||
                scal(sub(x[ts[5-i].second], x[far]), sub(x[ts[5-j].second], x[far])) != 0) {
                ort = 0;
                break;
            }
        }
        if (!ort) continue;
        ok = 1;
        v = x;
        break;
    }
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j)
                cout << v[i][j] << ' ';
            cout << endl;
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}