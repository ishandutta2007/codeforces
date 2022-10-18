#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

int n, p[MAXN];
long long fact[MAXN], dp[MAXN];

int tree[MAXN];
void add(int i, int v){
    while(i < MAXN){
        tree[i] += v;
        i += i & (-i);
    }
}
int count(int i){
    int r = 0;
    while(i > 0){
        r += tree[i];
        i -= i & (-i);
    }
    return r;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    fact[0] = 1, dp[0] = 0;
    for(int i = 1; i <= n; i++){
        fact[i] = (i * fact[i - 1]) % MOD;
        dp[i] = (1LL * i * (i - 1) / 2 % MOD * fact[i - 1] + i * dp[i - 1]) % MOD;
    }

    for(int i = 1; i <= n; i++)add(i, 1);

    long long r = 0, res = 0;
    for(int i = 0; i < n; i++){
        int c = count(p[i] - 1);

        res = (res + c * fact[n - i - 1] % MOD * r +
        			1LL * c * (c - 1) / 2 % MOD * fact[n - i - 1] +
					c * dp[n - i - 1]) % MOD;

        r = (r + c) % MOD;
        add(p[i], -1);
    }
    
    res = (res + r) % MOD;
    printf("%I64d\n", res);

    return 0;
}