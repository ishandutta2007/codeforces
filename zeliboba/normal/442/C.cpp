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
    int n;
    cin >> n;
    vi v(n), l(n), r(n), was(n);
    vii q(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        q[i] = pii(v[i], i);
        l[i] = i-1;
        r[i] = i+1;
    }
    sort(q.begin(), q.end());
    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < q.size(); ++i) {
        int pos = q[i].second;
        if (pos == 0 || pos == n-1) continue;
        if (v[pos] <= v[l[pos]] && v[pos] <= v[r[pos]]) {
            ans += min(v[l[pos]], v[r[pos]]);
            l[r[pos]] = l[pos];
            r[l[pos]] = r[pos];
            was[pos] = 1;
            ++cnt;
        }
    }
    int pos = q.back().second;
    while (cnt < n - 2) {
        int pos1 = l[pos];
        if (pos != n-1 && (pos == 0 || v[r[pos]] > v[l[pos]])) pos1 = r[pos];
        if (pos != n-1 && pos != 0 && 
            (pos1 == 0 || pos1 == n-1 || 
            min(v[l[pos1]], v[r[pos1]]) < min(v[l[pos]], v[r[pos]]))) {
            swap(pos, pos1);
        }
        ans += min(v[l[pos1]], v[r[pos1]]);
        was[pos1] = 1;
        ++cnt;
        l[r[pos1]] = l[pos1];
        r[l[pos1]] = r[pos1];
    }
/*    set<pii> ord;
    for (int i = q.size() - 1; i >= 0; --i) {
        int pos = q[i].second;
        if (was[pos]) continue;
        if (pos == 0 || pos == n-1) continue;
        ord.insert(pii(-min(v[l[pos]], v[r[pos]]), pos));
    }
    while (ord.size()) {
        int pos = ord.begin()->second;
        ans -= ord.begin()->first;
        ord.erase(ord.begin());
        int pos1 = l[pos], pos2 = r[pos];
        ord.erase(pii(-min(v[l[pos1]], v[r[pos1]]), pos1));
        ord.erase(pii(-min(v[l[pos2]], v[r[pos2]]), pos2));
        l[r[pos]] = l[pos];
        r[l[pos]] = r[pos];
        was[pos] = 1;
    }*/
    cout << ans << endl;
    return 0;
}