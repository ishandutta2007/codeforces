#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 4e5 + 5;
int n,q;
typedef long long LL;
typedef unsigned long long ull;

LL a[maxn];
const LL mod = 1e9 + 7;
ull bitmask[maxn << 2];
ull addmask[maxn << 2];
LL product[maxn << 2];
LL mul[maxn << 2];

#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

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


void pushdown(int o, int l, int r){
    bitmask[o*2] |= addmask[o];
    bitmask[o*2+1] |= addmask[o];
    addmask[o*2] |= addmask[o];
    addmask[o*2+1] |= addmask[o];
    addmask[o] = 0;
    int mid = (l + r) / 2;
    product[o*2] = product[o*2] * qpow(mul[o], mid - l + 1) % mod;
    product[o*2+1] = product[o*2+1] * qpow(mul[o], r - mid) % mod;
    mul[o*2] = mul[o*2] * mul[o] % mod;
    mul[o*2+1] = mul[o*2+1] * mul[o] % mod;
    mul[o] = 1;
}

void pushup(int o){
    product[o] = product[o*2] * product[o*2+1] % mod;    
    bitmask[o] = bitmask[o*2] | bitmask[o*2+1];
}

void build(int o, int l, int r){
    product[o] = 1;
    bitmask[o] = 0;
    addmask[o] = 0;
    mul[o] = 1;
    if(l == r){
        return;
    }
    int mid = (l + r) / 2;
    build(lson);
    build(rson);
    pushup(o);
}

void update(int o, int l, int r, int ql, int qr, LL d, ull mask){
    if(ql <= l && r <= qr){
        LL tmp = qpow(d, (r - l + 1));
        product[o] = product[o] * tmp % mod;
        mul[o] = mul[o] * d % mod;
        bitmask[o] |= mask;
        addmask[o] |= mask;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(o, l, r);
    if(ql <= mid){
        update(lson, ql, qr, d, mask);
    }
    if(qr > mid){
        update(rson, ql, qr, d, mask);
    }
    pushup(o);
}

pair<LL, ull> query(int o, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return make_pair(product[o], bitmask[o]);
    }
    int mid = (l + r) / 2;
    ull ansmask = 0;
    LL  ans = 1;
    pushdown(o, l, r);
    if(ql <= mid){
        pair<LL, ull> tmp = query(lson, ql, qr);
        ansmask |= tmp.second;
        ans = (ans * tmp.first) % mod;
    }if(qr > mid){
        pair<LL, ull> tmp = query(rson, ql, qr);
        ansmask |= tmp.second;
        ans = (ans * tmp.first) % mod;
    } 
    return make_pair(ans, ansmask);
}

vector<int> divisor[305];
bool vis[305];
int id[305];
LL prime[70];
int tot;
LL inv[305];
void init(){
    tot = 0;
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for(int i = 2;i < 305;i++){
        if(!vis[i]){
            id[i] = tot;
            prime[tot] = i;
            tot++;
            for(int j = 2 * i;j < 305;j += i){
                vis[j] = 1;
            }
            for(int j = i;j < 305;j += i){
                divisor[j].push_back(i);
            }
        }
    } 
    for(int i = 2;i < 305;i++){
        inv[i] = qpow(i, mod - 2);
    }
}

char op[10];

int main(){
    init();
    while(cin >> n >> q){
        build(1, 1, n);
        for(int i = 1;i <= n;i++){
            scanf("%lld", a + i);
            ull mask = 0;
            for(auto j: divisor[a[i]]){
                mask |= (1LL << id[j]);
            }
            update(1, 1, n, i, i, a[i], mask);
        }
        for(int i = 1;i <= q;i++){
            scanf("%s", op);
            if(op[0] == 'T'){
                int l, r;
                scanf("%d%d", &l, &r);
                pair<LL, ull> ans = query(1, 1, n, l, r); 
                LL ret = ans.first;
                ull mask = ans.second;
                for(int j = 0;j < 62;j++){
                    if((mask >> j) & 1){
                        ret = (ret * inv[prime[j]] % mod * (prime[j] - 1) % mod);
                    }
                }
                printf("%lld\n", ret);
            }else if(op[0] == 'M'){
                int l, r;
                LL val;
                scanf("%d%d%lld", &l, &r, &val);
                ull mask = 0;
                for(auto j: divisor[val]){
                    mask |= (1LL << id[j]);
                }
                update(1, 1, n, l, r, val, mask); 
            }
        }
    }
    return 0;
}