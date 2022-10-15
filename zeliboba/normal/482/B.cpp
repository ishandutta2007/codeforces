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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n, m;
    cin >> n >> m;
    vi l(m), r(m), x(m);
    vii v[30];
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d",&l[i],&r[i],&x[i]);
        --l[i]; --r[i];
        for (int b = 0; b < 30; ++b) if (x[i] & (1 << b)) {
            v[b].push_back(pii(l[i], r[i]));
        }
    }
    vvi a(30, vi(n));
    vvi sa(30, vi(n + 1));
    for (int b = 0; b < 30; ++b) if (!v[b].empty()) {
        sort(v[b].begin(), v[b].end());
        int curr = v[b][0].first, curl = v[b][0].second;
        for (int i = 1; i < v[b].size(); ++i) {
            if (v[b][i].first <= curl) {
                curl = max(curl, v[b][i].second);
            } else {
                for (int j = curr; j <= curl; ++j) {
                    a[b][j] = 1;
                }
                curl = v[b][i].second;
                curr = v[b][i].first;
            }
        }
        for (int j = curr; j <= curl; ++j) {
            a[b][j] = 1;
        }
        for (int i = 0; i < n; ++i)
            sa[b][i+1] = sa[b][i] + a[b][i];
    }
    for (int i = 0; i < m; ++i) {
        for (int b = 0; b < 30; ++b) if (!(x[i] & (1 << b))) {
            if (sa[b][r[i]+1] - sa[b][l[i]] == r[i]-l[i]+1) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int b = 0; b < 30; ++b) if (a[b][i]) {
            cur += (1 << b);
        }
        printf("%d ", cur);
    }
    return 0;
}