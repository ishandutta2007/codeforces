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

int main() {
    int n, w;
    cin >> n >> w;
    vii a(n), b(n);
    vi a0(n), b0(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &b[i].first);
        a0[i] = a[i].first;
        b0[i] = b[i].first;
        a[i].second = b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vi was(n);
    int it2 = 0;
    set<pii> q;
    set<pii> q2;
    for (int i = n-1; i >= 0; --i) {
        q.insert(pii(a0[i], i));
        q2.insert(pii(b0[i], i));
    }
    ll cur = 0;
    set<pii> diff;
    set<pii> rdiff;
    set<pii> qcur;
    for (int t = 1; t <= w; ++t) {
        while (q.size() && was[q.begin()->second]) q.erase(q.begin());
        while (q2.size() && was[q2.begin()->second]) q2.erase(q2.begin());
        ll n1 = 1e18;
        if (q.size()) n1 = cur + q.begin()->first;
        ll n2 = 1e18;
        if (q2.size() && qcur.size()) {
            n2 = cur + q2.begin()->first + qcur.begin()->first;
        }
        ll n3 = 1e18;
        if (diff.size()) n3 = cur + diff.begin()->first;
        ll n4 = 1e18;
        if (q2.size() && rdiff.size()) {
            n4 = cur + q2.begin()->first + rdiff.begin()->first;
        }
//        cerr << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << endl;
        ll mi = min(n1, min(n2, min(n3, n4)));
        if (mi == n1) {
            int ind = q.begin()->second;
            was[q.begin()->second] = 1;
            qcur.insert(pii(-q.begin()->first, q.begin()->second));
            diff.insert(pii(b0[ind] - a0[ind], ind));
            q.erase(q.begin());
        } else if (mi == n2) {
            int ind = qcur.begin()->second;
            int ind2 = q2.begin()->second;
            was[ind] = 0;
            was[ind2] = 2;
            rdiff.insert(pii(a0[ind2]-b0[ind2], ind2));
            q.insert(pii(a0[ind], ind));
            q2.insert(pii(b0[ind], ind));
            qcur.erase(qcur.begin());
            diff.erase(pii(b0[ind] - a0[ind], ind));
        } else if (mi == n3) {
            int ind = diff.begin()->second;
            diff.erase(diff.begin());
            qcur.erase(pii(-a0[ind], ind));
            q2.erase(pii(b0[ind], ind));
            was[ind] = 2;
            rdiff.insert(pii(a0[ind]-b0[ind], ind));
        } else {
            int ind = rdiff.begin()->second;
            int ind2 = q2.begin()->second;
            was[ind] = 1;
            was[ind2] = 2;
            q2.erase(q2.begin());
            rdiff.erase(rdiff.begin());
            rdiff.insert(pii(a0[ind2]-b0[ind2], ind2));
            diff.insert(pii(b0[ind]-a0[ind], ind));
            qcur.insert(pii(-a0[ind], ind));
        }
        cur = mi;
    }
    cout << cur << endl;
    for (int i = 0; i < n; ++i)
        cout << was[i];
    cout << endl;
    return 0;
}