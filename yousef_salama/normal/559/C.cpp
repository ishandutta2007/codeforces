#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
const int MAXM = 200005;
const int MOD = 1000000007;

int h, w, n, dp[MAXN];
pair <int, int> b[MAXN];

long long fact[MAXM], invfact[MAXM];
long long modpower(long long x, int p){
    if(p == 0)return 1;
    if(p % 2 == 1)return (x * modpower(x, p - 1)) % MOD;
    
    long long r = modpower(x, p / 2);
    return (r * r) % MOD;
}
long long C(int X, int Y){
    long long r = 1;
    r = (r * fact[X]) % MOD;
    r = (r * invfact[Y]) % MOD;
    r = (r * invfact[X - Y]) % MOD;
    return r;
}

int main(){
    fact[0] = 1;
    for(int i = 1; i <= MAXM; i++)
        fact[i] = (i * fact[i - 1]) % MOD;
    for(int i = 0; i <= MAXM; i++)
        invfact[i] = modpower(fact[i], MOD - 2);
    
    scanf("%d %d %d", &h, &w, &n);
    
    for(int i = 0; i < n; i++)
        scanf("%d %d", &b[i].first, &b[i].second);
    b[n++] = {1, 1};
    sort(b, b + n);
    
    for(int i = n - 1; i >= 0; i--){
        int dx = h - b[i].first;
        int dy = w - b[i].second;
        
        dp[i] = C(dx + dy, dx);
        for(int j = i + 1; j < n; j++){
            if(b[i].first > b[j].first || b[i].second > b[j].second)continue;
            
            int tx = b[j].first - b[i].first;
            int ty = b[j].second - b[i].second;
            
            dp[i] = (dp[i] - ((C(tx + ty, tx) * dp[j]) % MOD) + MOD) % MOD;
        }
    }
    
    printf("%d\n", dp[0]);
    
    return 0;
}