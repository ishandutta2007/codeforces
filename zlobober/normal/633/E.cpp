#include <cstdio>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;

const int N = 1000500;

int ans[N];

const int LGN = 20;
int Smx[LGN][N];
int Smn[LGN][N];
int lg[N];

pair<int, int> get(int a, int b) {
    int l = lg[b - a + 1];
    int u = a, v = b - (1 << l) + 1;
    return make_pair(100 * max(Smx[l][u], Smx[l][v]), min(Smn[l][u], Smn[l][v]));
}

double lgF[N];
double C(int n, int k) {
    return lgF[n] - lgF[k] - lgF[n - k];
}

int main() {
    int k, n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Smx[0][i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &Smn[0][i]);
    }
    for (int l = 1; l < LGN; l++) {
        for (int i = 0; i + (1 << l) <= n; i++) {
            Smx[l][i] = max(Smx[l - 1][i], Smx[l - 1][i + (1 << (l - 1))]);
            Smn[l][i] = min(Smn[l - 1][i], Smn[l - 1][i + (1 << (l - 1))]);
        }
    }
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = 1 + lg[i / 2];
    }
    for (int l = 0; l < n; l++) {
        int a = l - 1, b = n;
        while (b - a > 1) {
            int q = (a + b) / 2;
            int mn, mx;
            tie(mx, mn) = get(l, q); 
            if (mx <= mn)
                a = q;
            else
                b = q;
        }
        if (l <= a) {
            int mx, mn;
            tie(mx, mn) = get(l, a);
            ans[l] = max(ans[l], min(mn, mx));
        }
        if (b < n) {
            int mx, mn;
            tie(mx, mn) = get(l, b);
            ans[l] = max(ans[l], min(mn, mx));
        }
    }
    lgF[0] = 0;
    for (int i = 1; i <= n; i++)
        lgF[i] = lgF[i - 1] + log((double)i);
    double res = 0;
    sort(ans, ans + n);
    double cur = (double)k / n;
    for (int i = 0; i < n - k + 1; i++) {
        if (cur < 1e-100)
            continue;
        res += cur * ans[i];
        cur = cur * (n - k - i) / (n - 1 - i);
    }
    printf("%.10lf\n", res);
}