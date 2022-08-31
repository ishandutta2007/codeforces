#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;

int n, m;
int a[26] = {};

int res;
char ans[100100];

void solve1() {
    for (int l = 1; l <= m; l++) {
        if (m % l) continue;
        int c = m/l;
        int fc = -1;
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (a[i] % (2*c) == 0) continue;
            if (fc >= 0 || a[i] % c) {
                f = true;
                break;
            }
            fc = i;
        }
        if (f || fc == -1) continue;
        res = c;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (i == fc) {
                for (int j = 0; j < c; j++) {
                    for (int k = 0; k < c; k++) {
                        ans[k*l + l/2] = 'a' + i;
                    }
                }
            }
            for (int j = 0; j < a[i]/(2*c); j++) {
                for (int k = 0; k < c; k++) {
                    ans[k*l + idx] = 'a' + i;
                    ans[k*l + (l-1-idx)] = 'a' + i;
                }
                idx++;
            }
        }
        return;
    }
    res = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            ans[idx] = 'a' + i;
            idx++;
        }
    }
}

void solve2() {
    for (int l = 1; l <= m; l++) {
        if (m % l) continue;
        int c = m/l;
        if (c % 2) {
            bool f = false;
            for (int i = 0; i < n; i++) {
                if (a[i] % (2*c) == 0) continue;
                f = true;
                break;
            }
            if (f) continue;
            res = c;
            int idx = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < a[i]/(2*c); j++) {
                    for (int k = 0; k < c; k++) {
                        ans[k*l + idx] = 'a' + i;
                        ans[k*l + (l-1-idx)] = 'a' + i;
                    }
                    idx++;
                }
            }
            return;
        } else {
            bool f = false;
            for (int i = 0; i < n; i++) {
                if (a[i] % c == 0) continue;
                f = true;
                break;
            }
            if (f) continue;
            res = c;
            int idx = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < a[i]/c; j++) {
                    for (int k = 0; k < c; k++) {
                        if (k % 2 == 0) {
                            ans[k*l + idx] = 'a' + i;
                        } else {
                            ans[k*l + (l-1-idx)] = 'a' + i;
                        }
                    }
                    idx++;
                }
            }
            return;
        }
    }
    res = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            ans[idx] = 'a' + i;
            idx++;
        }
    }
}

int main() {
    scanf("%d", &n);
    m = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        m += a[i];
    }
    if (m % 2) {
        solve1();
    } else {
        solve2();
    }
    printf("%d\n", res);
//    ans[m] = '\0';
//    printf("%s\n", ans);
    for (int i = 0; i < m; i++) {
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}