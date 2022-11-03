#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int n;
const int maxn = 1e6 + 5;
int k[maxn];
vector<int> G[maxn];

int cnt[maxn];

typedef long long LL;
LL p[maxn];

const LL mod = 998244353;

LL qpow(LL a, LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1) 
            ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

LL inv(LL a){
    return qpow(a, mod - 2);
}

int main(){
    cin >> n;
    LL m = inv(n);
    for(int i = 1;i <= n;i++){
        scanf("%d", &k[i]);
        for(int j = 0;j < k[i];j++){
            int num;
            scanf("%d", &num);
            G[i].push_back(num);
            cnt[num]++;
            p[num] = (p[num] + inv(k[i])) % mod;
        }
    }
    LL ans = 0;
    for(int i = 1;i <= 1e6;i++){
        LL num1 = cnt[i] * m % mod;
        LL num2 = p[i] * m % mod;
        ans = (ans + num1 * num2) % mod;
    }
    cout << ans << endl;
    return 0;
}