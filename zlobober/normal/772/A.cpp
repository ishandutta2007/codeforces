#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100500;


typedef long double ldouble;
ldouble A[N], B[N];

int main() {
    int n;
    double p;
    scanf("%d %lf", &n, &p);
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        A[i] = x, B[i] = y;
    }

    ldouble l = 0, r = 1e20;
    for (int it = 0; it < 100; it++) {
        ldouble m = (l + r) / 2;
        ldouble sum = 0;
        for (int i = 0; i < n; i++) {
            if (m < B[i] / A[i])
                continue;
            // B[i] / (A[i] - x) = m
            // x = A[i] - B[i] / m
            ldouble x = A[i] - B[i] / m;
            sum += x;
        }
        if (sum > p)
            r = m;
        else
            l = m;
    }
    ldouble ans = (l + r) / 2;
    if (ans > 1e19) {
        puts("-1");
    } else {
        printf("%.20lf\n", (double)ans);
    }
}