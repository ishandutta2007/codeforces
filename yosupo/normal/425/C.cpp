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
const int MN = 101000;
const int MK = 400;

int a[MN], b[MN], c[MN], p[MN], r[MK];

int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", b+i);
    }

    fill_n(c, MN, -1);
    fill_n(r, MK, MN*10);
    int rp = -1;
    fill_n(p, MN, MN);
    for (int i = m-1; i >= 0; i--) {
        p[b[i]] = i;
    }
    for (int i = 1; i < MK; i++) {
        for (int j = 0; j < n; j++) {
            int c2 = c[j];
            c[j] = p[a[j]];
            if (c[j] < MN) {
                r[i] = min(r[i], j+c[j] + 2);
            }
            for (int k = rp; k > c2; k--) {
                p[b[k]] = min(p[b[k]], k);
            }
            rp = min(rp, c2);
        }
        rp = m-1;
        fill_n(p, MN, MN);
    }
    int res = 0;
    for (int i = 1; i < MK; i++) {
        if (i*e+r[i] <= s) res = i;
    }
    cout << res << endl;
    return 0;
}