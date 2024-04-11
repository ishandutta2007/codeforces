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

const int MAX_N = 3010;
const int MAX_M = 310;

double dp[MAX_N*2+10][MAX_N+1];
bool dpused[MAX_N*2+10][MAX_N+1] = {};
int dpmap[MAX_N+1][MAX_M];
int dpcount = 0;
int n, m;
int data[MAX_N][MAX_M];

double solve(int n, int c, int m) {
    if (n == 0) return 1.0;
    if (c == 0) return 0.0;
    if (dpmap[n][m] == -1) {
        dpmap[n][m] = dpcount;
        dpcount++;
    }
    int add = dpmap[n][m];
    if (dpused[add][c]) return dp[dpmap[n][m]][c];
    dpused[add][c] = true;
    dp[add][c] = (solve(n-1, c-1, m) * data[c-1][m]
                + solve(n, c-1, m) * (1000 - data[c-1][m]));
    dp[add][c] /= 1000;
    return dp[add][c];
}

int main(int argc, char *argv[]) {
    fill((int *)dpmap, (int *)dpmap + (MAX_N+1)*MAX_M, -1);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &(data[i][j]));
        }
    }
    int res[MAX_M] = {};
    fill(res, res + MAX_M, 1);
    double result = 0;
    for (int i = 0; i < n; i++) {
        int maxm = 0;
        double maxp = -1;
        for (int j = 0; j < m; j++) {
            double p = solve(res[j], n, j);
            if (p > maxp) {
                maxp = p;
                maxm = j;
            }
        }
        result += maxp;
        res[maxm]++;
    }
    printf("%.13lf\n", result);
    return 0;
}