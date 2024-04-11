#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;

const int N = 100500;

double A[N];
double B[N];

double X[N], Y[N];
bool can[N][2];

const double eps = 1e-6;

void path(int i, int t) {
    if (i == -1)
        return;
    if (t)
        swap(X[i], Y[i]);
    path(i - 1, t);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &A[i]);
        if (i != 0)
            A[i] += A[i - 1];
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &B[i]);
        if (i != 0)
            B[i] += B[i - 1];
    }
    for (int i = 0; i < n; i++) {
        double D = (A[i] + B[i]) * (A[i] + B[i]) - 4 * A[i];
        X[i] = (A[i] + B[i] - sqrt(max(0.0, D))) / 2.0;
        Y[i] = (A[i] + B[i] + sqrt(max(0.0, D))) / 2.0;
        assert(X[i] > -eps && Y[i] < 1 + eps);
    }
    can[0][0] = can[0][1] = true;
    for (int i = 1; i < n; i++) {
        for (int s = 0; s < 2; s++) {
            for (int t = 0; t < 2; t++) {
                double x1 = X[i - 1], y1 = Y[i - 1];
                double x2 = X[i], y2 = Y[i];
                if (s)
                    swap(x1, y1);
                if (t)
                    swap(x2, y2);
                if (x1 - eps < x2 && y1 - eps < y2)
                    can[i][t] |= can[i - 1][s];
            }
        }
    }
    assert(can[n - 1][0] || can[n - 1][1]);
    if (can[n - 1][0])
        path(n - 1, 0);
    else
        path(n - 1, 1);
    for (int i = n - 1; i >= 0; i--)
        X[i] -= X[i - 1], Y[i] -= Y[i - 1];
    for (int i = 0; i < n; i++) {
        printf("%.10lf ", X[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%.10lf ", Y[i]);
    }
    printf("\n");
}