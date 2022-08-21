#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <numeric>
#include <valarray>
#include <array>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int MN = 3030;
const ll MD = 1e9+7;
bool g[MN][MN];
ll dp1[MN][MN], dp2[MN][MN];
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = s[j] == '#';
        }
    }
    if (g[0][1] || g[1][0]) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < m; i++) {
        if (g[0][i]) break;
        dp1[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (g[i][0]) break;
        dp2[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (g[i][j]) continue;
            dp1[i][j] = (dp1[i][j-1]+dp1[i-1][j])%MD;
            dp2[i][j] = (dp2[i][j-1]+dp2[i-1][j])%MD;
        }
    }
    cout << ((dp1[n-2][m-1]*dp2[n-1][m-2]%MD-dp1[n-1][m-2]*dp2[n-2][m-1]%MD)%MD+MD)%MD << endl;
    return 0;
}