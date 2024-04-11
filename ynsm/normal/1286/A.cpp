#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, x, dp[200][200][2];
int main()
{
    cin >> n;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) 
            dp[i][j][0] = dp[i][j][1] = inf;
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 0 || (x != 0 && x % 2 == 0)){
            for(int a = 0; a <= i; a++){    
                int b = i - a;
                dp[a + 1][b][0] = min(dp[a + 1][b][0], dp[a][b][0]);
                dp[a + 1][b][0] = min(dp[a + 1][b][0], dp[a][b][1] + 1);
            }
        }
        if(x == 0 || (x != 0 && x % 2 == 1)){
            for(int a = 0; a <= i; a++){    
                int b = i - a;
                dp[a][b + 1][1] = min(dp[a][b + 1][1], dp[a][b][0] + 1);
                dp[a][b + 1][1] = min(dp[a][b + 1][1], dp[a][b][1]);
            }
        }
    }
    cout << min(dp[n / 2][n - n / 2][0], dp[n / 2][n - n / 2][1]);
}