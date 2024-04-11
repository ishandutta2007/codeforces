#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int tot;
ll inv[maxn], rt[maxn];
ll divisor[maxn];
int lson[maxn * 200], rson[maxn * 200];
int val[maxn * 200];
ll pre[maxn];

int update(int rt, int l, int r, int p, ll v){
    if(l == r){
        int rt1 = ++tot;
        val[rt1] = 1LL * val[rt] * v % mod;
        return rt1;
    }
    int mid = (l + r) / 2;
    int rt1 = ++tot;
    if(p <= mid){
        lson[rt1] = update(lson[rt], l, mid, p, v);
        rson[rt1] = rson[rt]; 
    }else{
        lson[rt1] = lson[rt];
        rson[rt1] = update(rson[rt], mid+1, r, p, v);
    }
    val[rt1] = 1LL * val[lson[rt1]] * val[rson[rt1]] % mod;
    return rt1;
}

ll query(int rt, int l, int r, int ql, int qr){
    if(ql <= l and r <= qr)
        return val[rt];
    int mid = (l + r) / 2;
    ll ans = 1;
    if(ql <= mid and lson[rt]){
        ans = ans * query(lson[rt], l, mid, ql, qr) % mod;
    }
    if(qr > mid and rson[rt]){
        ans = ans * query(rson[rt], mid + 1, r, ql, qr) % mod;
    }
    return ans;
}

int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    inv[0] = inv[1] = 1;
    for(int i = 2;i < maxn;i++){
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    for(int i = 2;i < maxn;i++){
        if(!divisor[i]){
            for(int j = i;j < maxn;j += i){
                divisor[j] = i;
            }
        }
    }
    val[0] = 1;
    for(int i = 1;i <= n;i++){
        ll x, c = 1;
        cin >> x;
        rt[i] = rt[i - 1];
        while(divisor[x]){
            ll v = divisor[x];
            c = 1;
            while(x % v == 0){
                c *= v;
                x /= v;
                if(pre[c]){
                    rt[i] = update(rt[i], 1, n, pre[c], inv[v]);
                }
                pre[c] = i;
            }
            rt[i] = update(rt[i], 1, n, i, c);
        }
    }
    int q;
    cin >> q;
    for(int i = 1, l, r, lst=0;i <= q;i++){
        cin >> l >> r;
        l = (l + lst) % n + 1, r = (r + lst) % n + 1;
        if(l > r) swap(l, r);
        cout << (lst = query(rt[r], 1, n, l, r)) << endl; 
    }
    return 0;
}