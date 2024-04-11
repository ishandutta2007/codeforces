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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int check (const vi & v, int t) {
    int cnt = 0;
    int it = lower_bound(v.begin(), v.end(), t) - v.begin();
    if (it + 1 < v.size())
        ++cnt;
    if (it)
        ++cnt;
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vi x(m), y(m);
    vector<vi> v(n), h(n), s(2 * n - 1), d(2 * n - 1);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        --x[i]; --y[i];
        v[x[i]].push_back(y[i]);
        h[y[i]].push_back(x[i]);
        s[x[i] + y[i]].push_back(x[i] + n - 1 - y[i]);
        d[x[i] + n - 1 - y[i]].push_back(x[i] + y[i]);
    }
    for (int i = 0; i < n; ++i) {
        sort(v[i].begin(), v[i].end());
        sort(h[i].begin(), h[i].end());
    }
    for (int i = 0; i < 2 * n - 1; ++i) {
        sort(s[i].begin(), s[i].end());
        sort(d[i].begin(), d[i].end());
    }
    vi cnt(m);
    vi t(9);
    for (int i = 0; i < m; ++i) {
        cnt[i] += check(v[x[i]], y[i]);
        cnt[i] += check(h[y[i]], x[i]);
        cnt[i] += check(s[x[i] + y[i]], x[i] + n - 1 - y[i]);
        cnt[i] += check(d[x[i] + n - 1 - y[i]], y[i] + x[i]);
//        cerr << s[x[i] + y[i]].size() << " " << cnt[i] << endl;
        t[cnt[i]]++;
    }
    for (int i = 0; i < t.size(); ++i)
        cout << t[i] << " ";
    return 0;
}