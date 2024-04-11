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
int n;

inline int dw(int x) {
    if (x < n) return x;
    return x - n;
}

ll s[1000005];
int a[1000005];
int v[1000005];

int main() {
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        assert(a[i] > 0);
    }
    for (int test = 1; test <= q; ++test) {
        ll b;
        cin >> b;
        s[0] = a[0];
        v[0] = 0;
        int sz = 1;
        for (int i = 1; i < n; ++i) {
            if (s[sz-1] + a[i] <= b) {
                s[sz-1] += a[i];
            } else {
                v[sz] = i;
                s[sz] = a[i];
                ++sz;
            }
        }
        int mi = sz;
        if (mi <= 2) {
            printf("%d\n", mi);
            continue;
        }
        int L = v[1];
        for (v[0] = 1; v[0] <= L; ++v[0]) {
            s[0] -= a[v[0]-1];
            s[sz-1] += a[v[0]-1];
            /*while (v[0] < L && s[sz-1] + a[v[0]] <= b) {
                s[sz-1] += a[v[0]];
                s[0] -= a[v[0]];
                ++v[0];
            }*/
            for (int i = 0; i+1 < sz; ++i) {
                bool moved = 0;
                while (s[i] + a[v[i+1]] <= b) {
                    s[i] += a[v[i+1]];
                    s[i+1] -= a[v[i+1]];
                    v[i+1] = dw(v[i+1]+1);
                    moved = 1;
                }
                if (!moved) break;
            }
            if (s[sz-1] > b) break;
            if (s[sz-1] <= 0) {
                --mi;
                break;
            }
        }
        printf("%d\n", mi);
    }
    return 0;
}