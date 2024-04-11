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
#include <complex>
using namespace std;

typedef long long ll;

const int MN = 410;
const int MA = MN*MN;
int a[MN][MN];
int dp[MN][MN];
short last[MN][MA];
int main() {
    fill_n(last[0], MN*MA, -1);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &(a[i][j]));
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[j][j] = max(dp[j][j], last[j][a[i][j]]+1);
            res = max(res, (i-dp[j][j]+1)*1);
            last[j][a[i][j]] = i;
        }
        for (int r = 1; r < m; r++) {
            for (int l = r-1; l >= 0; l--) {
                dp[l][r] = max(dp[l][r], max(dp[l+1][r], dp[l][r-1]));
                dp[l][r] = max(dp[l][r], max(last[r][a[i][l]]+1, last[l][a[i][r]]+1));
                res = max(res, (i-dp[l][r]+1)*(r-l+1));
            }
        }
    }
    cout << res << endl;
    return 0;
}