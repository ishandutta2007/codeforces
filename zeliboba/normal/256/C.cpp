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

ll a[1000000];

ll p2 (ll x) {
    ll res = (ll)sqrt((double)x);
    while (res * res > x)
        --res;
    while ((res + 1) * (res + 1) <= x)
        ++res;
    return res;
}

ll prod (ll x) {
    return x * x * x * x;
}

ll p4 (ll x) {
    ll res = p2(p2(x));
    while (prod(res) < x)
        ++res;
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int gr[1000000];
    gr[0] = gr[1] = gr[2] = 0;
    int was[1000000];
/*    for (int i = 3; i < 882000; ++i) {
        ll l = p4(i), r = p2(i);
        for (int j = l; j <= r; ++j) if (gr[j] < 1000)
            was[gr[j]] = i;
        for (int j = 0; ; ++j) if (was[j] != i) {
            gr[i] = j;
            break;
        }
        if (gr[i] != gr[i - 1]) {
            cout << i << " " << gr[i] << endl;
        }
    }*/
    ll res = 0;
    memset(was, 0, sizeof(was));
    ll pa[] = {0, 4, 16, 82, 6724, 50626, 1000000};
    int v[] = {0, 1, 2, 0, 3, 1};
    for (int i = 0; i < n; ++i) if (a[i] > 3) {
        vi was(10);
        ll l = p4(a[i]), r = p2(a[i]);
        for (int j = 0; j < 6; ++j) {
            ll l1 = max(l, pa[j]), r1 = min(r, pa[j + 1] - 1);
            if (l1 <= r1)
                was[v[j]] = 1;
        }
        for (int j = 0; j < 10; ++j) if (!was[j]) {
            res ^= j;
//            if (a[i] < 777777)
//                assert(j == gr[a[i]]);
            break;
        }
/*        for (int j = l; j <= r; ++j) if (gr[j] < 1000000)
            was[gr[j]] = i + 1;
        for (int j = 0; ; ++j) if (was[j] != i + 1) {
            res ^= j;
            break;
        }*/
    }
    if (res) cout << "Furlo\n";
    else cout << "Rublo\n";
    return 0;
}