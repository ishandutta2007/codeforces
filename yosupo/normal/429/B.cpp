#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
const int MN = 1010;
int n, m;
int d[2][MN][MN];
int dp1[2][MN][MN], dp2[2][MN][MN];
bool f1[2][MN][MN], f2[2][MN][MN], f3[MN][MN], f4[MN][MN];

ll solve1(int t, int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (f1[t][i][j]) return dp1[t][i][j]; 
    f1[t][i][j] = true;
    ll r = max(solve1(t, i-1, j), solve1(t, i, j-1)) + d[t][i][j];
    dp1[t][i][j] = r;
    return r;
}

ll solve2(int t, int i, int j) {
    if (i >= n || j >= m) return 0;
    if (f2[t][i][j]) return dp2[t][i][j];
    f2[t][i][j] = true;
    ll r = max(solve2(t, i+1, j), solve2(t, i, j+1)) + d[t][i][j];
    dp2[t][i][j] = r;
    return r;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &(d[0][i][j]));
            d[1][n-i-1][j] = d[0][i][j];
        }
    }
    ll r = 0;
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            r = max(r, solve1(0, i-1, j) + solve1(1, n-i-1, j-1) + solve2(0, i+1, j) + solve2(1, n-i-1, j+1));
            r = max(r, solve1(0, i, j-1) + solve1(1, n-i-2, j) + solve2(0, i, j+1) + solve2(1, n-i, j));
        }
    }
    cout << r << endl;
    return 0;
}