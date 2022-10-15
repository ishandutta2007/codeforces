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

int main() {
    int n = 12;
/*    vi v(n);
    for (int i = 0; i < v.size(); ++i)
        v[i] = i;
    do {
        vi y(n, 0);
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            ++y[(i+v[i])%n];
            if (y[(i+v[i])%n] > 1) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < v.size(); ++i)
                cerr << v[i] << ' ';
            cerr << endl;
        }
    } while(next_permutation(v.begin() + 1, v.end()));
    cerr << "here\n"; */
    cin >> n;
    vi a(n), b(n), c(n);
    if (n % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (n & 1) {
        for (int i = 0; i < n; ++i) {
            a[i] = i;
            b[i] = i % n;
            c[i] = 2*i % n;
        }
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
        printf("\n");
        for (int i = 0; i < n; ++i)
            printf("%d ", b[i]);
        printf("\n");
        for (int i = 0; i < n; ++i)
            printf("%d ", c[i]);
        printf("\n");
        return 0;
    }
    return 0;
}