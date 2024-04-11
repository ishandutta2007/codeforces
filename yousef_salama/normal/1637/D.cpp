#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        vector <int> b(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);

        long long fixed_part = 0;
        for(int i = 0; i < n; i++){
            fixed_part += a[i] * a[i] * (n - 2);
            fixed_part += b[i] * b[i] * (n - 2);
        }

        int sum = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);

        vector <bool> dp(sum + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++){
            vector <bool> ndp(sum + 1, false);
            for(int j = 0; j <= sum; j++){
                if(j >= a[i])ndp[j] = ndp[j] || dp[j - a[i]];
                if(j >= b[i])ndp[j] = ndp[j] || dp[j - b[i]];
            }
            swap(ndp, dp);
        }

        long long res = 1LL << 60;
        for(int i = 0; i <= sum; i++)
            if(dp[i])res = min(res, fixed_part + i * i + (sum - i) * (sum - i));

        printf("%lld\n", res);
    }

    return 0;
}