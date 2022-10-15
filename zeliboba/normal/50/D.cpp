#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

long long p2(long long x) {
    return x * x;
}

void out(const vector<double> & p) {
    for (int i = 0; i < p.size(); ++i)
        printf("%lf ", p[i]);
    printf("\n");
}

int main () {
    int n, k, x0, y0, e;
    scanf("%d%d%d%d%d", &n, &k, &e, &x0, &y0);
    e = 1000 - e;
    vector<int> x, y;
    for (int i = 0; i < n; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        if (a == x0 && b == y0) {
            --k;
        } else {
            x.push_back(a);
            y.push_back(b);
        }
    }
    n = x.size();
    long double l = 0, r = 10000;
    if (e == 0 || k <= 0) {
        printf("0\n");
        return 0;
    }
    vector<long long> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = p2(x[i] - x0) + p2(y[i] - y0);
    }
    while (r - l > 1e-10) {
        long double x = (r + l) / 2.;
        long double x2 = x * x;
        int cnt = 0;
        vector<long double> p;
        for (int i = 0; i < n; ++i) {
            if (x2 > d[i]) {
                ++cnt;
            } else {
                p.push_back(exp(1. - d[i] / x / x));
            }
        }
        bool kill = false;
        if (k <= cnt) {
            kill = true;
        } else {
            int k1 = k - cnt;
            vector<vector<long double> > prob(p.size() + 1, vector<long double>(k1 + 1, 0.));
            prob[0][0] = 1.;
            for (int i = 0; i + 1 < prob.size(); ++i) {
                prob[i + 1][k1] = prob[i][k1];
                for (int j = 0; j < k1; ++j) {
                    prob[i + 1][j] += (1 - p[i]) * prob[i][j];
                    prob[i + 1][j + 1] += p[i] * prob[i][j];
                }
            }
//            out(p);
//            printf("k1=%d, x=%lf, prob=%lf\n", k1, x, prob[p.size()][k1]);
            if (prob[p.size()][k1] >= e / 1000.)
                kill = true;
        }
        if (kill)
            r = x;
        else
            l = x;
    }
    printf("%.6lf\n", (double)(l + r) / 2.);
    return 0;
}