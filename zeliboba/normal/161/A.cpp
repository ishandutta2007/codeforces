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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vi a(n), b(m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    vii res;
    int it = 0;
    for (int i = 0; i < n && it < m; ++i) {
        while (it < m && b[it] < a[i] - x)
            ++it;
        if (it >= m)
            break;
        if (b[it] <= a[i] + y) {
            res.push_back(pii(i, it));
            ++it;
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    return 0;
}