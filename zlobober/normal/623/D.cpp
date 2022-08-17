#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 105;

double P[N];

const int IT = 2000000;

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("%.10lf\n", 1.0);
        return 0;
    }
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &P[i]);
        P[i] /= 100.0;
    }
    sort(P, P + n);
    //reverse(P, P + n);
    vector<double> mn(n, 1);
    double prev = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        mn[i] = 1 - P[i];
    }
    prev = 1;
    for (int i = 0; i < n; i++)
        prev *= P[i];
    ans += prev * n;
    double prod = prev;
    for (int j = n + 1; j < IT; j++) {
        int c = -1;
        double best = -1e100;
        double best_without = -1e100;
        for (int q = 0; q < n; q++) {
            double without = 1.0 - mn[q] * (1.0 - P[q]);
            /*for (int t = 0; t < n; t++) {
                if (t != q)
                    without *= 1.0 - mn[t];
            }*/
            without *= prod / (1.0 - mn[q]);
            if (best < without)
                best = without, c = q, best_without = without;
        }
        if (best > 1.0 - 1e-13)
            break;
        ans += (best - prev) * j;
        mn[c] *= (1 - P[c]);
        prev = best;
        prod = best_without;
    }
    printf("%.10lf\n", ans);
}