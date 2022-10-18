#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>

using namespace std;

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;
int main(){
//    freopen("a.in", "r", stdin);
    int n, m, a, b;
    cin >> n >> m;
    int g[n][m], dp[n + 1][m + 1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    cin >> a >> b;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = g[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(i + a - 1 < n && j + b - 1 < m)
                ans = min(ans, dp[i + a][j + b] - dp[i + a][j] - dp[i][j + b] + dp[i][j]);
            if(j + a - 1 < m && i + b - 1 < n)
                ans = min(ans, dp[i + b][j + a] - dp[i + b][j] - dp[i][j + a] + dp[i][j]);
        }
//    for(int i = 0; i <= n; i++){
//        for(int j = 0; j <= m; j++)
//            cout << dp[i][j] << ' ';
//        cout << endl;
//    }
    cout << ans << endl;
    return 0;
}