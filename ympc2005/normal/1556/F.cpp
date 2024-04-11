#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10, mod = 1e9 + 7;

int n, a[14], b[14][1<<14], f[1<<14], inv[N], ans;

void init_(int mx) {
    inv[1] = 1;
    
    for (int i = 2; i <= mx; i++)
        inv[i] = -1ll*inv[mod%i]*(mod/i)%mod;
}

int main() {
    init_(2e6);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < (1<<n); j++) {
            b[i][j] = 1;

            for (int k = 0; k < n; k++)
                if (j&(1<<k))
                    b[i][j] = 1ll*b[i][j]*inv[a[i] + a[k]]%mod*a[i]%mod;
        }
    
    for (int i = 1; i < (1<<n); i++) {
        f[i] = 1;

        for (int j = (i - 1)&i; j; j = (j - 1)&i) {
            int val = f[j];

            for (int k = 0; k < n; k++)
                if (j&(1<<k))
                    val = 1ll*val*b[k][i^j]%mod;
            
            f[i] = (f[i] - val)%mod;
        }

        int k = f[i], cnt = 0;

        for (int j = 0; j < n; j++) 
            if (i&(1<<j)) {
                cnt++;
                k = 1ll*k*b[j][((1<<n) - 1)^i]%mod;
            }
        
        ans = (ans + 1ll*cnt*k)%mod;
    }

    printf("%d\n", (ans%mod + mod)%mod);
}