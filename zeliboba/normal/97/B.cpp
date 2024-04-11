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
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vii res;

void out(const vii & x, int b, int e) {
    if (b >= e || x[b].first == x[e - 1].first)
        return;
    int mid = x[(b + e) / 2].first;
    int i = b;
    for (; i < x.size() && x[i].first < mid; ++i)
        res.push_back(pii(mid, x[i].second));
    out(x, b, i);
    for (i = e - 1; i >= b && x[i].first > mid; --i)
        res.push_back(pii(mid, x[i].second));
    out(x, i + 1, e);
}

int main() {
    int n;
    cin >> n;
    vector<pii> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> x[i].second;
    }
    sort(x.begin(), x.end());
    res = x;
    out(x, 0, x.size());
/*    for (int i = 0; i < res.size(); ++i)
        swap(res[i].first, res[i].second);
    res = out(res);
    for (int i = 0; i < res.size(); ++i)
        swap(res[i].first, res[i].second);
    res.push_back(pii(-1e9 - 10, 0));
    res = out(res);*/
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << res[i].first << " " << res[i].second << endl;
    return 0;
}