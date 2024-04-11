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

vvl a(3);

bool check(int i, int j) {
 return a[0][i] * a[1][j] == a[0][j]*a[1][i];
}

bool check(int i, int j, int l) {
//    cerr << i << j << l << endl;
    if (check(i,j)) return false;
//    cerr << i << j << l << endl;
    ll det = a[0][i] * a[1][j] * a[2][l] + a[1][i] * a[2][j] * a[0][l] + a[2][i] * a[0][j] * a[1][l] - 
            (a[0][i] * a[2][j] * a[1][l] + a[1][i] * a[0][j] * a[2][l] + a[2][i] * a[1][j] * a[0][l]);
    return det == 0;
}

void up (ll &x, ll &y) {
    ll d = __gcd(abs(x), abs(y));
    x /= d;
    y /= d;
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vi a0(n), b0(n), c0(n);
    a[0].resize(n);
    a[1].resize(n);
    a[2].resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a0[i], &b0[i], &c0[i]);
        a[0][i] = a0[i];
        a[1][i] = b0[i];
        a[2][i] = c0[i];
    }
    vii res;
    vi ord(n);
    for (int i = 0; i < ord.size(); ++i) ord[i] = i;
    vi was(n);
    while (k) {
        k = min((int)ord.size(), k);
        if (k == ord.size()) {
            for (int i = 0; i < k; ++i) {
                res.push_back(pii(ord[i] + 1, -1));
            }
            break;
        }
        random_shuffle(ord.begin(), ord.end());
        bool stop = 0;
        for (int i0 = 0; !stop && i0 < ord.size(); ++i0) {
            if (i0 > 20) {
                cout << "NO\n";
                return 0;
            }
            int i = ord[i0];
            vvl v0; 
            v0.reserve(ord.size() - 1);
            for (int j0 = 0; j0 < ord.size(); ++j0) if (j0 != i0) {
                int j = ord[j0];
                if (check(i, j)) continue;
                bool ok = 0;
                vl x(5);
                x[1] = x[3] = a[0][i]*a[1][j]-a[1][i]*a[0][j];
                x[0] = -a[0][i]*a[2][j]+a[2][i]*a[0][j];
                x[2] = a[1][i]*a[2][j]-a[2][i]*a[1][j];
                x[4] = j;
                up(x[0], x[1]);
                up(x[2], x[3]);
                v0.push_back(x);
/*                for (int t = 0; t < v.size(); ++t) if (check(i, j, v[t][0])) {
                    v[t].push_back(j);
                    ok = 1;
                    break;
                }
                if (!ok) {
                    v.push_back(vi(1, j));
                }*/
            }
            if (v0.empty()) continue;
            sort(v0.begin(), v0.end());
            vvi v(1, vi(1, v0[0][4]));
            for (int t = 1; t < v0.size(); ++t) {
                bool ok = 1;
                for (int it = 0; it < 4; ++it) if (v0[t][it] != v0[t-1][it]) {
                    ok = 0;
                    break;
                }
                if (ok) {
                    v.back().push_back(v0[t][4]);
                } else {
                    v.push_back(vi(1, v0[t][4]));
                }
            }
//            cerr << i << ' ' << v.size() << endl;
//            cerr << i0 << endl;
            for (int t = 0; t < v.size(); ++t) if ((v[t].size()+1) * k >= ord.size()) {
//                cerr << k << ' ' << t << ' ' << v[t].size() << endl;
                stop = 1;
                res.push_back(pii(i + 1, v[t][0] + 1));
                was[i] = 1;
                for (int it = 0; it < v[t].size(); ++it) was[v[t][it]] = 1;
                vi nord;
                for (int it = 0; it < ord.size(); ++it) if (!was[ord[it]])
                    nord.push_back(ord[it]);
                ord.swap(nord);
                break;
            }
        }
        --k;
//        cerr << k << ord.size() << endl;
        if (!stop) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n" << res.size() << endl;;
    for (int i = 0; i < res.size(); ++i) {
        if (res[i].first == res[i].second) res[i].second = -1;
        cout << res[i].first << ' ' << res[i].second << endl;
    }
    return 0;
}