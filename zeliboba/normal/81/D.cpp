#include <cstdio>
#include <cstdlib>
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
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    vi a(m);
    int cnt = 0, ma = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        cnt += a[i];
        ma = max(ma, a[i]);
    }
    if (cnt < n || 2 * (cnt - ma) < n || (n % 2) && m <= 2) {
        cout << -1 << endl;
        return 0;
    }
    set<pii> q;
    vi res;
    for (int i = 0; i < n; ++i) {
        int ma = 0, best = 0;
        if (i && res[0] != res.back() && a[res[0]] && i + 1 < n) {
            best = res[0];
        } else {
            for (int j = 0; j < m; ++j) if (res.empty() || j != res.back()) if (i + 1 < n || res[0] != j) {
                if (ma < a[j]) {
                    ma = a[j];
                    best = j;
                }
            }
        }
        res.push_back(best);
        --a[best];
    }
    for (int i = 0; i < res.size(); ++i)
        printf("%d ", res[i] + 1);
    printf("\n");
    return 0;
}