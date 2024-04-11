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
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vi h(n), r(n), R(n);
    vd d(n);
    double dmax = 0, hmax = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> r[i] >> R[i];
        d[i] = dmax;
        for (int j = 0; j < i; ++j) {
            if (r[i] >= r[j]) {
                if (r[i] >= R[j])
                    d[i] = max(d[i], d[j] + h[j]);
                else
                    d[i] = max(d[i], d[j] + h[j] * (double)(r[i] - r[j]) / (R[j] - r[j]));
            }
            if (R[i] <= R[j] && R[i] >= r[j])
                d[i] = max(d[i], d[j] + h[j] * (double)(R[i] - r[j]) / (R[j] - r[j]) - h[i]);
            if (R[i] >= R[j] && r[i] <= R[j]) 
                d[i] = max(d[i], d[j] - h[i] * (double)(R[j] - r[i]) / (R[i] - r[i]) + h[j]);
        }
        dmax = max(dmax, d[i]);
        hmax = max(hmax, d[i] + h[i]);
    }
    printf("%lf\n", hmax);
    return 0;
}