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
    int n, l, t;
    cin >> n >> l >> t;
    vi a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
        a.push_back(a[i] + l);
    double res = n * (double)(n - 1) * (2*t / l);
    ll t1 = (2*t) % l;
    int it = 0;
    ll add = 0;
    for (int i = 0; i < n; ++i) {
        while (it < a.size() && a[it] - a[i] <= t1)
            ++it;
        add += min(n - 1, it - i - 1);
    }
    printf("%.10lf\n", (double)(res+add) / 4.);
    return 0;
}