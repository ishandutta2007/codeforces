#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
typedef long long ll;

typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 2100;

int main() {
    int n, x;
    cin >> n >> x;
    vector<T> G1, G2;
    for (int i = 0; i < n; i++) {
        int t, h, m;
        cin >> t >> h >> m;
        G1.push_back(T(t, h, m));
        G2.push_back(T(1-t, h, m));
    }
    int u = 0;
    bool used[MN] = {};
    int x1 = x;
    int r1 = 0, r2 = 0;
    while (1) {
        int k = -1, mm = -1;
        for (int i = 0; i < n; i++) {
            int t, h, m;
            tie(t, h, m) = G1[i];
            if (!used[i] && t == u && h <= x1 && mm < m) {
                k = i;
                mm = m;
            }
        }
        if (k == -1) break;
        used[k] = true;
        x1 += mm;
        r1++;
        u = 1-u;
    }
    u = 0;
    fill_n(used, MN, false);
    int x2 = x;
    while (1) {
        int k = -1, mm = -1;
        for (int i = 0; i < n; i++) {
            int t, h, m;
            tie(t, h, m) = G2[i];
            if (!used[i] && t == u && h <= x2 && mm < m) {
                k = i;
                mm = m;
            }
        }
        if (k == -1) break;
        used[k] = true;
        x2 += mm;
        r2++;
        u = 1-u;
    }
    printf("%d\n", max(r1, r2));
    return 0;
}