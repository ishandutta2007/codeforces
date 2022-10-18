#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long modpow(long long a, long long p){
    if(p == 0)return 1;
    if(p % 2 == 1)return a * modpow(a, p - 1) % MOD;

    long long r = modpow(a, p / 2);
    return r * r % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector <string> g(n);
        for(int i = 0; i < n; i++)cin >> g[i];

        int cnt = 0;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += (g[i][j] == '#');
        
        if(cnt == n * m)printf("%lld\n", (modpow(2, cnt) - 1 + MOD) % MOD);
        else printf("%lld\n", modpow(2, cnt));
    }
    return 0;
}