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

int f0(vi & a) {
    int t = 0;
    vi b = a;
    while (true) {
        for (int i = 1; i + 1 < b.size(); ++i) {
            b[i] = (a[i-1] + a[i] + a[i+1]) / 2;
        }
        if (b == a) break;
        a.swap(b);
        ++t;
    }
    return t;
}

int f(vi & a) {
    int t = 0;
    int prev = 0;
    while (prev + 1 < a.size() && a[prev+1] == a[prev]) ++prev;
    for (int i = 1; i < a.size(); ++i) {
        if (i + 1 == a.size() || a[i] == a[i+1]) {
            if (a[prev] == a[i]) {
                t = max(t, (i - prev) / 2);
                for (int j = prev + 1; j < i; ++j) a[j] = a[i];
            } else {
                t = max(t, (i - prev) / 2);
                for (int j = prev + 1; j < i; ++j) {
                    if (j - prev < i - j) a[j] = a[prev];
                    else a[j] = a[i];
                }
            }
            while (i + 1 < a.size() && a[i] == a[i+1]) ++i;
            prev = i;
        }
    }
    return t;
}

void out(const vi & a) {
    for (int i = 0; i < a.size(); ++i) cerr << a[i] << ' ';
    cerr << endl;
}

int main() {
/*    int ma = 0;
    for (int n = 4; n <= 15; ++n) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            vi a(n);
            for (int i = 0; i < n; ++i) if (mask & (1 << i)) a[i] = 1;
            vi a0 = a;
            vi b = a;
            int t = f(a);
            int t1 = f0(b);
//            out(a0); out(a); out(b);
            assert(t == t1 && a == b);
            if (ma < t) {
                ma = t;
//                cerr << ma << endl;
//                out(a0); out(a);
            }
        }
    }*/
    int n;
    scanf("%d", &n);
    vi a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int t = f(a);
    printf("%d\n", t);
    for (int i = 0; i < a.size(); ++i) printf("%d ", a[i]);
    return 0;
}