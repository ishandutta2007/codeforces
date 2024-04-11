#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m;
int x[80], s[80];
int l[80], r[80];
P p[80];
int dp[100][100005];

const int INF = 1e+8;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> s[i];
        p[i] = P(x[i]-s[i], x[i]+s[i]);
    }
    sort(p, p+n);
    for(int i = 0; i < n; i++){
        l[i] = p[i].first;
        r[i] = p[i].second;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            if(l[i] <= j+1){
                int r_ = min(m, r[i]);
                dp[i+1][r_] = min(dp[i+1][r_], dp[i][j]);
            }else{
                int dif = l[i]-(j+1);
                int r_ = min(m, r[i]+dif);
                dp[i+1][r_] = min(dp[i+1][r_], dp[i][j]+dif);
            }
        }
    }
    int ans = INF;
    for(int i = 0; i <= m; i++){
        ans = min(ans, dp[n][i]+(m-i));
    }
    cout << ans << endl;
}