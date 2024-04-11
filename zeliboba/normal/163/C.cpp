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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef pair<double, int> pdi;

double up (double x, double y) {
    if (x < 0)
        return x + y;
    return x;
}

int main() {
    ll n, l, v1, v2;
    cin >> n >> l >> v1 >> v2;
    vi a(n);
    vd res(2 * n + 1, 0.);
    vector<pdi> events;
    double len = (double)v2 / (v1 + v2) * l;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] * (v1 + v2) < v2 * l)
            ++cur;
        events.push_back(pdi(a[i], 0));
        events.push_back(pdi(up(a[i] - len, 2 * l), 1));
    }
    sort(events.begin(), events.end());
    double prev = 0.;
    for (int i = 0; i < events.size(); ++i) {
        if (cur >= 0) {
            res[cur] += (events[i].first - prev);
//            cerr << events[i].first << " " << prev << endl;
        }
        prev = events[i].first;
        if (events[i].second)
            ++cur;
        else --cur;
    }
    res[cur] += (2 * l - prev);
//    cerr << 2 * l << " " << prev << endl;
    for (int i = 0; i <= n; ++i)
        printf("%.12lf\n", res[i] / 2. / l);
    return 0;
}