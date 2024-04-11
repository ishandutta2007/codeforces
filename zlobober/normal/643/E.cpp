#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

const int N = 500500;
const int L = 35;

double D[L][N];
int P[N];

//inline double myexp(double v) {
//    if (v < -30)
//        return 0;
//    else
//        return exp(v);
//}

void go(int x) {
    assert(x != 1);
    double old_D = D[0][P[x]];
    D[0][P[x]] += log(0.5);
    x = P[x];
    for (int i = 0; i < L - 1; i++) {
        int y = P[x];
        if (y == 0)
            break;
        double new_old_D = D[i + 1][y];
        D[i + 1][y] -= log(0.5 * exp(old_D) + 0.5);
        D[i + 1][y] += log(0.5 * exp(D[i][x]) + 0.5);
        old_D = new_old_D;
        x = y;
    }
}

int main() {
    int q;
    scanf("%d", &q);
    P[1] = 0;
    int pt = 2;
    for (int i = 0; i < q; i++) {
        int t, x;
        scanf("%d %d", &t, &x);
        if (t == 1) {
            P[pt] = x;
            go(pt);
            pt++;
        } else {
            double ans = 0;
            for (int j = 0; j < L; j++) {
                ans += 1.0 - exp(D[j][x]);
            }
            printf("%.10lf\n", ans);
        }
    }

}