#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long modpow(long long x, long long p){
    if(p == 0)return 1;
    if(p % 2 == 1)return x * modpow(x, p - 1) % MOD;

    long long r = modpow(x, p / 2);
    return r * r % MOD;
}
long long modinv(long long x){
    return modpow(x, MOD - 2);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector < vector <int> > d(n, vector <int> (m));
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &d[i][j]);

    long long res = 0;

    for(int j = 0; j < m; j++){
        vector <int> cnt(n + 2, 0);
        for(int i = 0; i < n; i++){
            cnt[d[i][j]]++;
        }

        long long prob = 1, total = 0;
        for(int i = 0; i < n; i++){
            total += cnt[n + 1 - i];

            if(total == 0){
                prob = 0;
                break;
            }

            prob = prob * total % MOD * modinv(n - i) % MOD;

            total--;
        }
        res = (res + 1 - prob + MOD) % MOD;
    }

    printf("%lld\n", res);

    return 0;
}