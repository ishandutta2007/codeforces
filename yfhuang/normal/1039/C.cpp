#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 5e5 + 5;

typedef long long LL;
map<LL, int> cnt;

int n, m, k;
LL c[maxn];

const LL mod = 1e9 + 7;

map<LL, int> mp[maxn];

int Find(LL col, int x){
    int fa;
    if(mp[x].count(col)){
        fa = mp[x][col];
        if(fa == x)
            return x;
        mp[x][col] = Find(col, fa); 
        return mp[x][col];
    }else{
        mp[x][col] = x;
        return x;
    }
}

LL qpow(LL a, LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1){
            ret = ret * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &c[i]);
    }
    for(int i = 1;i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        LL x = c[u] ^ c[v];
        int fx = Find(x, u);
        int fy = Find(x, v);
        //cout << fx << " " << fy << endl;
        if(fx != fy){
           cnt[x]++; 
           mp[fx][x] = fy;
        }
    }
    LL tot = (1LL << k);
    LL ans = 0;
    for(auto it : cnt){
        tot--;
        LL tmp = n - it.second;
        tmp = qpow(2, tmp);
        ans = (ans + tmp) % mod;
    }
    LL tmp = qpow(2, n);
    ans = (ans + tot % mod * tmp) % mod;
    cout << ans << endl;
    return 0;
}