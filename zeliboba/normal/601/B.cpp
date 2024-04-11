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

int main() {
    int n, Q;
    cin >> n >> Q;
    vi a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i + 1 < n; ++i) a[i] = abs(a[i+1] - a[i]);
    vi l(n-1), r(n-1);
    vi q;
    for (int i = 0; i < n-1; ++i) {
        while (q.size() && a[q.back()] <= a[i]) q.pop_back();
        if (q.size()) l[i] = q.back();
        else l[i] = -1;
        q.push_back(i);
    }
    q.clear();
    for (int i = n-2; i >= 0; --i) {
        while (q.size() && a[q.back()] < a[i]) q.pop_back();
        if (q.size()) r[i] = q.back();
        else r[i] = n-1;
        q.push_back(i);
    }
    for (int qq = 0; qq < Q; ++qq) {
        int x,b;
        scanf("%d%d",&x,&b);
        --x; --b;
        ll res = 0;
        for (int i = x; i < b; ++i) {
//            cerr << i << ' ' << a[i] << ' ' << l[i] << ' ' << r[i] << endl;
            res += a[i] * (ll)(i - max(x-1, l[i])) * (min(b, r[i]) - i);
        }
        cout << res << endl;
    }
    return 0;
}