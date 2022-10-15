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
const int mod = 1000000000;

int main() {
    vl f(100005, 1);
    for (int i = 2; i < f.size(); ++i)
        f[i] = (f[i-1]+f[i-2]) % mod;
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        if (x == 1) {
            a[l-1] = r;
        } else {
            --l; --r;
            ll sum = 0;
            for (int i = 0; i <= r-l; ++i)
                sum = (sum + f[i] * a[l+i]) % mod;
            printf("%d\n", (int)sum);
        }
    }
    return 0;
}