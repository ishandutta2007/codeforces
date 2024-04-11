#include <iostream>
//#include <algorithm>

using namespace std;

constexpr int Q = 1000005;
int cnt[Q];
int dp[Q][40];
int n, m;

int f(int h, int r1, int r2)
{
    if(h == m) return 0;
    short k = 8 * (r1 > 4 ? r1 - 3 : r1) + r2;
    if(dp[h][k] != -1) return dp[h][k] + (r1 > 4);

//    int ans = 0;
//    ans = max(ans, r1 / 3 + f(h + 1, r2, cnt[h + 2]));
//    if(r1 >= 1 && r2 >= 1 && cnt[h + 2] >= 1) ans = max(ans, 1 + (r1 - 1) / 3 + f(h + 1, r2 - 1, cnt[h + 2] - 1));
//    if(r1 >= 2 && r2 >= 2 && cnt[h + 2] >= 2) ans = max(ans, 2 + (r1 - 2) / 3 + f(h + 1, r2 - 2, cnt[h + 2] - 2));
//    dp[h][k] = ans - (r1 > 4);
    int a;
    a = r1 / 3 + f(h + 1, r2, cnt[h + 2]); if(a > dp[h][k]) dp[h][k] = a;
    if(r1 >= 1 && r2 >= 1 && cnt[h + 2] >= 1){a = 1 + (r1 - 1) / 3 + f(h + 1, r2 - 1, cnt[h + 2] - 1); if(a > dp[h][k]) dp[h][k] = a;}
    if(r1 >= 2 && r2 >= 2 && cnt[h + 2] >= 2){a = 2 + (r1 - 2) / 3 + f(h + 1, r2 - 2, cnt[h + 2] - 2); if(a > dp[h][k]) dp[h][k] = a;}
    if(r1 > 4) --dp[h][k];

//    return ans;
    return dp[h][k] + (r1 > 4);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; ++i){int a; cin >> a; --a; cnt[a] += 1;}
    for(int i = 0; i <= m; ++i) for(int j = 0; j < 40; ++j) dp[i][j] = -1;

    int ans = 0;
    for(int i = 0; i < m; ++i)
    {
        if(cnt[i] >= 8)
        {
            ans += ((cnt[i] - 8) / 3 + 1);
            cnt[i] = ((cnt[i] - 8) % 3 + 5);
        }
    }
    ans += f(0, cnt[0], cnt[1]);

    cout << ans;
    return 0;
}