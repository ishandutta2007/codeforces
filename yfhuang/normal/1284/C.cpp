#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

LL n, m;

const int maxn = 250000 + 5;

LL fac[maxn], inv[maxn];

void init(){
    fac[0] = 1;
    for(int i = 1;i < maxn;i++){
        fac[i] = fac[i - 1] * i % m;
    }
}

int main(){
    cin >> n >> m;
    init();
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        LL tmp = 1LL * (n + 1 - i) * (n + 1 - i) % m;
        tmp = tmp * fac[i] % m;
        tmp = tmp * fac[n - i] % m;
        ans = (ans + tmp);
        if(ans >= m)
            ans -= m;
    }
    cout << ans << endl;
    return 0;
}