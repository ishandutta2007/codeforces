#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

LL l, r;
const LL mod = 1e9 + 7;
LL count(LL n, int odd){
    return ((n % mod) * ((n + 1) % mod) % mod - odd * n % mod + mod) % mod;
}

LL cal(LL n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    int cnt = 0;
    LL now = 1;
    while(true){
        if(2 * now + 1 <= n){
            cnt++;
            now = 2 * now + 1;
        }else{
            break;
        }
    }
    LL cnt0 = 0, cnt1 = 0;
    int odd = 0;
    for(int i = 0;i <= cnt;i++){
        if(!odd){
            cnt0 += (1LL << i);
        }else{
            cnt1 += (1LL << i);
        }
        odd ^= 1;
    }
    if(!odd){
        cnt0 += n - now;
    }else{
        cnt1 += n - now;
    }
    return (count(cnt0, 1) + count(cnt1, 0)) % mod;
}

LL cal(LL l, LL r){
    return (cal(r) - cal(l - 1) + mod) % mod;
}

int main(){
    while(cin >> l >> r){
        cout << cal(l, r) << endl;
    }
    return 0;
}