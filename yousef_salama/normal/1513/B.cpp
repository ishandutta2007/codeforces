#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for(int i = 0; i < n; i++)scanf("%d", &a[i]);

        int z = 0;
        for(int j = 0; j < 30; j++){
            bool ok = true;
            for(int i = 0; i < n; i++){
                if(a[i] & (1 << j))continue;
                
                ok = false;
                break;
            }
            if(ok)z += 1 << j;
        }

        int cnt = count(a.begin(), a.end(), z);

        long long res = 1LL * cnt * (cnt - 1) % MOD;
        for(int i = n - 2; i >= 1; i--)res = res * i % MOD;

        printf("%lld\n", res);
    }
    return 0;
}