#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, m, b, mi, pi;
pair <int, pair <int, int> > f[MAXN];

long long dp[1 << 20];

int main(){
    scanf("%d %d %d", &n, &m, &b);

    int tmask = 0;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &f[i].second.first, &f[i].first, &mi);

        f[i].second.second = 0;
        for(int j = 0; j < mi; j++){
            scanf("%d", &pi);
            f[i].second.second |= 1 << (pi - 1);
        }
        tmask |= f[i].second.second;
    }
    sort(f, f + n);

    if(tmask != (1 << m) - 1){
    	printf("-1\n");
    	return 0;
    }

    long long r = 1LL << 60;

    for(int mask = 0; mask < (1 << m); mask++){
        if(mask == 0)dp[mask] = 0;
        else dp[mask] = 1LL << 60;
    }

    for(int i = 0; i < n; i++){
        for(int mask = (1 << m) - 1; mask >= 0; mask--)
            dp[mask | f[i].second.second] = min(dp[mask | f[i].second.second],
                                                dp[mask] + f[i].second.first);
        r = min(r, dp[(1 << m) - 1] + 1LL * f[i].first * b);
    }
    printf("%I64d\n", r);

    return 0;
}