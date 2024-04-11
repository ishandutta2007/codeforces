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

char buf[10];

int main() {
    ll w,h,n;
    cin >> w >> h >> n;
    vi s(n), v(n);
    vi x(h + 1), y(w + 1);
    x[0] = y[0] = x.back() = y.back() = 1;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%s%d", buf, &t);
        if (buf[0] == 'H') {
            s[i] = 0;
            ++x[t];
        } else {
            s[i] = 1;
            ++y[t];
        }
        v[i] = t;
    }
    int xma = 0, yma = 0;
    vi px(h + 1), nx(h + 1);
    vi py(w + 1), ny(w + 1);
    int last = 0;
    for (int i = 1; i <= h; ++i) {
        if (x[i]) {
            px[i] = last;
            nx[last] = i;
            xma = max(xma, i - last);
            last = i;
        }
    }
    last = 0;
    for (int i = 1; i <= w; ++i) {
        if (y[i]) {
            py[i] = last;
            ny[last] = i;
            yma = max(yma, i - last);
            last = i;
        }
    }
    vl res;
    res.push_back(xma*(ll)yma);
    for (int i = (int)s.size() - 1; i > 0; --i) {
        if (s[i] == 0) {
            --x[v[i]];
            if (x[v[i]] == 0) {
                int a = px[v[i]];
                int b = nx[v[i]];
                nx[a] = b;
                px[b] = a;
                xma = max(xma, b - a);
            }
        } else {
            --y[v[i]];
            if (y[v[i]] == 0) {
                int a = py[v[i]];
                int b = ny[v[i]];
                ny[a] = b;
                py[b] = a;
                yma = max(yma, b - a);
            }
        }
        res.push_back(xma*(ll)yma);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}