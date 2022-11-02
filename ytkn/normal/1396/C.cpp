#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

ll dp[1000005][2];

int n;
ll a[1000000];
ll r1, r2, r3, d;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> r1 >> r2 >> r3 >> d;
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0][0] = min({r1*a[0]+r3, r3*a[0]+r3});
    dp[0][1] = min({r1*a[0]+r1, r2, r3*a[0]+r1});

    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0]+min({
            min(r1*a[i], r3*a[i])+r3,
            r2+min({r1, r2, r3})+2*d,
            min(r1*a[i], r3*a[i])+2*min(r1, r2)+2*d
        });
        ll tmp = dp[i-1][1]+min({
                                r1*a[i]+2*r1,
                                r3*a[i]+r3,
                                r2+min({r1, r2, r3})
                            })+min({r1, r2, r3})+2*d; // i-1 boss

        dp[i][0] = min(tmp, dp[i][0]);

        dp[i][1] = dp[i-1][0]+min({r1*a[i]+r1, r3*a[i]+r1, r2});
        dp[i][0] += d; dp[i][1] += d;
        // debug_value(dp[i][0]);
        // debug_value(dp[i][1]);
    }
    
    ll ans = dp[n-2][1]+min({
                    r1*a[n-1]+r3,
                    r3*a[n-1]+r3,
                })+min({r1, r2, r3})+2*d;
    // debug_value(dp[n-2][1]);
    // debug_value(ans);
    ans = min(ans, dp[n-1][0]);
    cout << ans << endl;
}