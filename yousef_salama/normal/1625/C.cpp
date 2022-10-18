#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

long long dp[MAXN][MAXN];

int main(){
    int n, l, k;
    scanf("%d %d %d", &n, &l, &k);

    vector <int> d(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &d[i]);

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = n; i >= 0; i--)
    for(int j = 0; j <= k; j++){
        if(i == n){
            dp[i][j] = 0;
        }else{
            dp[i][j] = 1LL << 30;
            for(int x = i + 1; x <= n; x++){
                if(x - i - 1 > j)break;

                dp[i][j] = min(dp[i][j], dp[x][j - (x - i - 1)] + 1LL * a[i] * ((x == n ? l : d[x]) - d[i]));
            }
        }
    }

    printf("%lld\n", dp[0][k]);

    return 0;
}