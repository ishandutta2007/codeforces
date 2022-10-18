#include <bits/stdc++.h>
using namespace std;

int main(){
    const int MOD = 998244353;
    
    int n, m;
    scanf("%d %d", &n, &m);

    vector <int> l(n), r(n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &l[i], &r[i]);
    
    vector <long long> cnt(m + 1);

    for(int c = m; c >= 1; c--){
        int cm = m / c;

        vector <long long> dp(cm + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= cm; j++)
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            
            vector <long long> nxt(cm + 1, 0);
            for(int j = 0; j <= cm; j++){
                int cl = (l[i] + c - 1) / c, cr = r[i] / c + 1;

                if(j >= cl)nxt[j] = dp[j - cl];
                if(j >= cr)nxt[j] = (nxt[j] - dp[j - cr] + MOD) % MOD;
            }

            swap(dp, nxt);
        }

        cnt[c] = accumulate(dp.begin(), dp.end(), 0LL);

        for(int i = c + c; i <= m; i += c)
            cnt[c] = (cnt[c] - cnt[i] + MOD) % MOD;
    }

    printf("%lld\n", cnt[1]);

    return 0;
}