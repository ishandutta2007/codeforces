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

int main() {
    int n,m;
    cin >> n >> m;
    vl a(n), b(m);
    ll sa = 0, sb = 0;
    for (int i = 0; i < a.size(); ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        sa += a[i];
    }
    for (int i = 0; i < b.size(); ++i) {
        int x;
        scanf("%d", &x);
        b[i] = x;
        sb += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a.back() > b.back()) {
        a.swap(b);
        swap(sa, sb);
    }
    ll ans = 0;
    ans += sa;
    for (int i = (int)b.size() - 2; i >= 0; --i) {
        ans += min(sa, b[i]);
    }
    cout << ans << endl;
    return 0;
}