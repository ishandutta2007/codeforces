#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const LL mod = 1e6 + 3;

LL ask(LL num){
    cout << "? " << num << endl;
    fflush(stdout);
    LL ret;
    cin >> ret;
    return ret;
}

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

const int maxn = mod;

LL inv[maxn];
LL inv1[maxn];
inline void add(LL &a, LL b){
    a += b;
    if(a >= mod){
        a -= mod;
    } 
}

inline void mul(LL &a, LL b){
    a *= b;
    if(a >= mod){
        a %= mod;
    }
}
void init(){
    for(LL i = 1;i < 20;i++){
        inv[i] = qpow(i, mod - 2);
    }
    for(int i = 1;i <= 11;i++){
        int cnt = 0;
        LL tmp = 1;
        for(int j = 1;j <= 11;j++){
            if(j == i)
                continue;
            if(j < i){
                mul(tmp, inv[i - j]);
            }else{
                cnt++;
                mul(tmp, inv[j - i]);
            }
        }
        if(cnt & 1)
            tmp = -tmp;
        add(tmp, mod);
        inv1[i] = tmp;
    }
}

LL f[maxn];
int k = 11;


LL cal(LL n){
    LL ret = 0;
    for(int i = 1;i <= 11;i++){
        LL tmp = f[i] * inv1[i] % mod;
        add(tmp, mod);
        int cnt = 0;
        for(int j = 1;j <= 11;j++){
            if(j == i)
                continue;
            if(j < n){
                mul(tmp, n - j);
            }else{
                cnt++;
                mul(tmp, j - n);
            }
        }
        if(cnt & 1)
            tmp = -tmp;
        add(tmp, mod);
        add(ret, tmp);
    }
    return ret;
}

int main(){
    init();
    for(LL i = 1;i <= 11;i++){
        f[i] = ask(i);
    }     
    LL ans = -1;
    for(int i = 0;i < mod;i++){
        if(cal(i) == 0){
            ans = i;
            break;
        }
    }
    cout << "! " << ans << endl;
    fflush(stdout);
    return 0;
}