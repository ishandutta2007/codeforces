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

int N = 1;
int mi[1 << 19];

int getmi(int l, int r) {
    r = min(r, N-1);
    l += N; r += N;
    int res = 2e9;
    while (l <= r) {
        if (l & 1) {
            res = min(res, mi[l]);
            ++l;
        }
        if (!(r & 1)) {
            res = min(res, mi[r]);
            --r;
        }
        if (l > r) return res;
        l /= 2;
        r /= 2;
    }
    return res;
}

int stupid(const vi & a, int k) {
    int c = 0;
    for (int i = 1; i < a.size(); ++i) {
        if (a[(i-1) / k] > a[i]) ++c;
    }
    return c;
}

int main() {
    int n;
    for (int test = 1; test <= 1; ++test) {
        n = 100000;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            //a[i] = n-i;
            scanf("%d", &a[i]);
        }
        vi res(n);
        vi d(n + 1);
        for (int i = 1; i < n; ++i) {
            int i1 = i - 1;
            int m = min((int)sqrt(i1) + 1, i - 1);
            for (int k = 1; k <= m; ++k) {
                if (a[i] < a[i1/k]) ++res[k];
            }
            for (int j = 0; j <= m; ++j) {
                if (a[i] < a[j]) {
                    int l = max(m + 1, i1/(j+1) + 1);
                    int r = (j) ? i1/j + 1 : n;
                    if (l <= r) {
                        d[l]++;
                        if (j) {
                            d[r]--;
                        }
                    }
                }
            }
        }
        int s = 0;
        for (int i = 1; i < n; ++i) {
            s += d[i];
            res[i] += s;
            //assert(res[i] == stupid(a, i));
            printf("%d ", res[i]);
        }
    }
    return 0;
}