#include <bits/stdc++.h>
using namespace std;

int main(){
    const int MOD = 998244353;

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for(int i = 0; i < n; i++)scanf("%d", &a[i]);

        sort(a.rbegin(), a.rend());

        if(a[0] == a[1]){
            long long res = 1;
            for(int i = 1; i <= n; i++)
                res = res * i % MOD;
            printf("%lld\n", res);

            continue;
        }

        if(a[0] - a[1] > 1){
            printf("0\n");
            continue;
        }

        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += (a[i] == a[1]);

        long long res = 1;
        for(int i = 2; i <= cnt; i++)
            res = res * i % MOD;
        res = res * cnt % MOD;

        for(int i = cnt + 2; i <= n; i++)
            res = res * i % MOD;
        
        printf("%lld\n", res);
    }
    return 0;
}