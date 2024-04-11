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

void f(vi x, int k, int p, int m, vl & res) {
    multiset<ll> q;
    for (int i = 0; i < x.size(); ++i)
        q.insert(-x[i]);
    for (int i = 1; i <= k; ++i) {
        ll t = *(q.begin());
        res[i] = res[i-1] - t;
        q.erase(q.begin());
        q.insert(t + p*m);
    }
/*    int N = 1000000;
    vi v(2*N + 1);
    for (int i = 0; i < x.size(); ++i) {
        v[N+x[i]]++;
    }
    int it = v.size() - 1;
    for (int i = 1; i <= k; ++i) {
        while (v[it] == 0) --it;
        v[it]--;
        v[it-p*m]++;
        res[i] = res[i-1] + it-N;
    }*/
}

int main() {
    int n,m,k,p;
    cin >> n >> m >> k >> p;
    vvi a(n, vi(m));
    vi x(n), y(m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
        x[i] += a[i][j];
        y[j] += a[i][j];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vl resx(k + 1), resy(k + 1);
    f(x, k, p, m, resx);
    f(y, k, p, n, resy);
    ll ma = resx[0] + resy[k];
    for (int i = 0; i <= k; ++i)
        ma = max(ma, resx[i] + resy[k-i] - i*(ll)(k-i)*p);
    cout << ma << endl;
    return 0;
}