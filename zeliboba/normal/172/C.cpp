#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
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
    int n, m;
    cin >> n >> m;
    vi t(n), x(n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &t[i], &x[i]);
    vi w(n);
    int T = 0;
    for (int i = 0; i < n; i += m) {
        int last = min(i + m - 1, n - 1);
        vii curx(1, pii(0,0));
        for (int j = i; j <= last; ++j)
            curx.push_back(pii(x[j], j));
        sort(curx.begin(), curx.end());
        T = max(T, t[last]);
        for (int j = 1; j < curx.size(); ++j) {
            int k = 1;
            while (j + k < curx.size() && curx[j + k].first == curx[j].first)
                ++k;
            T += curx[j].first - curx[j - 1].first;
            for (int j1 = j; j1 < j + k; ++j1)
                w[curx[j1].second] = T;
            T += 1 + k / 2;
            j += k - 1;
        }
        T += curx.back().first;
    }
    for (int i = 0; i < w.size(); ++i)
        printf("%d ", w[i]);
    return 0;
}