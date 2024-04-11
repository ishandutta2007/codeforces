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

vi fen(200001);

void add(int i, int val) {
    for (; i < fen.size(); i |= (i+1))
        fen[i] += val;
}

int sum(int i) {
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        res += fen[i];
    return res;
}

void out(const vi &v) {
    for (int i = 0; i < v.size(); ++i)
        cerr << v[i] << ' ';
    cerr << endl;
}

vi f(vi v) {
    fen.assign(fen.size(), 0);
    for (int i = 0; i < v.size(); ++i) {
        add(v[i], 1);
        v[i] = v[i] - sum(v[i] - 1);
    }
    reverse(v.begin(), v.end());
    return v;
}

vi f1(vi v) {
    fen.assign(fen.size(), 0);
    int n = v.size();
    for (int i = 0; i < v.size(); ++i) {
        int l = 0, r = n;
        while (r - l > 1) {
            int t = (l + r) / 2;
            if (sum(t-1) + v[i] >= t) {
                l = t;
            } else r = t;
        }
        v[i] = l;
        add(v[i], 1);
    }
    return v;
}

int main() {
    int n;
    scanf("%d", &n);
    vi a(n), b(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    a = f(a);
    b = f(b);
//    out(a); out(b);
    for (int i = 0; i < n; ++i) {
        a[i] += b[i];
        if (a[i] > i) {
            a[i] -= i+1;
            if (i + 1 < n)
                a[i+1]++;
        }
    }
    reverse(a.begin(), a.end());
//    out(a);
    a = f1(a);
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << ' ';
    return 0;
}