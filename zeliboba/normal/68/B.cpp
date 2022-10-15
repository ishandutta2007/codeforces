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
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n, k;
    cin >> n >> k;
    vd a(n);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &a[i]);
    double l = 0, r = 1000;
    while (r - l > 1.e-8) {
        double x = (r + l) / 2.;
        double sum = 0.;
        for (int i = 0; i < n; ++i) {
            if (a[i] > x)
                sum += (a[i] - x) * (100 - k) / 100.;
            else
                sum += (a[i] - x);
        }
        if (sum > 0)
            l = x;
        else
            r = x;
    }
    printf("%.8lf\n", (r + l) / 2.);
    return 0;
}