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

void out(const vl & x) {
    for (int i = 0; i < x.size(); ++i)
        cerr << x[i] << ' ';
    cerr << endl;
}

int main() {
    int n,m;
    cin >> n >> m;
    vl a(32);
    vl b(32);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < a.size(); ++j) {
            if (x & 1)
                ++a[j];
            x /= 2;
        }
    }
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        b[x]++;
    }
//    out(a);
//    out(b);
    int res = 0;
    for (int i = 0; i < b.size(); ++i) if (b[i] > 0) {
        for (int j = i; j < a.size(); ++j) {
            ll mul = 1LL << (j-i);
            int t = min(a[j]*mul, b[i]);
            res += t;
            b[i] -= t;
            ll x = (t+mul-1) / mul;
            ll rem = x * mul - t;
            a[j] -= x;
            for (int l = j-1; l >= i; --l) {
                mul /= 2;
                ll add = rem / mul;
                a[l] += add;
                rem -= add * mul;
            }
            if (b[i] == 0)
                break;
        }
//    out(a);
//    out(b);
    }
    cout << res << endl;
    return 0;
}