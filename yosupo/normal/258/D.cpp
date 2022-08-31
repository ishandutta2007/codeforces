#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

const int MAX_N = 1001;
int main(int argc, char *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    double dp[MAX_N][MAX_N] = {};
    int d[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &(d[i]));
    }
    for (int x = 0; x < n; x++) {
        for (int y = x+1; y < n; y++) {
            if (d[x] > d[y]) {
                dp[x][y] = 1.0f;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        if (a > b) {
            swap(a, b);
        }
        dp[a][b] = 0.5f;
        for (int j = 0; j < a; j++) {
            dp[j][a] = dp[j][b] = (dp[j][a] + dp[j][b]) / 2;
        }
        for (int j = a+1; j < b; j++) {
            double dpa = dp[a][j], dpb = dp[j][b];
            dp[a][j] = (dpa + (1 - dpb)) / 2;
            dp[j][b] = ((1 - dpa) + dpb) / 2;
        }
        for (int j = b+1; j < n; j++) {
            dp[a][j] = dp[b][j] = (dp[a][j] + dp[b][j]) / 2;
        }
    }
    double r = 0;
    for (int x = 0; x < n; x++) {
        for (int y = x+1; y < n; y++) {
            r += dp[x][y];
        }
    }
    printf("%.10f\n", r);
    return 0;
}