#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "c"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int c[5] = {0, 0, 0, 0, 0};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int q;
        scanf("%d", &q);
        c[q]++;
    }
    int sum = c[1] + c[2] * 2 + c[3] * 3 + c[4] * 4;
    if (sum < 3 || sum == 5) {
        cout << -1 << '\n';
        return 0;
    }
    int res = 0;
    while (c[1] || c[2]) {
        if (c[1] && c[2]) {
            ++res;
            ++c[3];
            --c[1];
            --c[2];
            continue;
        }
        if (c[1]) {
            if (c[1] > 1) {
                if (c[1] == 2) {
                    res += 2;
                    break;
                }
                ++res;
                c[1] -= 2;
                ++c[2];
                continue;
            }
            if (c[3]) {
                ++res;
                --c[3];
                --c[1];
                ++c[4];
                continue;
            }
            res += 2;
            --c[1];
            ++c[3];
            assert(c[4] > 1);
            c[4] -= 2;
            continue;
        }
        if (c[2] > 1) {
            ++res;
            c[2] -= 2;
            ++c[1];
            ++c[3];
            continue;
        }
        if (c[4]) {
            ++res;
            --c[2];
            --c[4];
            c[3] += 2;
            continue;
        }
        res += 2;
        --c[2];
        c[4] += 2;
        assert(c[3] > 1);
        c[3] -= 2;
        continue;
    }
    cout << res << '\n';
}