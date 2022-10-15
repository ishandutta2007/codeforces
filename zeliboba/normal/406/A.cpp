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
typedef vector<string> vs;

int main() {
    int n;
    scanf("%d", &n);
    vvi a(n, vi(n));
    vvi s(2, vi(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        scanf("%d", &a[i][j]);
        s[0][i] ^= a[i][j];
        s[1][j] ^= a[i][j];
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cur += a[i][j]*a[j][i];
    }
    cur %= 2;
    vvi r(2, vi(n));
    int R[2] = {0,0};
    int q;
    scanf("%d", &q);
    for (int qq = 0; qq < q; ++qq) {
        int t;
        scanf("%d", &t);
        if (t == 3) {
            printf("%d", cur%2);
        } else {
            --t;
            int m;
            scanf("%d", &m);
            --m;
            cur = (cur + 1) % 2;// + (a[m][m]+r[0][m]+r[1][m]) + (s[1-t][m]+R[t])) % 2;
            r[t][m]++;
            R[t]++;
        }
    }
    printf("\n");
    return 0;
}