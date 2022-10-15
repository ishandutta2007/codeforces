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

const int N = 1<<17;
int v[2*N];

void set0(int l, int r, int val) {
    l += N;
    r += N;
    while (l < r) {
        if (l % 2 == 1) {
            v[l] = val;
            ++l;
        }
        if (r % 2 == 1) {
            v[r-1] = val;
            --r;
        }
        l/=2;
        r/=2;
    }
}

int get (int pos) {
    pos += N;
    int ma = 0;
    while (pos) {
        ma = max(ma, v[pos]);
        pos /= 2;
    }
    return ma;
}

int main() {
    int n, m;
    cin >> n >> m;
    vi x(n), y(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &x[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &y[i]);
    vi a(m), b(m), k(m);
    memset(v, 0, sizeof(v));
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d%d", &t, &a[i]);
        --a[i];
        if (t == 1) {
            scanf("%d%d", &b[i], &k[i]);
            --b[i];
            set0(b[i], b[i] + k[i], i+1);
//            cerr << b[i] << ' ' << b[i]+k[i] << endl;
        } else {
            int last = get(a[i]);
//            cerr << "last=" << last << " pos=" << a[i] << endl;
            if (last == 0) {
                printf("%d\n", y[a[i]]);
            } else {
                int pos = a[last-1] + a[i] - b[last-1];
                printf("%d\n", x[pos]);
            }
        }
    }
    return 0;
}