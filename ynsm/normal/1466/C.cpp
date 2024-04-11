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
 
char s[N];
int n, dp[N][2][2];
void f(int &a, int b){
    if(a > b)
        a = b;
}
void solve(){
    scanf("%s", &s);
    n = strlen(s);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 2; j++)
            for(int q = 0; q < 2; q++)
                dp[i][j][q] = inf;
    dp[0][1][1] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int q = 0; q < 2; q++){
                if(dp[i][j][q] == inf)
                    continue;
                f(dp[i + 1][q][1], dp[i][j][q] + 1);
                bool ok = true;
                if(!q)
                    ok &= (s[i] != s[i - 1]);
                if(!j)
                    ok &= (s[i] != s[i - 2]);
                if(ok)
                    f(dp[i + 1][q][0], dp[i][j][q]);
            }
        }
    }
    int ans = inf;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            f(ans, dp[n][i][j]);
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
}