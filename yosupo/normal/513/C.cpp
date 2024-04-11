#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <tuple>
#include <cstring>
#include <set>
#include <valarray>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MP = 10100;
double l[5], r[5];
double d[5];
double p[MP];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i]; r[i]++;
        d[i] = r[i]-l[i];
    }
    for (int x = 0; x < MP; x++) {
        for (int i = 0; i < n; i++) {//i > x
            if (r[i]-1 <= x) continue;
            for (int j = 0; j < n; j++) {//j == x
                if (i == j) continue;
                if (x < l[j] || r[j] <= x) continue;
                double u = 1.0/d[j];
                for (int k = 0; k < j; k++) {
                    if (k == i) {
                        u *= max(0.0,
                            (r[k]-max(l[k], (x+1.0)))/d[k]);
                    } else {
                        u *= max(0.0,
                            (min(r[k], x*1.0)-l[k])/d[k]);
                    }
                }
                for (int k = j+1; k < n; k++) {
                    if (k == i) {
                        u *= max(0.0,
                            (r[k]-max(l[k], (x+1.0)))/d[k]);
                    } else {
                        u *= max(0.0,
                            (min(r[k], x+1.0)-l[k])/d[k]);
                    }
                }
                p[x] += u;
//                printf("%d %d %d %f\n", x, i, j, u);
            }
        }
    }
    for (int x = 0; x < MP; x++) {
        for (int i = 0; i < n; i++) {//i == x
            for (int j = i+1; j < n; j++) {//j == x
                if (x < l[i] || r[i] <= x) continue;
                if (x < l[j] || r[j] <= x) continue;
                double u = 1.0/d[i]/d[j];
                for (int k = 0; k < j; k++) {
                    if (k == i) continue;
                    u *= max(0.0,
                        (min(r[k], x*1.0)-l[k])/d[k]);
                }
                for (int k = j+1; k < n; k++) {
                    u *= max(0.0,
                        (min(r[k], x+1.0)-l[k])/d[k]);
                }
                p[x] += u;
//                printf("%d %d %d %f\n", x, i, j, u);
            }
        }
    }
    double res = 0;
    for (int i = 1; i < MP; i++) {
        res += i*p[i];
//        printf("%d %f\n", i, p[i]);
    }
    printf("%.20f\n", res);
    return 0;
}